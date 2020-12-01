#ifndef _RAND_H_
#define _RAND_H_

#include "include/dolphin/types.h"

// Address: 803257BC -> 803257C0?
void srand(u32 seed);

// Address: 803257C4 -> 80325874?
s32 rand(void);

#endif
