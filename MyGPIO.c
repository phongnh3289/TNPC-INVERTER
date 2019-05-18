/* ====================================================================================
File name:      MYGPIO.C                                     
Developer:	    DaoNgocDat / email: daongocdat@gmail.com
Target: 	    TMS320F28069
--------------------------------------------------------------------------------------*/
#include "main.h"

void MyInitGpio(void)
{
	EALLOW;

   GpioCtrlRegs.GPAMUX1.all = 0x0000;     
   GpioCtrlRegs.GPAMUX2.all = 0x0000;    
   GpioCtrlRegs.GPBMUX1.all = 0x0000;    
   GpioCtrlRegs.GPBMUX2.all = 0x0000;	 
   GpioCtrlRegs.AIOMUX1.all = 0x0000;    

   GpioCtrlRegs.GPADIR.all = 0x0000;     
   GpioCtrlRegs.GPBDIR.all = 0x0000;     
   GpioCtrlRegs.AIODIR.all = 0x0000;     

   GpioCtrlRegs.GPAQSEL1.all = 0x0000;   
   GpioCtrlRegs.GPAQSEL2.all = 0x0000;   
   GpioCtrlRegs.GPBQSEL1.all = 0x0000;   
   GpioCtrlRegs.GPBQSEL2.all = 0x0000;	 

   GpioCtrlRegs.GPAPUD.all = 0x0000;      
   GpioCtrlRegs.GPBPUD.all = 0x0000;      

   GpioCtrlRegs.GPBDIR.bit.GPIO34 = 1;	
   GpioCtrlRegs.GPBDIR.bit.GPIO39 = 1;	
   GpioCtrlRegs.GPADIR.bit.GPIO25 = 0;	
   GpioCtrlRegs.GPADIR.bit.GPIO19 = 1;	
   GpioCtrlRegs.GPADIR.bit.GPIO16 = 1;	
   GpioCtrlRegs.GPADIR.bit.GPIO12 = 1;	
   EDIS;
}
void DisableDriver(void)
{
	EALLOW;
	GpioDataRegs.GPACLEAR.bit.GPIO19 = 1;
	GpioDataRegs.GPASET.bit.GPIO16   = 1;
	EDIS;
}
void EnableDriver(void)
{
	EALLOW;
	GpioDataRegs.GPASET.bit.GPIO19   = 1;
	GpioDataRegs.GPACLEAR.bit.GPIO16 = 1;
	GpioDataRegs.GPASET.bit.GPIO16   = 1;
	EDIS;
}

