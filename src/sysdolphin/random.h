#ifndef _random_h_
#define _random_h_

#include "global.h"


// Address: 803804F8 -> 80380524
s32 HSD_Rand(void);

// Address: 
f32 HSD_Randf(void);

// Address:
s32 HSD_Randi(s32 max_val);

// Address:
void _HSD_RandForgetMemory(u32* low, u32* high);

#endif
