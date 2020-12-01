#ifndef _objalloc_h_
#define _objalloc_h_

#include "global.h"

typedef struct _objheap {
    u32 top;
    u32 curr;
    u32 size;
    u32 remain;
} objheap;

typedef struct _HSD_ObjAllocLink {
    struct _HSD_ObjAllocLink* next;
} HSD_ObjAllocLink;

typedef struct _HSD_ObjAllocData {
    u32 num_limit_flag : 1;
    u32 heap_limit_flag : 1;
    HSD_ObjAllocLink* freehead;
    u32 used;
    u32 free;
    u32 peak;
    u32 num_limit;
    u32 heap_limit_size;
    u32 heap_limit_num;
    u32 size;
    u32 align;
    struct _HSD_ObjAllocData* next;
} HSD_ObjAllocData;

// Address: 8037A94C -> 8037A964
void HSD_ObjSetHeap(u32 size, void* ptr);

// Address: 8037A968 -> 8037ABC4
s32	HSD_ObjAllocAddFree(HSD_ObjAllocData* data, u32 num);

// Address: 8037ABC8 -> 8037AD1C
void* HSD_ObjAlloc(HSD_ObjAllocData* data);

// Address: 8037AD20 -> 8037AD44
void HSD_ObjFree(HSD_ObjAllocData* data, void* obj);

// Address: 8037AE28 -> 8037AE30
void _HSD_ObjAllocForgetMemory(void);

#endif
