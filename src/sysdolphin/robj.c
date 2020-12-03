#include "robj.h"



extern HSD_ObjAllocData lbl_804C2368; // robj_alloc_data
extern HSD_ObjAllocData lbl_804C2394; // rvalue_alloc_data



#ifndef USE_ASM_VERSION



void HSD_RObjInitAllocData(void)
{
	HSD_ObjAllocInit(&lbl_804C2368, sizeof(HSD_RObj), 4);

	HSD_ObjAllocInit(&lbl_804C2394, sizeof(HSD_Rvalue), 4);
}

HSD_ObjAllocData* HSD_RObjGetAllocData(void)
{
	return &lbl_804C2368;
}

HSD_ObjAllocData* HSD_RvalueObjGetAllocData(void)
{
	return &lbl_804C2394;
}

void HSD_RObjSetFlags(HSD_RObj* robj, u32 flags)
{
	if (robj != NULL) 
	{
		robj->flags |= flags;
	}
}



#else   // ASM



asm void HSD_RObjInitAllocData(void)
{
nofralloc
/* 8037AE34 00377A14  7C 08 02 A6 */	mflr r0
/* 8037AE38 00377A18  3C 60 80 4C */	lis r3, lbl_804C2368@ha
/* 8037AE3C 00377A1C  90 01 00 04 */	stw r0, 4(r1)
/* 8037AE40 00377A20  38 63 23 68 */	addi r3, r3, lbl_804C2368@l
/* 8037AE44 00377A24  38 80 00 1C */	li r4, 0x1c
/* 8037AE48 00377A28  94 21 FF F8 */	stwu r1, -8(r1)
/* 8037AE4C 00377A2C  38 A0 00 04 */	li r5, 4
/* 8037AE50 00377A30  4B FF FE F9 */	bl func_8037AD48
/* 8037AE54 00377A34  3C 60 80 4C */	lis r3, lbl_804C2394@ha
/* 8037AE58 00377A38  38 63 23 94 */	addi r3, r3, lbl_804C2394@l
/* 8037AE5C 00377A3C  38 80 00 0C */	li r4, 0xc
/* 8037AE60 00377A40  38 A0 00 04 */	li r5, 4
/* 8037AE64 00377A44  4B FF FE E5 */	bl func_8037AD48
/* 8037AE68 00377A48  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8037AE6C 00377A4C  38 21 00 08 */	addi r1, r1, 8
/* 8037AE70 00377A50  7C 08 03 A6 */	mtlr r0
/* 8037AE74 00377A54  4E 80 00 20 */	blr 
/* 8037AE78 00377A58  3C 60 80 4C */	lis r3, lbl_804C2368@ha
/* 8037AE7C 00377A5C  38 63 23 68 */	addi r3, r3, lbl_804C2368@l
/* 8037AE80 00377A60  4E 80 00 20 */	blr 
/* 8037AE84 00377A64  3C 60 80 4C */	lis r3, lbl_804C2394@ha
/* 8037AE88 00377A68  38 63 23 94 */	addi r3, r3, lbl_804C2394@l
/* 8037AE8C 00377A6C  4E 80 00 20 */	blr 
}

asm HSD_ObjAllocData* HSD_RObjGetAllocData(void)
{
nofralloc
/* 8037AE78 00377A58  3C 60 80 4C */	lis r3, lbl_804C2368@ha
/* 8037AE7C 00377A5C  38 63 23 68 */	addi r3, r3, lbl_804C2368@l
/* 8037AE80 00377A60  4E 80 00 20 */	blr 
}

asm HSD_ObjAllocData* HSD_RvalueObjGetAllocData(void)
{
nofralloc
/* 8037AE84 00377A64  3C 60 80 4C */	lis r3, lbl_804C2394@ha
/* 8037AE88 00377A68  38 63 23 94 */	addi r3, r3, lbl_804C2394@l
/* 8037AE8C 00377A6C  4E 80 00 20 */	blr 
}

asm void HSD_RObjSetFlags(HSD_RObj* robj, u32 flags)
{
nofralloc
/* 8037AE90 00377A70  28 03 00 00 */	cmplwi r3, 0
/* 8037AE94 00377A74  4D 82 00 20 */	beqlr 
/* 8037AE98 00377A78  80 03 00 04 */	lwz r0, 4(r3)
/* 8037AE9C 00377A7C  7C 00 23 78 */	or r0, r0, r4
/* 8037AEA0 00377A80  90 03 00 04 */	stw r0, 4(r3)
/* 8037AEA4 00377A84  4E 80 00 20 */	blr 
}



#endif
