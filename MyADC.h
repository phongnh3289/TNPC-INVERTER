/* ====================================================================================
File name:      MYADC.H                                     
Developer:	    DaoNgocDat / email: daongocdat@gmail.com
Target: 	    TMS320F28069
--------------------------------------------------------------------------------------*/
#ifndef MYADC_H
#define MYADC_H

#include "F2806x_Device.h"
#include "F2806x_Examples.h"

typedef struct { _iq As;
				 _iq Bs;
				 _iq Cs;
				 _iq max;
				 _iq min;
				 _iq offset;
				 _iq Alpha;
				 _iq Beta;
				 _iq Ds;
				 _iq Qs;
				 _iq Sin;
				 _iq Cos;
				 _iq Ka;
				 _iq Kb;
				 _iq Kc;
				} DATA3P;
#define DATA3P_DEFAULTS {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}

extern void MyInitADC(int* ChSel, int* Trigsel, int* ACQPS);

#endif
