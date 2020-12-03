#ifndef _fobj_h_
#define _fobj_h_



#include "dolphin/types.h"

#include "object.h"
#include "objalloc.h"



#define HSD_A_OP_NONE 0
#define HSD_A_OP_CON  1
#define HSD_A_OP_LIN  2
#define HSD_A_OP_SPL0 3
#define HSD_A_OP_SPL  4
#define HSD_A_OP_SLP  5
#define HSD_A_OP_KEY  6

#define HSD_A_FRAC_FLOAT (0 << 5)
#define HSD_A_FRAC_S16   (1 << 5)
#define HSD_A_FRAC_U16   (2 << 5)
#define HSD_A_FRAC_S8    (3 << 5)
#define HSD_A_FRAC_U8    (4 << 5)

#define TYPE_ROBJ 1
#define TYPE_JOBJ 12



typedef struct _HSD_FObj     HSD_FObj;
typedef struct _HSD_FObjDesc HSD_FObjDesc;
typedef struct _HSD_FObjData FObjData;



struct _HSD_FObj
{
	HSD_FObj* next;
	u8*       ad;
	u8*       ad_head;
	u32       length;
	u8        flags;
	u8        op;
	u8        op_intrp;
	u8        obj_type;
	u8        frac_value;
	u8        frac_slope;
	u16       nb_pack;
	s16       startframe;
	u16       fterm;
	f32       time;
	f32       p0;
	f32       p1;
	f32       d0;
	f32       d1;
};

struct _HSD_FObjDesc 
{
	HSD_FObjDesc* next;
	u32           length;
	f32           startframe;
	u8            type;
	u8            frac_value;
	u8            frac_slope;
	u8            dummy0;
	u8*           ad;
};

struct _HSD_FObjData 
{
	f32 fv;
	s32 iv;
	Vec p;
};



// Address: 8036A938 - 8036A940
HSD_ObjAllocData* HSD_FObjGetAllocData(void);

// Address: 8036A944 - 8036a970
void HSD_FObjInitAllocData(void);

// Address: 8036A974 - 8036A998
void HSD_FObjRemove(HSD_FObj* fobj);

// Address: 8036A99C - 8036AA40
void HSD_FObjRemoveAll(HSD_FObj* fobj);

// Address: 8036AA44 - 8036AA60
u8 HSD_FObjSetState(HSD_FObj* fobj, u8 state);

// Address: 8036AA64 - 8036AA7C
u32 HSD_FObjGetState(HSD_FObj* fobj);

// Address: 8036AA80 - 8036AB20
void HSD_FObjReqAnimAll(HSD_FObj* fobj, f32 frame);

// Address: 8036AB24 - 8036AB74
void HSD_FObjStopAnim(HSD_FObj* fobj, void* obj, void (*callback)(), f32 frame);

// Address: 8036AB78 - 8036AC0C
void HSD_FObjStopAnimAll(HSD_FObj* fobj, void* obj, void (*callback)(), f32 frame);

// Address: 8036AE70 - 8036B02C
void FObjUpdateAnim(HSD_FObj* fobj, void* obj, void (*callback)(void*, u32, FObjData));

// Address: 8036B6CC - 8036B738
void HSD_FObjInterpretAnim(HSD_FObj* fobj, void* obj, void (*callback)(), f32 rate);

// Address: 8036B6CC - 8036B738
void HSD_FObjInterpretAnimAll(HSD_FObj* fobj, void* obj, void (*callback)(), f32 rate);

// Address: 8036B73C - 8036B844
HSD_FObj* HSD_FObjLoadDesc(HSD_FObjDesc* desc);

// Address: 8036B848 - 8036B8A0
HSD_FObj* HSD_FObjAlloc(void);

// Address: 8036B8A4 - 8036B8CC
void HSD_FObjFree(HSD_FObj* fobj);



#endif
