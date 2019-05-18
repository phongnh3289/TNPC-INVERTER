/* ====================================================================================
File name:      MATHBLOCK.C
Developer:	    DaoNgocDat / email: daongocdat@gmail.com
Description: 	Math Functions for TNPC inverter
Target: 	    TMS320F28069
--------------------------------------------------------------------------------------*/
#include "main.h"

void RAMP_CNTL(RAMPCNTL *v)
{
	v->Tmp = v->TargetValue - v->SetpointValue;
	if (_IQabs(v->Tmp) >= _IQ(0.0000305))
	{
		v->RampDelayCount++	;
			if (v->RampDelayCount >= v->RampDelayMax)
			{
				if (v->TargetValue >= v->SetpointValue)
					v->SetpointValue += _IQ(0.0000305);
				else
					v->SetpointValue -= _IQ(0.0000305);

				v->SetpointValue=_IQsat(v->SetpointValue,v->RampHighLimit,v->RampLowLimit);
				v->RampDelayCount = 0;
			}
	}
	else v->EqualFlag = 0x7FFFFFFF;
}

void RAMP_GEN(RAMPGEN *v)
{
	v->Angle += _IQmpy(v->StepAngleMax,v->Freq);
	if (v->Angle>_IQ(1.0)) 			v->Angle -= _IQ(1.0);
	else if (v->Angle<_IQ(-1.0))	v->Angle += _IQ(1.0);
	v->Out = v->Angle;
}

void SVGEN_PWM(SVGEN *v)
{
	v->tmp1= v->Ubeta;
	v->tmp2= _IQdiv2(v->Ubeta) + (_IQmpy(_IQ(0.866),v->Ualpha));
	v->tmp3= v->tmp2 - v->tmp1;

	v->VecSector=3;
	v->VecSector=(v->tmp2> 0)?( v->VecSector-1):v->VecSector;
	v->VecSector=(v->tmp3> 0)?( v->VecSector-1):v->VecSector;
	v->VecSector=(v->tmp1< 0)?(7-v->VecSector) :v->VecSector;

	if (v->VecSector==1 || v->VecSector==4)
	{	v->Ta= v->tmp2;
		v->Tb= v->tmp1-v->tmp3;
		v->Tc=-v->tmp2;
	}
	else if(v->VecSector==2 || v->VecSector==5)
	{	v->Ta= v->tmp3+v->tmp2;
		v->Tb= v->tmp1;
		v->Tc=-v->tmp1;
	}
	else
	{	v->Ta= v->tmp3;
		v->Tb=-v->tmp3;
		v->Tc=-(v->tmp1+v->tmp2);
	}
}
void IPARK_TRFORM(IPARK *v)
{
	v->Alpha = _IQmpy(v->Ds,v->Cosine) - _IQmpy(v->Qs,v->Sine);
	v->Beta  = _IQmpy(v->Qs,v->Cosine) + _IQmpy(v->Ds,v->Sine);
}
void CLARKE_TRFORM(CLARKE *v)
{
	v->Alpha = v->As;
	v->Beta = _IQmpy((v->As +_IQmpy2(v->Bs)),_IQ(0.57735026918));
}
void PARK_TRFORM(PARK *v)
{
	v->Ds = _IQmpy(v->Alpha,v->Cosine) + _IQmpy(v->Beta,v->Sine);
    v->Qs = _IQmpy(v->Beta,v->Cosine) - _IQmpy(v->Alpha,v->Sine);
}
void PI_CONTROLER(PIDATA *v)
{
	v->up = _IQmpy(v->Kp, (v->Ref - v->Fbk));
	v->ui = (v->Out == v->v1)?(_IQmpy(v->Ki, v->up)+ v->i1) : v->i1;
	v->i1 = v->ui;
	v->v1 = v->up + v->ui;
	v->Out= _IQsat(v->v1, v->Umax, v->Umin);
	//v->w1 = (v->Out == v->v1) ? _IQ(1.0) : _IQ(0.0);
}
void MAPVECTOR(VECTOR3L *v)
{
	v->Va = v->Ualpha;
	v->Vb = _IQmpy(_IQ(-0.5),v->Ualpha) + _IQmpy(_IQ(0.8660254),v->Ubeta);
	v->Vc = _IQmpy(_IQ(-0.5),v->Ualpha) - _IQmpy(_IQ(0.8660254),v->Ubeta);

	if (v->Va > 0)
	{
		if ((v->Vb < 0)&(v->Vc < 0)) v->Sector = 1;
		if ((v->Vb > 0)&(v->Vc < 0)) v->Sector = 2;
		if ((v->Vb < 0)&(v->Vc > 0)) v->Sector = 6;
	}
	else if (v->Va <= 0)
	{
		if ((v->Vb > 0)&(v->Vc < 0)) v->Sector = 3;
		if ((v->Vb > 0)&(v->Vc > 0)) v->Sector = 4;
		if ((v->Vb < 0)&(v->Vc > 0)) v->Sector = 5;
	}
	if (v->Sector == 1) { v->Malpha = v->Ualpha - _IQ(0.5) ; v->Mbeta = v->Ubeta - 0 ;}
	if (v->Sector == 2) { v->Malpha = v->Ualpha - _IQ(0.25); v->Mbeta = v->Ubeta - _IQ(0.4330127);}
	if (v->Sector == 3) { v->Malpha = v->Ualpha + _IQ(0.25); v->Mbeta = v->Ubeta - _IQ(0.4330127);}
	if (v->Sector == 4) { v->Malpha = v->Ualpha + _IQ(0.5) ; v->Mbeta = v->Ubeta - 0 ;}
	if (v->Sector == 5) { v->Malpha = v->Ualpha + _IQ(0.25); v->Mbeta = v->Ubeta + _IQ(0.4330127);}
	if (v->Sector == 6) { v->Malpha = v->Ualpha - _IQ(0.25); v->Mbeta = v->Ubeta + _IQ(0.4330127);}
}

