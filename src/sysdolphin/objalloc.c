#include "objalloc.h"



extern objheap lbl_80406E48;



#ifndef USE_ASM_VERSION



void HSD_ObjSetHeap(u32 size, void* ptr)
{
	objheap* heap = &lbl_80406E48;

	heap->curr   = (u32)ptr;
	heap->top    = (u32)ptr;
	heap->remain = size;
	heap->size   = size;
}



#else   // ASM


asm void HSD_ObjSetHeap(u32 size, void* ptr)
{
nofrealloc
/* 8037A94C 0037752C  3C A0 80 40 */	lis r5, lbl_80406E48@ha
/* 8037A950 00377530  38 A5 6E 48 */	addi r5, r5, lbl_80406E48@l
/* 8037A954 00377534  90 85 00 04 */	stw r4, 4(r5)
/* 8037A958 00377538  90 85 00 00 */	stw r4, 0(r5)
/* 8037A95C 0037753C  90 65 00 0C */	stw r3, 0xc(r5)
/* 8037A960 00377540  90 65 00 08 */	stw r3, 8(r5)
/* 8037A964 00377544  4E 80 00 20 */	blr 
}



#endif