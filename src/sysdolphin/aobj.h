#ifndef _aobj_h_
#define _aobj_h_



#include "dolphin/types.h"

#include "id.h"
#include "object.h"
#include "objalloc.h"

#include "fobj.h"
#include "list.h"



#define AOBJ_REWINDED   (1 << 26)
#define AOBJ_FIRST_PLAY (1 << 27)
#define AOBJ_NO_UPDATE  (1 << 28)
#define AOBJ_LOOP       (1 << 29)
#define AOBJ_NO_ANIM    (1 << 30)



typedef struct _HSD_AnimJoint     HSD_AnimJoint;
typedef struct _HSD_AObj          HSD_AObj     ;
typedef struct _HSD_AObjDesc      HSD_AObjDesc ;
typedef struct _HSD_Obj           HSD_Obj;
typedef struct _HSD_RObjAnimJoint HSD_RObjAnimJoint;



struct _HSD_AnimJoint 
{
	HSD_AnimJoint*     child;
	HSD_AnimJoint*     next;
	HSD_AObjDesc*      aobjdesc;
	HSD_RObjAnimJoint* robj_anim;
	u32                flags;
};

struct _HSD_AObj 
{
	u32       flags;
	f32       curr_frame;
	f32       rewind_frame;
	f32       end_frame;
	f32       framerate;
	HSD_FObj* fobj;
	HSD_Obj*  hsd_obj;
};

struct _HSD_AObjDesc 
{
	u32           flags;
	f32           end_frame;
	HSD_FObjDesc* fobjdesc;
	u32           obj_id;
};



// Address: 80363fC8 - 80363FF4
void HSD_AObjInitAllocData(void);

// Address: 80363ff8 - 80364000
HSD_ObjAllocData* HSD_AObjGetAllocData(void);

// Address: 80364004 - 80364010
u32 HSD_AObjGetFlags(HSD_AObj* aobj);

// Address: 8036401C - 80364034
void HSD_AObjSetFlags(HSD_AObj* aobj, u32 flags);

// Address: 80364038 - 80364050
void HSD_AObjClearFlags(HSD_AObj* aobj, u32 flags);

// Address: 80364054 - 80364080
void HSD_AObjSetFObj(HSD_AObj* aobj, HSD_FObj* fobj);

// Address: 803640A0 - 803640AC
void HSD_AObjInitEndCallBack(void);

// Address: 803640B0 - 80364108
void HSD_AObjInvokeCallBacks(void);

// Address: 8036410C - 80364148
void HSD_AObjReqAnim(HSD_AObj* aobj, f32 frame);

// Address: 8036414C - 80364150
void HSD_AObjStopAnim(HSD_AObj* aobj, void* obj, void (*func)());

// Address: 80364190 - 8036433C
void HSD_AObjInterpretAnim(HSD_AObj* aobj, void* obj, void (*update_func)());

// Address: 80364340 - 80364398
f32 fmod(f64 x, f64 y);

// Address: 8036439C - 803644C8
HSD_AObj* HSD_AObjLoadDesc(HSD_AObjDesc* aobjdesc);

// Address: 803644CC - 80364538
void HSD_AObjRemove(HSD_AObj* aobj);

// Address: 8036453C - 803645A4
HSD_AObj* HSD_AObjAlloc(void);

// Address: 803645A8 - 803645D4
void HSD_AObjFree(HSD_AObj* aobj);

// Address: 803645D8 - 803646F0
void func_803645D8(void);

// Address: 803646F4 - 80364764
void func_803646F4(void);

// Address: 803647DC - 80364920
void func_803647DC(void);

// Address: 80364924 - 80364C04
void func_80364924(void);

// Address: 8036530C - 80365318
void HSD_AObjSetRate(HSD_AObj* aobj, f32 rate);

// Address: 8036531C - 80365328
void HSD_AObjSetRewindFrame(HSD_AObj* aobj, f32 frame);

// Address: 8036532C - 80365338
void HSD_AObjSetEndFrame(HSD_AObj* aobj, f32 frame);

// Address: 8036533C - 8036538C
void HSD_AObjSetCurrentFrame(HSD_AObj* aobj, f32 frame);

// Address: 80365390 - 80365398
void _HSD_AObjForgetMemory(void);



#endif
