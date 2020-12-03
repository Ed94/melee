#ifndef _random_h_
#define _random_h_



#include "global.h"



// Address: 803804F8 - 80380524
s32 HSD_Rand(void);

// Address: 80380528 - 8038057C
f32 HSD_Randf(void);

// Address: 80380580 - 803805B8
s32 HSD_Randi(s32 max_val);

// Address:  803805BC - 803805D8
void _HSD_RandForgetMemory(u32* low, u32* high);



#endif
