#include "main.h"

//Global defines used in this example
#define SYSTEM_FREQUENCY 	90000	// kHz
#define PWM_FREQUENCY 		10		// kHz
#define ISR_FREQUENCY		10		// kHz
#define BASE_VOLTAGE    	330     // Base Peak Phase Voltage (volt)
#define BASE_CURRENT    	14      // Base Peak Phase Current (amp)
#define BASE_FREQ			50		// Hz
#define GRID_FREQ			50		// Hz
#define L_FILTER			0.00478 // Henry
#define PI	  3.141592654
#define DELAY 1000000L

// Functions that will be run from RAM
#pragma CODE_SECTION(MainISR,"ramfuncs");
#pragma CODE_SECTION(OffsetISR,"ramfuncs");

// Prototype statements for functions found within this file.
interrupt void MainISR(void);
interrupt void OffsetISR(void);
Uint8 CHECKCB (void);

// Global variables used in this example
Uint32  LoopCount = 0;
Uint32  EPwmCount = 0;
Uint32  IsrTicker = 0;
Uint32  bucount = 0;
Uint8	buflag = 0;
Uint8   start = 0, cbstatus = 0;
float32 T = 0.001/ISR_FREQUENCY;
float32 ZLpu = 2*PI*GRID_FREQ*L_FILTER/BASE_VOLTAGE;
_iq Vpu = _IQ(10.0/BASE_VOLTAGE);
_iq IDref = _IQ(0.8);
_iq IQref = _IQ(0.0);
_iq oIA = 0, oIB = 0, oIC = 0;
_iq oVA = 0, oVB = 0, oVC = 0;
_iq K1 = _IQ(0.998);
_iq K2 = _IQ(0.001999);
int16 DlogCh1 = 0;
int16 DlogCh2 = 0;
int16 DlogCh3 = 0;
int16 DlogCh4 = 0;

int ChSel[16]   = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int	TrigSel[16] = {5,5,5,5,5,5,5,0,0,0,0,0,0,0,0,0};
int ACQPS[16]   = {8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8};

RAMPCNTL rc1 = RMPCNTL_DEFAULTS;
PWMSV3L pwm3l = PWMSV3L_DEFAULTS;
DATA3P vref = DATA3P_DEFAULTS;
DATA3P curr = DATA3P_DEFAULTS;
DATA3P vols = DATA3P_DEFAULTS;
PLL3P_OBJ pll = PLL3P_DEFAULTS;
PIDATA pi_id = PIDATA_DEFAULTS;
PIDATA pi_iq = PIDATA_DEFAULTS;
DLOG_4CH dlog = DLOG_4CH_DEFAULTS;

extern Uint16 RamfuncsLoadStart;
extern Uint16 RamfuncsLoadEnd;
extern Uint16 RamfuncsRunStart;
extern Uint16 RamfuncsLoadSize;

