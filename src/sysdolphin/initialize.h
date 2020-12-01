#ifndef _initialize_h_
#define _initialize_h_

#include "global.h"

typedef struct _HSD_MemReport
{
    u32 total;
    u32 system;
    u32 xfb;
    u32 gxfifo;
    u32 heap;
} HSD_MemReport;

// Address: 80374E48 -> 80374F5C
void HSD_InitComponent(void);

// Address: 80374F60 -> 80374F74
void HSD_GXSetFifoObj(GXFifoObj* fifo);

// Address: 80374f78
void HSD_DVDInit(void);

#endif
