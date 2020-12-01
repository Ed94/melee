#ifndef ___mem_
#define ___mem_


// Address  : 80003100 - 8000312C		
// Offset   : 100
// GenSymbol: func_80003100
__declspec(section ".init") void * memset(void * dst, int val, unsigned long n);


// Address  : 80003130 - 800031F0		
// Offset   : 130
// GenSymbol: func_80003130
__declspec(section ".init") void __fill_mem(void * dst, int val, unsigned long n);

#endif
