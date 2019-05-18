/* ====================================================================================
File name:      MYGRID.C
Developer:	    DaoNgocDat / email: daongocdat@gmail.com
Description: 	Math Functions for Grid connected
Target: 	    TMS320F28069
--------------------------------------------------------------------------------------*/
#include "main.h"
#include "MyGrid.h"

#define pllQ 	_IQ21
#define Qmpy 	_IQ21mpy

void ABC_DQ(DATA3P *v)
{
	_iq k1 = _IQ(0.6666667), k2 = _IQ(0.3333333), k3 = _IQ(0.5773502);
	v->Alpha = _IQmpy(k1,v->As) - _IQmpy(k2,v->Bs) - _IQmpy(k2,v->Cs);
	v->Beta  = _IQmpy(k3,(v->Bs - v->Cs));
	v->Ds =   _IQmpy(v->Alpha,v->Cos) + _IQmpy(v->Beta,v->Sin);
	v->Qs = - _IQmpy(v->Alpha,v->Sin) + _IQmpy(v->Beta,v->Cos);
}

void DQ_ABC(DATA3P *v)
{
	_iq k1 = _IQ(0.5), k2 = _IQ(0.8660254038);
	v->Alpha = _IQmpy(v->Ds,v->Cos) - _IQmpy(v->Qs,v->Sin);
	v->Beta  = _IQmpy(v->Ds,v->Sin) + _IQmpy(v->Qs,v->Cos);;
	v->As = v->Alpha;
	v->Bs = - _IQmpy(k1,v->Alpha) + _IQmpy(k2,v->Beta);
	v->Cs = - v->As - v->Bs;
}

void SIN3P_SFO (DATA3P *v)
{
	if ((v->As >= v->Bs)&(v->As >= v->Cs)) v->max = v->As;
	if ((v->Bs >= v->As)&(v->Bs >= v->Cs)) v->max = v->Bs;
	if ((v->Cs >= v->As)&(v->Cs >= v->Bs)) v->max = v->Cs;
	if ((v->As <= v->Bs)&(v->As <= v->Cs)) v->min = v->As;
	if ((v->Bs <= v->As)&(v->Bs <= v->Cs)) v->min = v->Bs;
	if ((v->Cs <= v->As)&(v->Cs <= v->Bs)) v->min = v->Cs;
	v->offset =_IQdiv2(v->max + v->min);
	v->As -= v->offset;
	v->Bs -= v->offset;
	v->Cs -= v->offset;
}

void PLL3P_INIT(int fgrid, long deltaT, PLL3P_OBJ *v)
{
	v->vq[0]  = pllQ(0.0);
	v->vq[1]  = pllQ(0.0);
	v->ylf[0] = pllQ(0.0);
	v->ylf[1] = pllQ(0.0);

	v->fo = pllQ(0.0);
	v->fn = pllQ(fgrid);

	v->theta[0] = pllQ(0.0);
	v->theta[1] = pllQ(0.0);

	v->B0 = _IQ21(166.9743);
	v->B1 = _IQ21(-166.266);

	v->dT = deltaT;
}

void PLL3P(PLL3P_OBJ *v)
{
	v->ylf[0] = v->ylf[1] + Qmpy(v->B0,v->vq[0]) + Qmpy(v->B1,v->vq[1]);
	v->ylf[1] = v->ylf[0];
	v->vq[1] = v->vq[0];
	v->ylf[0] = (v->ylf[0]>pllQ(200))?pllQ(200):v->ylf[0];
	v->fo = v->fn + v->ylf[0];
	v->theta[0] = v->theta[1] + Qmpy(v->fo,v->dT);
	v->theta[0] = (v->theta[0]>pllQ(1))?(v->theta[0] - pllQ(1)):v->theta[0];
	v->theta[1] = v->theta[0];
}

