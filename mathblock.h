/* ======================================================================================
File name:      MATHBLOCK.H
Developer:	    DaoNgocDat / email: daongocdat@gmail.com
Description: 	Declare structs and math functions.
Target: 	    STM32F407
----------------------------------------------------------------------------------------*/
#ifndef __MATHBLOCK_H__
#define __MATHBLOCK_H__

typedef struct { _iq    TargetValue; 	
				 Uint32 RampDelayMax;	
		 	 	 _iq    RampLowLimit;	
				 _iq    RampHighLimit;	
				 Uint32 RampDelayCount; 
				 _iq    SetpointValue;	
				 Uint32 EqualFlag;		
				 _iq	Tmp;			
		  	   } RAMPCNTL;

#define RMPCNTL_DEFAULTS {0, 5, _IQ(0.0), _IQ(1), 0,	0, 0, 0}

typedef struct { _iq  Freq; 		
				 _iq  StepAngleMax;	
				 _iq  Angle;		
				 _iq  Gain;			
				 _iq  Out;  	 	
				 _iq  Offset;		
				} RAMPGEN;
               
#define RAMPGEN_DEFAULTS {0, 0, 0 ,_IQ(1), 0, 0}

typedef struct 	{ _iq  Ualpha; 			
				  _iq  Ubeta;			
				  _iq  Ta;				
				  _iq  Tb;				
				  _iq  Tc;				
				  _iq  tmp1;			
				  _iq  tmp2;			
				  _iq  tmp3;			
				  Uint16 VecSector;		
				} SVGEN;

#define SVGEN_DEFAULTS {0,0,0,0,0,0,0,0,0 }

typedef struct {  _iq  Alpha;  		
				  _iq  Beta;		
				  _iq  Angle;		
				  _iq  Ds;			
				  _iq  Qs;			
				  _iq  Sine;		
				  _iq  Cosine;		
				} IPARK;

#define IPARK_DEFAULTS {0,0,0,0,0,0,0}

typedef struct {  _iq  As;  		
				  _iq  Bs;			
				  _iq  Cs;			
				  _iq  Alpha;		
				  _iq  Beta;		
				} CLARKE;

#define CLARKE_DEFAULTS {0,0,0,0,0}

typedef struct {  _iq  Alpha;  		
				  _iq  Beta;	 	
				  _iq  Angle;		
				  _iq  Ds;			
				  _iq  Qs;			
				  _iq  Sine;
				  _iq  Cosine;
				} PARK;

#define PARK_DEFAULTS {0,0,0,0,0,0,0}

typedef struct {  _iq  Ref;   		
				  _iq  Fbk;   		
				  _iq  Out;   		
				  _iq  Kp;			
				  _iq  Ki;			
				  _iq  Umax;	
				  _iq  Umin;		
				  _iq  up;			
				  _iq  ui;			
				  _iq  v1;		
				  _iq  i1;		
				  _iq  w1;		
				} PIDATA;

#define PIDATA_DEFAULTS {0,0,0,0,0,0,0,0,0,0,0,0}

typedef struct {  _iq   m;   		
				  _iq   Ualpha;  
				  _iq   Ubeta;		
				  _iq   Va;   	
				  _iq   Vb;   	
				  _iq   Vc;   	
				  Uint8 Sector;		
				  _iq   Malpha;  	
				  _iq   Mbeta;		
				} VECTOR3L;

#define VECTOR3L_DEFAULTS {0,0,0,0,0,0,0,0,0}

typedef struct { Uint16 Period;   		
				 Uint16 HalfPrd;		
				  _iq   Sector;   		
				  _iq	Ma;				
				  _iq	Mb;				
				  _iq	Mc;				
				  _iq	Duty1A;			
				  _iq	Duty1B;			
				  _iq	Duty2A;			
				  _iq	Duty2B;			
				  _iq	Duty3A;			
				  _iq	Duty3B;			
				  _iq	Duty4A;			
				  _iq	Duty4B;			
				  _iq	Duty5A;			
				  _iq	Duty5B;			
				  _iq	Duty6A;			
				  _iq	Duty6B;			
				}PWMSV3L;

#define PWMSV3L_DEFAULTS {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}

typedef struct { _iq  Sin;   			
				 _iq  Cos;   			
				 _iq  Va;				
				 _iq  Vb;				
				 _iq  Vc;				
				 _iq  Vmax;				
				 _iq  Vmin;				
				 _iq  Vos;				
				}VOLREF;
#define VOLREF_DEFAULTS  {0,0,0,0,0}

void RAMP_CNTL(RAMPCNTL *v);
void RAMP_GEN(RAMPGEN *v);
void SVGEN_PWM(SVGEN *v);
void IPARK_TRFORM(IPARK *v);
void CLARKE_TRFORM(CLARKE *v);
void PARK_TRFORM(PARK *v);
void PI_CONTROLER(PIDATA *v);
void MAPVECTOR(VECTOR3L *v);
void DUTYSVTNPC (PWMSV3L *v);
void DUTYSINTNPC (PWMSV3L *v);
void DUTYOFF(PWMSV3L *v);
void SIN3P_GEN(VOLREF *v);

#endif 
