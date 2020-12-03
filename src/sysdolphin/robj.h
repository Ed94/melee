#ifndef _robj_h_
#define _robj_h_



#include "global.h"

#include "objalloc.h"

#include "aobj.h"
#include "jobj.h"



#define REFTYPE_IKHINT 0x40000000
#define REFTYPE_JOBJ   0x10000000
#define TYPE_MASK      0x70000000



typedef union _Func_ByteCode                  Func_ByteCode;
typedef union _HSD_JO_Exp_IKHint              HSD_JO_Exp_IKHint;
typedef union _HSD_I_ExDes_BCExDes_IKH_JO_Lim HSD_I_ExDes_BCExDes_IKH_JO_Lim;

typedef struct _HSD_AObj            HSD_AObj;
typedef struct _HSD_ByteCodeExpDesc HSD_ByteCodeExpDesc;
typedef struct _HSD_Exp             HSD_Exp;
typedef struct _HSD_ExpDesc         HSD_ExpDesc;
typedef struct _HSD_IKHint          HSD_IKHint;
typedef struct _HSD_IKHintDesc      HSD_IKHintDesc;
typedef struct _HSD_JObj            HSD_JObj;
typedef struct _HSD_JObjDesc        HSD_JObjDesc;
typedef struct _HSD_Rvalue          HSD_Rvalue;
typedef struct _HSD_RvalueList      HSD_RvalueList;
typedef struct _HSD_RObj            HSD_RObj;
typedef struct _HSD_RObjAnimJoint   HSD_RObjAnimJoint;
typedef struct _HSD_RObjDesc        HSD_RObjDesc;



union _Func_ByteCode
{
	f32 (*func)(void);

	u8* bytecode;
};

struct _HSD_Exp 
{
	Func_ByteCode expr;
	HSD_Rvalue*   rvalue;
	u32           nb_args;
	u8            is_bytecode;
};

struct _HSD_IKHint
{
	f32 bone_length;
	f32 rotate_x;
};

union _HSD_JO_Exp_IKHint
{
	HSD_JObj*  jobj;
	HSD_Exp    exp;
	f32        limit;
	HSD_IKHint ik_hint;
};

union _HSD_I_ExDes_BCExDes_IKH_JO_Lim
{
	u32                  i;
	HSD_ExpDesc*         exp;
	HSD_ByteCodeExpDesc* bcexp;
	HSD_IKHintDesc*      ik_hint;
	HSD_JObjDesc*        joint;
	f32                  limit;
};

struct _HSD_Rvalue
{
	HSD_Rvalue* next;
	u32         flags;
	HSD_JObj*   jobj;
};

struct _HSD_RvalueList
{
	u32             flags;
	HSD_JObjDesc*   joint;
	HSD_RvalueList* next;
};

typedef struct _HSD_IKHintDesc
{
	f32 bone_length;
	f32 rotate_x;
};

struct _HSD_ExpDesc 
{
	f32 (*func)(void);

	HSD_RvalueList* rvalue;
};

typedef struct _HSD_ByteCodeExpDesc
{
	u8*             bytecode;
	HSD_RvalueList* rvalue;
};

struct _HSD_RObj 
{
	HSD_RObj*         next;
	u32               flags;
	HSD_JO_Exp_IKHint u;
	HSD_AObj*         aobj;
};

struct _HSD_RObjDesc 
{
	HSD_RObjDesc*                  next;
	u32                            flags; //0x04
	HSD_I_ExDes_BCExDes_IKH_JO_Lim u;
};

struct _HSD_RObjAnimJoint
{
	HSD_RObjAnimJoint* next;
	HSD_AObjDesc*      aobjdesc;
};



// Address: 8037AE34 - 8037AE74
void HSD_RObjInitAllocData(void);

// Address: 8037AE78 - 8037AE80
HSD_ObjAllocData* HSD_RObjGetAllocData(void);

// Address: 8037AE84 - 8037AE8C
HSD_ObjAllocData* HSD_RvalueObjGetAllocData(void);

// Address: 8037AE90 - 8037AEA4
void HSD_RObjSetFlags(HSD_RObj* robj, u32 flags);



#endif
