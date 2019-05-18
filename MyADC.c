/* ====================================================================================
File name:      MYADC.C                                     
Developer:	    DaoNgocDat / email: daongocdat@gmail.com
Target: 	    TMS320F28069
--------------------------------------------------------------------------------------*/
#include "main.h"
#define ADC_usDELAY  1000L
//---------------------------------------------------------------------------
// MyInitADC: This function initializes the ADC(s) to a known state.
//---------------------------------------------------------------------------
void MyInitADC(int* ChSel, int* Trigsel, int* ACQPS)
{
	extern void DSP28x_usDelay(Uint32 Count);
    EALLOW;
		SysCtrlRegs.PCLKCR0.bit.ADCENCLK = 1;
		(*Device_cal)();
		AdcRegs.ADCCTL1.bit.ADCBGPWD  = 1;      // Power ADC BG
		AdcRegs.ADCCTL1.bit.ADCREFPWD = 1;      // Power reference
		AdcRegs.ADCCTL1.bit.ADCPWDN   = 1;      // Power ADC
		AdcRegs.ADCCTL1.bit.ADCENABLE = 1;      // Enable ADC
		AdcRegs.ADCCTL1.bit.ADCREFSEL = 0;      // Select interal BG
    EDIS;
    DELAY_US(ADC_usDELAY);         // Delay before converting ADC channels
    EALLOW;
		AdcRegs.ADCCTL2.bit.CLKDIV2EN = 1;
    EDIS;
    DELAY_US(ADC_usDELAY);         // Delay before converting ADC channels
	
	EALLOW;

	/***** Configure ADC pins using AIO regs *****/
	// This specifies which of the possible AIO pins will be Analog input pins.
	// NOTE: AIO1,3,5,7-9,11,13,15 are analog inputs in all AIOMUX1 configurations.
	// Comment out other unwanted lines.
	
    GpioCtrlRegs.AIOMUX1.bit.AIO2 = 2;    // Configure AIO2 for A2 (analog input) operation
    GpioCtrlRegs.AIOMUX1.bit.AIO4 = 2;    // Configure AIO4 for A4 (analog input) operation
    GpioCtrlRegs.AIOMUX1.bit.AIO6 = 2;    // Configure AIO6 for A6 (analog input) operation
    GpioCtrlRegs.AIOMUX1.bit.AIO10 = 2;   // Configure AIO10 for B2 (analog input) operation
    GpioCtrlRegs.AIOMUX1.bit.AIO12 = 2;   // Configure AIO12 for B4 (analog input) operation
    GpioCtrlRegs.AIOMUX1.bit.AIO14 = 2;   // Configure AIO14 for B6 (analog input) operation

	/******* CHANNEL SELECT *******/
	AdcRegs.ADCSOC0CTL.bit.CHSEL  = ChSel[0];
	AdcRegs.ADCSOC1CTL.bit.CHSEL  = ChSel[1];
	AdcRegs.ADCSOC2CTL.bit.CHSEL  = ChSel[2];
	AdcRegs.ADCSOC3CTL.bit.CHSEL  = ChSel[3];
	AdcRegs.ADCSOC4CTL.bit.CHSEL  = ChSel[4];
	AdcRegs.ADCSOC5CTL.bit.CHSEL  = ChSel[5];
	AdcRegs.ADCSOC6CTL.bit.CHSEL  = ChSel[6];
	AdcRegs.ADCSOC7CTL.bit.CHSEL  = ChSel[7];
	AdcRegs.ADCSOC8CTL.bit.CHSEL  = ChSel[8];
	AdcRegs.ADCSOC9CTL.bit.CHSEL  = ChSel[9];
	AdcRegs.ADCSOC10CTL.bit.CHSEL = ChSel[10];
	AdcRegs.ADCSOC11CTL.bit.CHSEL = ChSel[11];
	AdcRegs.ADCSOC12CTL.bit.CHSEL = ChSel[12];
	AdcRegs.ADCSOC13CTL.bit.CHSEL = ChSel[13];
	AdcRegs.ADCSOC14CTL.bit.CHSEL = ChSel[14];
	AdcRegs.ADCSOC15CTL.bit.CHSEL = ChSel[15];
	
	/******* TRIGGER SOURCE SELECT *******/
	AdcRegs.ADCSOC0CTL.bit.TRIGSEL  = Trigsel[0];
	AdcRegs.ADCSOC1CTL.bit.TRIGSEL  = Trigsel[1];
	AdcRegs.ADCSOC2CTL.bit.TRIGSEL  = Trigsel[2];
	AdcRegs.ADCSOC3CTL.bit.TRIGSEL  = Trigsel[3];
	AdcRegs.ADCSOC4CTL.bit.TRIGSEL  = Trigsel[4];
	AdcRegs.ADCSOC5CTL.bit.TRIGSEL  = Trigsel[5];
	AdcRegs.ADCSOC6CTL.bit.TRIGSEL  = Trigsel[6];
	AdcRegs.ADCSOC7CTL.bit.TRIGSEL  = Trigsel[7];
	AdcRegs.ADCSOC8CTL.bit.TRIGSEL  = Trigsel[8];
	AdcRegs.ADCSOC9CTL.bit.TRIGSEL  = Trigsel[9];
	AdcRegs.ADCSOC10CTL.bit.TRIGSEL = Trigsel[10];
	AdcRegs.ADCSOC11CTL.bit.TRIGSEL = Trigsel[11];
	AdcRegs.ADCSOC12CTL.bit.TRIGSEL = Trigsel[12];
	AdcRegs.ADCSOC13CTL.bit.TRIGSEL = Trigsel[13];
	AdcRegs.ADCSOC14CTL.bit.TRIGSEL = Trigsel[14];
	AdcRegs.ADCSOC15CTL.bit.TRIGSEL = Trigsel[15];
	
	/******* ADC ACQUISITION SELECT *******/
	AdcRegs.ADCSOC0CTL.bit.ACQPS  = ACQPS[0];
   	AdcRegs.ADCSOC1CTL.bit.ACQPS  = ACQPS[1];													\
   	AdcRegs.ADCSOC2CTL.bit.ACQPS  = ACQPS[2];													\
   	AdcRegs.ADCSOC3CTL.bit.ACQPS  = ACQPS[3];													\
   	AdcRegs.ADCSOC4CTL.bit.ACQPS  = ACQPS[4];													\
   	AdcRegs.ADCSOC5CTL.bit.ACQPS  = ACQPS[5];													\
   	AdcRegs.ADCSOC6CTL.bit.ACQPS  = ACQPS[6];													\
   	AdcRegs.ADCSOC7CTL.bit.ACQPS  = ACQPS[7];													\
   	AdcRegs.ADCSOC8CTL.bit.ACQPS  = ACQPS[8];													\
   	AdcRegs.ADCSOC9CTL.bit.ACQPS  = ACQPS[9];													\
   	AdcRegs.ADCSOC10CTL.bit.ACQPS = ACQPS[10];													\
   	AdcRegs.ADCSOC11CTL.bit.ACQPS = ACQPS[11];													\
   	AdcRegs.ADCSOC12CTL.bit.ACQPS = ACQPS[12];													\
   	AdcRegs.ADCSOC13CTL.bit.ACQPS = ACQPS[13];													\
   	AdcRegs.ADCSOC14CTL.bit.ACQPS = ACQPS[14];													\
   	AdcRegs.ADCSOC15CTL.bit.ACQPS = ACQPS[15];
	
    EDIS;
	
	/* Set up Event Trigger with period enable for Time-base of EPWM1 */						\
    EPwm1Regs.ETSEL.bit.SOCAEN = 1;     /* Enable SOCA */										\
    EPwm1Regs.ETSEL.bit.SOCASEL = 2;    /* Enable period event for SOCA */						\
    EPwm1Regs.ETPS.bit.SOCAPRD = 1;     /* Generate SOCA on the 1st event */					\
	EPwm1Regs.ETCLR.bit.SOCA = 1;       /* Clear SOCA flag */
}

//===========================================================================
// End of file.
//===========================================================================
