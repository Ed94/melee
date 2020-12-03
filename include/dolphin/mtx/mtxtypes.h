#ifndef _MTXTYPES_h_
#define _MTXTYPES_h_



#include "dolphin/types.h"



typedef f32   Mtx    [3][4];
typedef f32 (*MtxPtr)[4]   ;

typedef f32   Mtx44    [4][4];
typedef f32 (*Mtx44Ptr)[4]   ;

typedef struct _Quaternion Quaternion;
typedef struct _Vec        Vec;



struct _Quaternion
{
	f32 x, y, z, w;
};

struct _Vec
{
	f32 x, y, z;
};



#endif
