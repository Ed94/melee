#include "wobj.h"



#ifndef USE_ASM_VERSION




void HSD_WObjRemoveAnim(HSD_WObj* wobj)
{
	if (wobj != NULL)
	{
		HSD_AObjRemove(wobj->aobj);

		wobj->aobj = NULL;

		HSD_RObjRemoveAnimAll(wobj->robj);
	}
}

void HSD_WObjReqAnim(HSD_WObj* wobj, f32 frame)
{
	if (wobj != NULL)
	{
		HSD_AObjReqAnim   (wobj->aobj, frame);
		HSD_RObjReqAnimAll(wobj->robj, frame);
	}
}



#else   // ASM



asm void HSD_WObjRemoveAnim(HSD_WObj* wobj)
{
nofralloc
/* 8037D050 00379C30  7C 08 02 A6 */	mflr r0
/* 8037D054 00379C34  90 01 00 04 */	stw r0, 4(r1)
/* 8037D058 00379C38  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 8037D05C 00379C3C  93 E1 00 14 */	stw r31, 0x14(r1)
/* 8037D060 00379C40  7C 7F 1B 79 */	or. r31, r3, r3
/* 8037D064 00379C44  41 82 00 1C */	beq lbl_8037D080
/* 8037D068 00379C48  80 7F 00 18 */	lwz r3, 0x18(r31)
/* 8037D06C 00379C4C  4B FE 74 61 */	bl func_803644CC
/* 8037D070 00379C50  38 00 00 00 */	li r0, 0
/* 8037D074 00379C54  90 1F 00 18 */	stw r0, 0x18(r31)
/* 8037D078 00379C58  80 7F 00 1C */	lwz r3, 0x1c(r31)
/* 8037D07C 00379C5C  4B FF DF C9 */	bl func_8037B044
lbl_8037D080:
/* 8037D080 00379C60  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 8037D084 00379C64  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 8037D088 00379C68  38 21 00 18 */	addi r1, r1, 0x18
/* 8037D08C 00379C6C  7C 08 03 A6 */	mtlr r0
/* 8037D090 00379C70  4E 80 00 20 */	blr 
}

asm void HSD_WObjReqAnim(HSD_WObj* wobj, f32 frame)
{
nofralloc
/* 8037D094 00379C74  7C 08 02 A6 */	mflr r0
/* 8037D098 00379C78  90 01 00 04 */	stw r0, 4(r1)
/* 8037D09C 00379C7C  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8037D0A0 00379C80  DB E1 00 18 */	stfd f31, 0x18(r1)
/* 8037D0A4 00379C84  FF E0 08 90 */	fmr f31, f1
/* 8037D0A8 00379C88  93 E1 00 14 */	stw r31, 0x14(r1)
/* 8037D0AC 00379C8C  7C 7F 1B 79 */	or. r31, r3, r3
/* 8037D0B0 00379C90  41 82 00 1C */	beq lbl_8037D0CC
/* 8037D0B4 00379C94  80 7F 00 18 */	lwz r3, 0x18(r31)
/* 8037D0B8 00379C98  FC 20 F8 90 */	fmr f1, f31
/* 8037D0BC 00379C9C  4B FE 70 51 */	bl func_8036410C
/* 8037D0C0 00379CA0  80 7F 00 1C */	lwz r3, 0x1c(r31)
/* 8037D0C4 00379CA4  FC 20 F8 90 */	fmr f1, f31
/* 8037D0C8 00379CA8  4B FF E0 6D */	bl func_8037B134
lbl_8037D0CC:
/* 8037D0CC 00379CAC  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8037D0D0 00379CB0  CB E1 00 18 */	lfd f31, 0x18(r1)
/* 8037D0D4 00379CB4  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 8037D0D8 00379CB8  38 21 00 20 */	addi r1, r1, 0x20
/* 8037D0DC 00379CBC  7C 08 03 A6 */	mtlr r0
/* 8037D0E0 00379CC0  4E 80 00 20 */	blr 
}



#endif