void DUTYSVTNPC (PWMSV3L *v)
{
	if (v->Sector == 1)
	{v->Duty1A = v->Ma;  v->Duty1B =_IQ(1); v->Duty4A =_IQ(1); v->Duty4B = v->Ma;
	 v->Duty2A =_IQ(-1); v->Duty2B = v->Mb; v->Duty5A = v->Mb; v->Duty5B =_IQ(-1);
	 v->Duty3A =_IQ(-1); v->Duty3B = v->Mc; v->Duty6A = v->Mc; v->Duty6B =_IQ(-1);}
	else if (v->Sector == 2)
	{v->Duty1A = v->Ma;  v->Duty1B =_IQ(1); v->Duty4A =_IQ(1); v->Duty4B = v->Ma;
	 v->Duty2A = v->Mb;  v->Duty2B =_IQ(1); v->Duty5A =_IQ(1); v->Duty5B = v->Mb;
	 v->Duty3A =_IQ(-1); v->Duty3B = v->Mc; v->Duty6A = v->Mc; v->Duty6B =_IQ(-1);}
	else if (v->Sector == 3)
	{v->Duty1A =_IQ(-1); v->Duty1B = v->Ma; v->Duty4A = v->Ma; v->Duty4B =_IQ(-1);
	 v->Duty2A = v->Mb;  v->Duty2B =_IQ(1); v->Duty5A =_IQ(1); v->Duty5B = v->Mb;
	 v->Duty3A =_IQ(-1); v->Duty3B = v->Mc; v->Duty6A = v->Mc; v->Duty6B =_IQ(-1);}
	else if (v->Sector == 4)
	{v->Duty1A =_IQ(-1); v->Duty1B = v->Ma; v->Duty4A = v->Ma; v->Duty4B =_IQ(-1);
	 v->Duty2A = v->Mb;  v->Duty2B =_IQ(1); v->Duty5A =_IQ(1); v->Duty5B = v->Mb;
	 v->Duty3A = v->Mc;  v->Duty3B =_IQ(1); v->Duty6A =_IQ(1); v->Duty6B = v->Mc;}
	else if (v->Sector == 5)
	{v->Duty1A =_IQ(-1); v->Duty1B = v->Ma; v->Duty4A = v->Ma; v->Duty4B =_IQ(-1);
	 v->Duty2A =_IQ(-1); v->Duty2B = v->Mb; v->Duty5A = v->Mb; v->Duty5B =_IQ(-1);
	 v->Duty3A = v->Mc;  v->Duty3B =_IQ(1); v->Duty6A =_IQ(1); v->Duty6B = v->Mc;}
	else if (v->Sector == 6)
	{v->Duty1A = v->Ma;  v->Duty1B =_IQ(1); v->Duty4A =_IQ(1); v->Duty4B = v->Ma;
	 v->Duty2A =_IQ(-1); v->Duty2B = v->Mb; v->Duty5A = v->Mb; v->Duty5B =_IQ(-1);
	 v->Duty3A = v->Mc;  v->Duty3B =_IQ(1); v->Duty6A =_IQ(1); v->Duty6B = v->Mc;}
}
void SIN3P_GEN (VOLREF *v)
{
	v->Va = v->Sin;
	v->Vb = _IQmpy(_IQ(-0.5),v->Sin) - _IQmpy(_IQ(0.8660254),v->Cos);
	v->Vc = _IQmpy(_IQ(-0.5),v->Sin) + _IQmpy(_IQ(0.8660254),v->Cos);
	if ((v->Va >= v->Vb)&(v->Va >= v->Vc)) v->Vmax = v->Va;
	if ((v->Vb >= v->Va)&(v->Vb >= v->Vc)) v->Vmax = v->Vb;
	if ((v->Vc >= v->Va)&(v->Vc >= v->Vb)) v->Vmax = v->Vc;
	if ((v->Va <= v->Vb)&(v->Va <= v->Vc)) v->Vmin = v->Va;
	if ((v->Vb <= v->Va)&(v->Vb <= v->Vc)) v->Vmin = v->Vb;
	if ((v->Vc <= v->Va)&(v->Vc <= v->Vb)) v->Vmin = v->Vc;
	v->Vos =_IQdiv2(v->Vmax + v->Vmin);
	v->Va -= v->Vos;
	v->Vb -= v->Vos;
	v->Vc -= v->Vos;
}
void DUTYSINTNPC (PWMSV3L *v)
{
	v->Duty1A = (v->Ma>0)?v->Ma:0;
	v->Duty1B = (v->Ma<0)?(_IQ(1)+v->Ma):_IQ(1);
	v->Duty4A = (v->Ma<0)?(v->Duty1B-_IQ(0.02)):_IQ(1);
	v->Duty4B = (v->Ma>0)?(v->Duty1A+_IQ(0.02)):0;

	v->Duty2A = (v->Mb>0)?v->Mb:0;
	v->Duty2B = (v->Mb<0)?(_IQ(1)+v->Mb):_IQ(1);
	v->Duty5A = (v->Mb<0)?(v->Duty2B-_IQ(0.02)):_IQ(1);
	v->Duty5B = (v->Mb>0)?(v->Duty2A+_IQ(0.02)):0;

	v->Duty3A = (v->Mc>0)?v->Mc:0;
	v->Duty3B = (v->Mc<0)?(_IQ(1)+v->Mc):_IQ(1);
	v->Duty6A = (v->Mc<0)?(v->Duty3B-_IQ(0.02)):_IQ(1);
	v->Duty6B = (v->Mc>0)?(v->Duty3A+_IQ(0.02)):0;
}
void DUTYOFF(PWMSV3L *v)
{
	v->Duty1A = 0;
	v->Duty1B = _IQ(1);
	v->Duty4A = 0;
	v->Duty4B = _IQ(1);

	v->Duty2A = 0;
	v->Duty2B = _IQ(1);
	v->Duty5A = 0;
	v->Duty5B = _IQ(1);;

	v->Duty3A = 0;
	v->Duty3B = _IQ(1);
	v->Duty6A = 0;
	v->Duty6B = _IQ(1);;
}

