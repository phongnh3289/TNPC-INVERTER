/* ====================================================================================
File name:      MYEPWM.C                                     
Developer:	    DaoNgocDat / email: daongocdat@gmail.com
Target: 	    TMS320F28069
--------------------------------------------------------------------------------------*/
#include "main.h"

void MyInitEPwmGpio(void)
{
	EALLOW;
    GpioCtrlRegs.GPAPUD.bit.GPIO0 = 1;
    GpioCtrlRegs.GPAPUD.bit.GPIO1 = 1;
    GpioCtrlRegs.GPAMUX1.bit.GPIO0 = 1;
    GpioCtrlRegs.GPAMUX1.bit.GPIO1 = 1;

	GpioCtrlRegs.GPAPUD.bit.GPIO2 = 1;
    GpioCtrlRegs.GPAPUD.bit.GPIO3 = 1;
    GpioCtrlRegs.GPAMUX1.bit.GPIO2 = 1;
    GpioCtrlRegs.GPAMUX1.bit.GPIO3 = 1;

	GpioCtrlRegs.GPAPUD.bit.GPIO4 = 1;
    GpioCtrlRegs.GPAPUD.bit.GPIO5 = 1;
    GpioCtrlRegs.GPAMUX1.bit.GPIO4 = 1;
    GpioCtrlRegs.GPAMUX1.bit.GPIO5 = 1;

	GpioCtrlRegs.GPAPUD.bit.GPIO6 = 1;
    GpioCtrlRegs.GPAPUD.bit.GPIO7 = 1;
    GpioCtrlRegs.GPAMUX1.bit.GPIO6 = 1;
    GpioCtrlRegs.GPAMUX1.bit.GPIO7 = 1;

	GpioCtrlRegs.GPAPUD.bit.GPIO8 = 1;
    GpioCtrlRegs.GPAPUD.bit.GPIO9 = 1;
    GpioCtrlRegs.GPAMUX1.bit.GPIO8 = 1;
    GpioCtrlRegs.GPAMUX1.bit.GPIO9 = 1;

	GpioCtrlRegs.GPAPUD.bit.GPIO10 = 1;
    GpioCtrlRegs.GPAPUD.bit.GPIO11 = 1;
    GpioCtrlRegs.GPAMUX1.bit.GPIO10 = 1;
    GpioCtrlRegs.GPAMUX1.bit.GPIO11 = 1;
    EDIS;
}
void MyInitEPwmSIN3L(PWMSV3L* v)
{
	MyInitEPwmGpio();
	EALLOW;
	SysCtrlRegs.PCLKCR0.bit.TBCLKSYNC = 0;

	EPwm1Regs.TBPRD = v->Period; 
	EPwm1Regs.TBPHS.half.TBPHS = 0; 
	EPwm1Regs.CMPA.half.CMPA = 0;					
	EPwm1Regs.CMPB = 0;         					
	EPwm1Regs.TBCTL.bit.HSPCLKDIV = TB_DIV1;       	
	EPwm1Regs.TBCTL.bit.CLKDIV = TB_DIV1;
	EPwm1Regs.TBCTL.bit.CTRMODE = TB_COUNT_UPDOWN; 	
	EPwm1Regs.TBCTL.bit.PHSEN = TB_DISABLE; 		
	EPwm1Regs.TBCTL.bit.PRDLD = TB_SHADOW;
	EPwm1Regs.TBCTL.bit.SYNCOSEL = TB_CTR_ZERO; 	
	EPwm1Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;
	EPwm1Regs.CMPCTL.bit.SHDWBMODE = CC_SHADOW;
	EPwm1Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO; 	
	EPwm1Regs.CMPCTL.bit.LOADBMODE = CC_CTR_ZERO; 	
	EPwm1Regs.AQCTLA.bit.CAU = AQ_CLEAR;           	
	EPwm1Regs.AQCTLA.bit.CAD = AQ_SET;           	
	EPwm1Regs.AQCTLB.bit.CBU = AQ_SET;            	
	EPwm1Regs.AQCTLB.bit.CBD = AQ_CLEAR;           	

	EPwm1Regs.ETSEL.bit.INTSEL = ET_CTR_ZERO;      
	EPwm1Regs.ETSEL.bit.INTEN = 1;                 
	EPwm1Regs.ETPS.bit.INTPRD = ET_1ST;            


	EPwm2Regs.TBPRD = v->Period; 					
	EPwm2Regs.TBPHS.half.TBPHS = 0; 				
	EPwm2Regs.CMPA.half.CMPA = 0;					
	EPwm2Regs.CMPB = 0;         					
	EPwm2Regs.TBCTL.bit.HSPCLKDIV = TB_DIV1;       
	EPwm2Regs.TBCTL.bit.CLKDIV = TB_DIV1;
	EPwm2Regs.TBCTL.bit.CTRMODE = TB_COUNT_UPDOWN; 	
	EPwm2Regs.TBCTL.bit.PHSEN = TB_ENABLE; 			
	EPwm2Regs.TBCTL.bit.PHSDIR = TB_DOWN;
	EPwm2Regs.TBCTL.bit.PRDLD = TB_SHADOW;
	EPwm2Regs.TBCTL.bit.SYNCOSEL = TB_SYNC_IN; 		
	EPwm2Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;
	EPwm2Regs.CMPCTL.bit.SHDWBMODE = CC_SHADOW;
	EPwm2Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO; 	
	EPwm2Regs.CMPCTL.bit.LOADBMODE = CC_CTR_ZERO; 	
	EPwm2Regs.AQCTLA.bit.CAU = AQ_CLEAR;            
	EPwm2Regs.AQCTLA.bit.CAD = AQ_SET;           	
	EPwm2Regs.AQCTLB.bit.CBU = AQ_SET;            	
	EPwm2Regs.AQCTLB.bit.CBD = AQ_CLEAR;           

	EPwm3Regs.TBPRD = v->Period; 					
	EPwm3Regs.TBPHS.half.TBPHS = 0;					
	EPwm3Regs.CMPA.half.CMPA = 0;					
	EPwm3Regs.CMPB = 0;         					
	EPwm3Regs.TBCTL.bit.HSPCLKDIV = TB_DIV1;       	
	EPwm3Regs.TBCTL.bit.CLKDIV = TB_DIV1;
	EPwm3Regs.TBCTL.bit.CTRMODE = TB_COUNT_UPDOWN; 	
	EPwm3Regs.TBCTL.bit.PHSEN = TB_ENABLE; 			
	EPwm3Regs.TBCTL.bit.PHSDIR = TB_UP;
	EPwm3Regs.TBCTL.bit.PRDLD = TB_SHADOW;
	EPwm3Regs.TBCTL.bit.SYNCOSEL = TB_SYNC_IN; 		
	EPwm3Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;
	EPwm3Regs.CMPCTL.bit.SHDWBMODE = CC_SHADOW;
	EPwm3Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO; 	
	EPwm3Regs.CMPCTL.bit.LOADBMODE = CC_CTR_ZERO; 	
	EPwm3Regs.AQCTLA.bit.CAU = AQ_CLEAR;            
	EPwm3Regs.AQCTLA.bit.CAD = AQ_SET;           	
	EPwm3Regs.AQCTLB.bit.CBU = AQ_SET;            	
	EPwm3Regs.AQCTLB.bit.CBD = AQ_CLEAR;           	

	EPwm4Regs.TBPRD = v->Period; 					
	EPwm4Regs.TBPHS.half.TBPHS = 0;					
	EPwm4Regs.CMPA.half.CMPA = 0;					
	EPwm4Regs.CMPB = 0;         					
	EPwm4Regs.TBCTL.bit.HSPCLKDIV = TB_DIV1;       
	EPwm4Regs.TBCTL.bit.CLKDIV = TB_DIV1;
	EPwm4Regs.TBCTL.bit.CTRMODE = TB_COUNT_UPDOWN; 
	EPwm4Regs.TBCTL.bit.PHSEN = TB_ENABLE; 			
	EPwm4Regs.TBCTL.bit.PHSDIR = TB_DOWN;
	EPwm4Regs.TBCTL.bit.PRDLD = TB_SHADOW;
	EPwm4Regs.TBCTL.bit.SYNCOSEL = TB_SYNC_IN; 		
	EPwm4Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;
	EPwm4Regs.CMPCTL.bit.SHDWBMODE = CC_SHADOW;
	EPwm4Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO; 	
	EPwm4Regs.CMPCTL.bit.LOADBMODE = CC_CTR_ZERO; 	
	EPwm4Regs.AQCTLA.bit.CAU = AQ_CLEAR;            
	EPwm4Regs.AQCTLA.bit.CAD = AQ_SET;           	
	EPwm4Regs.AQCTLB.bit.CBU = AQ_SET;            	
	EPwm4Regs.AQCTLB.bit.CBD = AQ_CLEAR;           	

	EPwm5Regs.TBPRD = v->Period; 					
	EPwm5Regs.TBPHS.half.TBPHS = 0; 				
	EPwm5Regs.CMPA.half.CMPA = 0;					
	EPwm5Regs.CMPB = 0;         					
	EPwm5Regs.TBCTL.bit.HSPCLKDIV = TB_DIV1;       
	EPwm5Regs.TBCTL.bit.CLKDIV = TB_DIV1;
	EPwm5Regs.TBCTL.bit.CTRMODE = TB_COUNT_UPDOWN; 
	EPwm5Regs.TBCTL.bit.PHSEN = TB_ENABLE; 			
	EPwm5Regs.TBCTL.bit.PHSDIR = TB_DOWN;
	EPwm5Regs.TBCTL.bit.PRDLD = TB_SHADOW;
	EPwm5Regs.TBCTL.bit.SYNCOSEL = TB_SYNC_IN; 		
	EPwm5Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;
	EPwm5Regs.CMPCTL.bit.SHDWBMODE = CC_SHADOW;
	EPwm5Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO; 	
	EPwm5Regs.CMPCTL.bit.LOADBMODE = CC_CTR_ZERO; 	
	EPwm5Regs.AQCTLA.bit.CAU = AQ_CLEAR;           
	EPwm5Regs.AQCTLA.bit.CAD = AQ_SET;           	
	EPwm5Regs.AQCTLB.bit.CBU = AQ_SET;            	
	EPwm5Regs.AQCTLB.bit.CBD = AQ_CLEAR;           	

	EPwm6Regs.TBPRD = v->Period; 					
	EPwm6Regs.TBPHS.half.TBPHS = 0; 				
	EPwm6Regs.CMPA.half.CMPA = 0;					
	EPwm6Regs.CMPB = 0;         					
	EPwm6Regs.TBCTL.bit.HSPCLKDIV = TB_DIV1;       	
	EPwm6Regs.TBCTL.bit.CLKDIV = TB_DIV1;
	EPwm6Regs.TBCTL.bit.CTRMODE = TB_COUNT_UPDOWN; 	
	EPwm6Regs.TBCTL.bit.PHSEN = TB_ENABLE; 			
	EPwm6Regs.TBCTL.bit.PHSDIR = TB_UP;
	EPwm6Regs.TBCTL.bit.PRDLD = TB_SHADOW;
	EPwm6Regs.TBCTL.bit.SYNCOSEL = TB_SYNC_IN; 		
	EPwm6Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;
	EPwm6Regs.CMPCTL.bit.SHDWBMODE = CC_SHADOW;
	EPwm6Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO; 	
	EPwm6Regs.CMPCTL.bit.LOADBMODE = CC_CTR_ZERO; 	
	EPwm6Regs.AQCTLA.bit.CAU = AQ_CLEAR;            
	EPwm6Regs.AQCTLA.bit.CAD = AQ_SET;           	
	EPwm6Regs.AQCTLB.bit.CBU = AQ_SET;            	
	EPwm6Regs.AQCTLB.bit.CBD = AQ_CLEAR;           

	SysCtrlRegs.PCLKCR0.bit.TBCLKSYNC = 1;         
	EDIS;
}

void PWM3L_UPDATE(PWMSV3L* v)
{
	EPwm1Regs.CMPA.half.CMPA = _IQmpy(v->Period,v->Duty1A);
	EPwm2Regs.CMPA.half.CMPA = _IQmpy(v->Period,v->Duty2A);
	EPwm3Regs.CMPA.half.CMPA = _IQmpy(v->Period,v->Duty3A);
	EPwm4Regs.CMPA.half.CMPA = _IQmpy(v->Period,v->Duty4A);
	EPwm5Regs.CMPA.half.CMPA = _IQmpy(v->Period,v->Duty5A);
	EPwm6Regs.CMPA.half.CMPA = _IQmpy(v->Period,v->Duty6A);

	EPwm1Regs.CMPB = _IQmpy(v->Period,v->Duty1B);
	EPwm2Regs.CMPB = _IQmpy(v->Period,v->Duty2B);
	EPwm3Regs.CMPB = _IQmpy(v->Period,v->Duty3B);
	EPwm4Regs.CMPB = _IQmpy(v->Period,v->Duty4B);
	EPwm5Regs.CMPB = _IQmpy(v->Period,v->Duty5B);
	EPwm6Regs.CMPB = _IQmpy(v->Period,v->Duty6B);
}

