/* ====================================================================================
File name:      MYSCI.C                                     
Developer:	    DaoNgocDat / email: daongocdat@gmail.com
Target: 	    TMS320F28069
--------------------------------------------------------------------------------------*/
#include "main.h"
#include "MySCI.h"

void MySciaGpio(void)
{
   EALLOW;
   GpioCtrlRegs.GPAPUD.bit.GPIO28 = 0;  
   GpioCtrlRegs.GPAPUD.bit.GPIO29 = 0;	
   GpioCtrlRegs.GPAQSEL2.bit.GPIO28 = 3; 
   GpioCtrlRegs.GPAMUX2.bit.GPIO28 = 1;  
   GpioCtrlRegs.GPAMUX2.bit.GPIO29 = 1;   
    EDIS;
}

void RS485_INIT(void)
{
 	SciaRegs.SCICCR.all =0x0007; 
	SciaRegs.SCICTL1.all =0x0003;  
   	SciaRegs.SCICTL2.bit.TXINTENA =0;
   	SciaRegs.SCICTL2.bit.RXBKINTENA =1;
	SciaRegs.SCIHBAUD    =0x0000; 
    SciaRegs.SCILBAUD    =0x0091;
   	SciaRegs.SCICCR.bit.LOOPBKENA =0;
   	SciaRegs.SCIFFTX.all = 0xC000;
   	SciaRegs.SCIFFRX.all = 0x0022;
   	SciaRegs.SCICTL1.all =0x0023;  
   	SciaRegs.SCIFFTX.bit.TXFIFOXRESET=1;
   	SciaRegs.SCIFFRX.bit.RXFIFORESET=1;
}
void ENTX(void)
{
	EALLOW;
	GpioDataRegs.GPASET.bit.GPIO12   = 1;
	EDIS;
}
void ENRX(void)
{
	EALLOW;
	GpioDataRegs.GPACLEAR.bit.GPIO12 = 1;
	EDIS;
}
void scia_xmit(int a)
{
    SciaRegs.SCITXBUF=a;
    while (SciaRegs.SCICTL2.bit.TXEMPTY == 0) {}
}

