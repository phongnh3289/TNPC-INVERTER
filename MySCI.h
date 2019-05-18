/* ====================================================================================
File name:      MYSCI.H                                    
Developer:	    DaoNgocDat / email: daongocdat@gmail.com
Target: 	    TMS320F28069
--------------------------------------------------------------------------------------*/
#ifndef MYSCI_H
#define MYSCI_H

#include "F2806x_Device.h" 
#include "F2806x_Examples.h"  

extern void MySciaGpio(void);
extern void RS485_INIT(void);
extern void ENTX(void);
extern void ENRX(void);
extern void scia_xmit(int a);

#endif
