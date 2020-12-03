#ifndef ___mem_
#define ___mem_



// Address  : 80003100 - 8000312C
__declspec(section ".init") void * memset(void * dst, int val, unsigned long n);



// Address  : 80003130 - 800031F0
__declspec(section ".init") void __fill_mem(void * dst, int val, unsigned long n);



#endif
