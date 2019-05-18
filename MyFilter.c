/* ======================================================================================
File name:      MYFILTER.H
Developer:	    DaoNgocDat / email: daongocdat@gmail.com
Description: 	Filter functions for DSP.
Target: 	    TMS320F28069
----------------------------------------------------------------------------------------*/
#include "main.h"						
#include "MyFilter.h"

_iq _IQssfir(_iq *x, _iq *a, Uint16 n)
{

Uint16 i;								
_iq y;									
_iq *xold;								

	a = a + (n-1);						
	x = x + (n-1);						
	xold = x;							
	y = _IQmpy(*a--, *x--);

	for(i=0; i<n-1; i++)
	{
		y = y + _IQmpy(*a--, *x);		
		*xold-- = *x--;					
	}

	return(y);
}

