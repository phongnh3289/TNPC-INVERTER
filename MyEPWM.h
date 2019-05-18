/* ====================================================================================
File name:      MYEPWM.H                                     
Developer:	    DaoNgocDat / email: daongocdat@gmail.com
Target: 	    TMS320F28069
--------------------------------------------------------------------------------------*/
#ifndef MYEPWM_H
#define MYEPWM_H

#include "F2806x_Device.h"     
#include "F2806x_Examples.h"   

typedef struct {
        Uint16 Period;   	
        Uint16 HalfPrd;		
        Uint16 Deadtime;   
        _iq MfuncC1;      
        _iq MfuncC2;      
        _iq MfuncC3;     
        } PWMGEN ;

#define PWMGEN_DEFAULTS   {0,0,0,0,0,0}

extern void MyInitEPwmGpio(void);
extern void MyInitEPwmSIN3L(PWMSV3L* v);
extern void PWM3L_UPDATE(PWMSV3L* v);

#endif