void main(void)
{
   InitSysCtrl();	
   MyInitGpio();	
   MySciaGpio();	
   DisableDriver();	
   DINT;			
   InitPieCtrl();	
   IER = 0x0000;	
   IFR = 0x0000;	
   InitPieVectTable();	

   EALLOW;
   PieVectTable.EPWM1_INT = &OffsetISR;
   EDIS;

   pwm3l.Period = SYSTEM_FREQUENCY/PWM_FREQUENCY/2;
   pwm3l.HalfPrd = pwm3l.Period/2;
   MyInitEPwmSIN3L(&pwm3l);

   RS485_INIT();

   memcpy(&RamfuncsRunStart, &RamfuncsLoadStart, (Uint32)&RamfuncsLoadSize);
   InitFlash();		

// Initialize DATALOG module
   dlog.iptr1 = &DlogCh1;
   dlog.iptr2 = &DlogCh2;
   dlog.iptr3 = &DlogCh3;
   dlog.iptr4 = &DlogCh4;
   dlog.trig_value = 1;
   dlog.size = 200;
   dlog.prescalar = 10;
   dlog.init(&dlog);

// Initialize ADC for TNPC system
   ChSel[0]=1;		
   ChSel[1]=9;		
   ChSel[2]=8;		
   ChSel[3]=0;		
   ChSel[4]=4;		
   ChSel[5]=2;		
   ChSel[6]=1;		
   MyInitADC(ChSel,TrigSel,ACQPS);
// Initialize parameter for current & voltage sensors
   curr.Ka = _IQ(14.0/BASE_CURRENT);
   curr.Kb = _IQ(14.0/BASE_CURRENT);
   curr.Kc = _IQ(14.0/BASE_CURRENT);
   vols.Ka = _IQmpy(_IQ(45.0),Vpu);
   vols.Kb = _IQmpy(_IQ(45.0),Vpu);
   vols.Kc = _IQmpy(_IQ(45.0),Vpu);

   PLL3P_INIT(GRID_FREQ,_IQ21(T),&pll);

   pi_id.Kp=_IQ(0.65);
   pi_id.Ki=_IQ(T/0.02);
   pi_id.Umax =_IQ(1.0);
   pi_id.Umin =_IQ(-1.0);

   pi_iq.Kp=_IQ(0.85);
   pi_iq.Ki=_IQ(T/0.007);
   pi_iq.Umax =_IQ(1.0);
   pi_iq.Umin =_IQ(-1.0);

   LoopCount = 0;
   EPwmCount = 0;
   rc1.RampLowLimit = 0;
   rc1.TargetValue = IDref;

   DELAY_US(DELAY);
   DELAY_US(DELAY);
   DELAY_US(DELAY);
   DELAY_US(DELAY);
   DELAY_US(DELAY);
   EnableDriver();

   IER |= M_INT3; 
   PieCtrlRegs.PIEIER3.bit.INTx1 = 1;
   EINT; 
   ERTM; 

   for(;;)
   {
       if (LoopCount >= 300)
       {
    	   if (GpioDataRegs.GPADAT.bit.GPIO25 == 0) {buflag = 1; bucount++;}
    	   else {buflag = 0;}
    	   if (buflag == 0)
    	   {
    		   if ((bucount >1)&(bucount < 10))
    		   {
    			   if (start == 0) start = 1;
    			   else if(start == 1) start = 2;
    			   else if(start == 2) start = 0;
    		   }
    		   else if (bucount >15) {IDref += _IQ(0.05);}	
    		   bucount = 0;
    	   }
    	   LoopCount = 0;
       }
   }
}

interrupt void MainISR(void)
{
   EALLOW;
   FlashRegs.FPWR.bit.PWR = FLASH_STANDBY;
   EDIS;

   curr.As = _IQmpy2(_IQ12toIQ(AdcResult.ADCRESULT1)-oIA);  curr.As = _IQmpy(curr.Ka,curr.As);
   curr.Bs = _IQmpy2(_IQ12toIQ(AdcResult.ADCRESULT2)-oIB);  curr.Bs = _IQmpy(curr.Kb,curr.Bs);
   curr.Cs = _IQmpy2(_IQ12toIQ(AdcResult.ADCRESULT3)-oIC);  curr.Cs = _IQmpy(curr.Ka,curr.Cs);

   vols.As = _IQmpy2(_IQ12toIQ(AdcResult.ADCRESULT4)-oVA);	vols.As = _IQmpy(vols.Ka,vols.As);
   vols.Bs = _IQmpy2(_IQ12toIQ(AdcResult.ADCRESULT5)-oVB);	vols.Bs = _IQmpy(vols.Kb,vols.Bs);
   vols.Cs = _IQmpy2(_IQ12toIQ(AdcResult.ADCRESULT6)-oVC);	vols.Cs = _IQmpy(vols.Kc,vols.Cs);
//--------------------------------------------------------------
   vols.Sin = _IQsinPU(pll.theta[1]<<3);
   vols.Cos = _IQcosPU(pll.theta[1]<<3);
   ABC_DQ(&vols);
//--------------------------------------------------------------
   curr.Sin = vols.Sin;
   curr.Cos = vols.Cos;
   ABC_DQ(&curr);
//--------------------------------------------------------------
   pll.vq[0] = (int32)(_IQtoIQ21(vols.Qs));
   PLL3P(&pll);
//--------------------------------------------------------------
   cbstatus = CHECKCB();
   if (cbstatus == 0) {GpioDataRegs.GPBSET.bit.GPIO34 = 1;}
   else {GpioDataRegs.GPBCLEAR.bit.GPIO34 = 1;}
//--------------------------------------------------------------
   if ((cbstatus == 1)&(start != 0))
   {
	   if (start == 1) {rc1.TargetValue = IDref;}
	   else if (start == 2) {
		   rc1.TargetValue = 0;
		   if (rc1.SetpointValue < _IQ(0.001)) {start = 0;} }

	   RAMP_CNTL(&rc1);
	   pi_id.Ref = rc1.SetpointValue;
	   pi_id.Fbk = curr.Ds;
	   PI_CONTROLER(&pi_id);
	   pi_iq.Ref = IQref;
	   pi_iq.Fbk = curr.Qs;
	   PI_CONTROLER(&pi_iq);
	   vref.Ds = pi_id.Out - _IQmpy(_IQ(ZLpu),curr.Qs) + vols.Ds;
	   vref.Ds = (vref.Ds>_IQ(1.13))?_IQ(1.13):vref.Ds;
	   vref.Qs = pi_iq.Out + _IQmpy(_IQ(ZLpu),curr.Ds) + vols.Qs;
	   vref.Qs = (vref.Qs>_IQ(0.4))?_IQ(0.4):vref.Qs;
	   vref.Qs = (vref.Qs<_IQ(-0.4))?_IQ(-0.4):vref.Qs;
	   vref.Cos = vols.Cos;
	   vref.Sin = vols.Sin;
	   DQ_ABC(&vref);
	   SIN3P_SFO(&vref);
	   pwm3l.Ma = vref.As;
	   pwm3l.Mb = vref.Bs;
	   pwm3l.Mc = vref.Cs;
	   DUTYSINTNPC(&pwm3l);
	   PWM3L_UPDATE(&pwm3l);
   }
   else if ((cbstatus == 0)|(start == 0))
   {
	   start = 0;
	   rc1.SetpointValue = 0;		pi_id.Ref = 0;
	   pi_id.Out = 0; pi_id.ui = 0; pi_id.i1 = 0;
	   pi_iq.Out = 0; pi_iq.ui = 0; pi_iq.i1 = 0;
	   vref.Ds = 0;   vref.Qs = 0;
	   DUTYOFF(&pwm3l);
	   PWM3L_UPDATE(&pwm3l);
   }

   LoopCount ++;
   EPwmCount ++;
   if (EPwmCount == 5000) {EPwmCount = 0; GpioDataRegs.GPBTOGGLE.bit.GPIO39 = 1;}
   EPwm1Regs.ETCLR.bit.INT = 1;
   PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;
}

