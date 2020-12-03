#ifndef _gobj_h_
#define _gobj_h_



#include "include/dolphin/types.h"



typedef struct _HSD_GObj     HSD_GObj;
typedef struct _HSD_GObjProc HSD_GObjProc;



struct _HSD_GObj 
{
    u16           classifier;
    s8            p_link;
    s8            gx_link;
    u8            p_priority;
    u8            render_priority;
    s8            obj_kind;
    s8            user_data_kind;
    HSD_GObj*     next; //0x08
    HSD_GObj*     prev; //0x0C
    HSD_GObj*     next_gx; //0x10
    HSD_GObj*     prev_gx; //0x14
    HSD_GObjProc* proc; //0x18

    void (*render_cb)(HSD_GObj* gobj, int code); //0x1C
    
    u64   gxlink_prios;
    void* hsd_obj;
    void* data;
    
    void (*user_data_remove_func)(void* data);
    
    void* x34_unk;
};

struct _HSD_GObjProc 
{
    HSD_GObjProc* child; //0x0
    HSD_GObjProc* next; //0x4
    HSD_GObjProc* prev; //0x8
    u8            s_link; //0xC
    u8            flags; //0xD
    HSD_GObj*     gobj; //0x10

    void (*callback)(struct _HSD_GObj*); //0x14
};



// Address: 80390C5C - 80390C80
BOOL func_80390C5C(HSD_GObj* gobj);

// Address: 80390C84 - 80390Cd3
BOOL func_80390C84(HSD_GObj* gobj);



#endif