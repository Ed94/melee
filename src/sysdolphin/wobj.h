#ifndef _wobj_h_
#define _wobj_h_



#include "global.h"

#include "object.h"
#include "aobj.h"



typedef struct _HSD_AObj          HSD_AObj;
typedef struct _HSD_AObjDesc      HSD_AObjDesc;
typedef struct _HSD_RObj          HSD_RObj;
typedef struct _HSD_RObjAnimJoint HSD_RObjAnimJoint;
typedef struct _HSD_RObjDesc      HSD_RObjDesc;
typedef struct _HSD_WObj          HSD_WObj;
typedef struct _HSD_WObjAnim      HSD_WObjAnim;
typedef struct _HSD_WObjDesc      HSD_WObjDesc;
typedef struct _HSD_WObjInfo      HSD_WObjInfo;



struct _HSD_WObj 
{
	HSD_Obj   parent;
	u32       flags;
	Vec       pos;
	HSD_AObj* aobj;
	HSD_RObj* robj;
};

struct _HSD_WObjDesc 
{
	char*         class_name;
	Vec           pos;
	HSD_RObjDesc* robjdesc;
	HSD_WObjDesc* next;
};

struct _HSD_WObjInfo 
{
	HSD_ObjInfo parent;

	int (*load)(HSD_WObj* wobj, HSD_WObjDesc* desc);
};

struct _HSD_WObjAnim
{
	HSD_AObjDesc*      aobjdesc;
	HSD_RObjAnimJoint* robjanim;
};



// Address: 8037D050 -> 8037D090
void HSD_WObjRemoveAnim(HSD_WObj* wobj);

// Address: 8037D094 -> 8037D0E0
void HSD_WObjReqAnim(HSD_WObj* wobj, f32 frame);



#endif