interrupt void OffsetISR(void)
{
   IsrTicker++;
   if (IsrTicker>=10000)
   {
	   oIA= _IQmpy(K1,oIA)+_IQmpy(K2,_IQ12toIQ(AdcResult.ADCRESULT1));
	   oIB= _IQmpy(K1,oIB)+_IQmpy(K2,_IQ12toIQ(AdcResult.ADCRESULT2));
	   oIC= _IQmpy(K1,oIC)+_IQmpy(K2,_IQ12toIQ(AdcResult.ADCRESULT3));

	   oVA= _IQmpy(K1,oVA)+_IQmpy(K2,_IQ12toIQ(AdcResult.ADCRESULT4));
	   oVB= _IQmpy(K1,oVB)+_IQmpy(K2,_IQ12toIQ(AdcResult.ADCRESULT5));
	   oVC= _IQmpy(K1,oVC)+_IQmpy(K2,_IQ12toIQ(AdcResult.ADCRESULT6));
   }
   if (IsrTicker > 50000)
   {
	   EALLOW;
	   PieVectTable.EPWM1_INT = &MainISR;
	   EDIS;
   }
// Clear INT flag for this timer
   EPwm1Regs.ETCLR.bit.INT = 1;
// Acknowledge this interrupt to receive more interrupts from group 3
   PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;
}

Uint8 CHECKCB (void)
{
	static Uint16 ticker1 = 0, ticker2 = 0, ticker3 = 0, ticker4 = 0;
	static Uint16 tim1 = 100, tim2 = 100, tim3 = 50, tim4 = 50;
	static Uint8 status = 0;

	if ((curr.Ds < _IQ(0.005))&(ticker2 == 0))
		{ticker1 ++; if (ticker1 == tim1) {ticker1 = 1; status = 0;} }
	else ticker1 = 0;

	if (curr.Qs < _IQ(-0.01))
		{ticker2 ++; if (ticker2 == tim2) {ticker2 = 1; status = 1;} }
	else ticker2 = 0;

	if (curr.Ds < (pi_id.Ref - _IQ(0.15)))
		{ticker3 ++; if (ticker3 == tim3) {ticker3 = 1; status = 0;} }
	else ticker3 = 0;

	if (curr.Ds > (pi_id.Ref + _IQ(0.15)))
		{ticker4 ++; if (ticker4 == tim4) {ticker4 = 1; status = 0;} }
	else ticker4 = 0;

	return status;
}
//===========================================================================
// No more.
//===========================================================================
