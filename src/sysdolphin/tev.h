#ifndef _tev_h_
#define _tev_h_

#include "global.h"

#include "objalloc.h"

// Address: 80362024 -> 8036207C
void HSD_RenderInitAllocData(void);

// Address: 80362080 -> 80362088
HSD_ObjAllocData* HSD_RenderGetAllocData(void);

// Address: 8036208C -> 80362094
HSD_ObjAllocData* HSD_TevRegGetAllocData(void);

// Address: 80362098 -> 803620A0
HSD_ObjAllocData* HSD_ChanGetAllocData(void);

// Address: 803620A4 -> 803623CC
void HSD_SetupChannel(void* ch);

// Address: 803623D0 -> 80362477
void HSD_StateSetNumChans(s32 num);

#endif
