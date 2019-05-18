/* ======================================================================================
File name:      MYGRID.H
Developer:	    DaoNgocDat / email: daongocdat@gmail.com
Description: 	Declare structs and math functions for grid connected.
Target: 	    STM32F407
----------------------------------------------------------------------------------------*/
#ifndef __MYGRID_H__
#define __MYGRID_H__
#include "MyADC.h"

typedef struct { int32  vq[2];   		
				 int32  ylf[2];   		
				 int32  fo;				
				 int32  fn;				
				 int32  theta[2];		
				 int32  dT;				
				 int32  B0;				
				 int32  B1;				
				}PLL3P_OBJ;
#define PLL3P_DEFAULTS {0,0,0,0,0,0,0,0}

void ABC_DQ(DATA3P *v);
void DQ_ABC(DATA3P *v);
void SIN3P_SFO (DATA3P *v);
void PLL3P_INIT(int fgrid, long deltaT, PLL3P_OBJ *v);
void PLL3P(PLL3P_OBJ *v);

#endif
