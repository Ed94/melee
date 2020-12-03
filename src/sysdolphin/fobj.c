// Parent Header
#include "fobj.h"



extern HSD_ObjAllocData lbl_804C08D8;



#ifndef USE_ASM_VERSION



HSD_ObjAllocData* HSD_FObjGetAllocData(void)
{
	return &lbl_804C08D8;
}

void HSD_FObjInitAllocData(void)
{
	HSD_ObjAllocInit(&lbl_804C08D8, sizeof(HSD_FObj), 4);
}

void HSD_FObjRemove(HSD_FObj* fobj)
{
	if (!fobj)
		return;

	HSD_FObjFree(fobj);
}

inline HSD_FObj* HSD_FObjGetNext(HSD_FObj *fobj) 
{
	return fobj->next;
}

inline void *HSD_FObjRemoveAll_Inlined(HSD_FObj *fobj) 
{
	if (!fobj)
	return;

	HSD_FObjRemoveAll(fobj->next);
	HSD_FObjRemove(fobj);
}

void HSD_FObjRemoveAll(HSD_FObj* fobj)
{
	HSD_FObj* t1;
	HSD_FObj* t2;
	HSD_FObj* t3;

	if (fobj)
	{
		t3 = HSD_FObjGetNext(fobj);

		if (t3)
		{
			t2 = HSD_FObjGetNext(t3);
			
			if (t2)
			{
				HSD_FObjRemoveAll_Inlined(t2->next);
				if (t2) 
				{
					HSD_FObjFree(t2);
				}
			}
			if (t3) 
			{
				HSD_FObjFree(t3);
			}
		}
		if (fobj) 
		{
			HSD_FObjFree(fobj);
		}
	}
}

u8 HSD_FObjSetState(HSD_FObj* fobj, u8 state)
{
	if (fobj)
		fobj->flags = (state & 0xF) | (fobj->flags & 0xF0);

	return state;
}

u32 HSD_FObjGetState(HSD_FObj* fobj)
{
	if (!fobj)
		return 0;

	return fobj->flags & 0xF;
}



#else   // ASM



asm HSD_ObjAllocData* HSD_FObjGetAllocData(void)
{
nofrealloc
/* 8036A938 00367518  3C 60 80 4C */	lis r3, lbl_804C08D8@ha
/* 8036A93C 0036751C  38 63 08 D8 */	addi r3, r3, lbl_804C08D8@l
/* 8036A940 00367520  4E 80 00 20 */	blr 
}

asm void HSD_FObjInitAllocData(void)
{
nofrealloc
/* 8036A944 00367524  7C 08 02 A6 */	mflr r0
/* 8036A948 00367528  3C 60 80 4C */	lis r3, lbl_804C08D8@ha
/* 8036A94C 0036752C  90 01 00 04 */	stw r0, 4(r1)
/* 8036A950 00367530  38 63 08 D8 */	addi r3, r3, lbl_804C08D8@l
/* 8036A954 00367534  38 80 00 30 */	li r4, 0x30
/* 8036A958 00367538  94 21 FF F8 */	stwu r1, -8(r1)
/* 8036A95C 0036753C  38 A0 00 04 */	li r5, 4
/* 8036A960 00367540  48 01 03 E9 */	bl func_8037AD48
/* 8036A964 00367544  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8036A968 00367548  38 21 00 08 */	addi r1, r1, 8
/* 8036A96C 0036754C  7C 08 03 A6 */	mtlr r0
/* 8036A970 00367550  4E 80 00 20 */	blr 
}

asm void HSD_FObjRemove(HSD_FObj* fobj)
{
nofrealloc
/* 8036A974 00367554  7C 08 02 A6 */	mflr r0
/* 8036A978 00367558  28 03 00 00 */	cmplwi r3, 0
/* 8036A97C 0036755C  90 01 00 04 */	stw r0, 4(r1)
/* 8036A980 00367560  94 21 FF F8 */	stwu r1, -8(r1)
/* 8036A984 00367564  41 82 00 08 */	beq lbl_8036A98C
/* 8036A988 00367568  48 00 0F 1D */	bl func_8036B8A4
lbl_8036A98C:
/* 8036A98C 0036756C  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8036A990 00367570  38 21 00 08 */	addi r1, r1, 8
/* 8036A994 00367574  7C 08 03 A6 */	mtlr r0
/* 8036A998 00367578  4E 80 00 20 */	blr 
}

asm void HSD_FObjRemoveAll(HSD_FObj* fobj)
{
nofrealloc
/* 8036A99C 0036757C  7C 08 02 A6 */	mflr r0
/* 8036A9A0 00367580  90 01 00 04 */	stw r0, 4(r1)
/* 8036A9A4 00367584  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8036A9A8 00367588  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8036A9AC 0036758C  93 C1 00 18 */	stw r30, 0x18(r1)
/* 8036A9B0 00367590  93 A1 00 14 */	stw r29, 0x14(r1)
/* 8036A9B4 00367594  93 81 00 10 */	stw r28, 0x10(r1)
/* 8036A9B8 00367598  7C 7C 1B 79 */	or. r28, r3, r3
/* 8036A9BC 0036759C  41 82 00 68 */	beq lbl_8036AA24
/* 8036A9C0 003675A0  83 FC 00 00 */	lwz r31, 0(r28)
/* 8036A9C4 003675A4  28 1F 00 00 */	cmplwi r31, 0
/* 8036A9C8 003675A8  41 82 00 4C */	beq lbl_8036AA14
/* 8036A9CC 003675AC  83 DF 00 00 */	lwz r30, 0(r31)
/* 8036A9D0 003675B0  28 1E 00 00 */	cmplwi r30, 0
/* 8036A9D4 003675B4  41 82 00 30 */	beq lbl_8036AA04
/* 8036A9D8 003675B8  83 BE 00 00 */	lwz r29, 0(r30)
/* 8036A9DC 003675BC  28 1D 00 00 */	cmplwi r29, 0
/* 8036A9E0 003675C0  41 82 00 14 */	beq lbl_8036A9F4
/* 8036A9E4 003675C4  80 7D 00 00 */	lwz r3, 0(r29)
/* 8036A9E8 003675C8  4B FF FF B5 */	bl func_8036A99C
/* 8036A9EC 003675CC  7F A3 EB 78 */	mr r3, r29
/* 8036A9F0 003675D0  4B FF FF 85 */	bl func_8036A974
lbl_8036A9F4:
/* 8036A9F4 003675D4  28 1E 00 00 */	cmplwi r30, 0
/* 8036A9F8 003675D8  41 82 00 0C */	beq lbl_8036AA04
/* 8036A9FC 003675DC  7F C3 F3 78 */	mr r3, r30
/* 8036AA00 003675E0  48 00 0E A5 */	bl func_8036B8A4
lbl_8036AA04:
/* 8036AA04 003675E4  28 1F 00 00 */	cmplwi r31, 0
/* 8036AA08 003675E8  41 82 00 0C */	beq lbl_8036AA14
/* 8036AA0C 003675EC  7F E3 FB 78 */	mr r3, r31
/* 8036AA10 003675F0  48 00 0E 95 */	bl func_8036B8A4
lbl_8036AA14:
/* 8036AA14 003675F4  28 1C 00 00 */	cmplwi r28, 0
/* 8036AA18 003675F8  41 82 00 0C */	beq lbl_8036AA24
/* 8036AA1C 003675FC  7F 83 E3 78 */	mr r3, r28
/* 8036AA20 00367600  48 00 0E 85 */	bl func_8036B8A4
lbl_8036AA24:
/* 8036AA24 00367604  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8036AA28 00367608  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8036AA2C 0036760C  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 8036AA30 00367610  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 8036AA34 00367614  83 81 00 10 */	lwz r28, 0x10(r1)
/* 8036AA38 00367618  38 21 00 20 */	addi r1, r1, 0x20
/* 8036AA3C 0036761C  7C 08 03 A6 */	mtlr r0
/* 8036AA40 00367620  4E 80 00 20 */	blr 
}

asm u8 HSD_FObjSetState(HSD_FObj* fobj, u8 state)
{
nofrealloc
/* 8036AA44 00367624  28 03 00 00 */	cmplwi r3, 0
/* 8036AA48 00367628  41 82 00 14 */	beq lbl_8036AA5C
/* 8036AA4C 0036762C  88 03 00 10 */	lbz r0, 0x10(r3)
/* 8036AA50 00367630  54 00 06 36 */	rlwinm r0, r0, 0, 0x18, 0x1b
/* 8036AA54 00367634  50 80 07 3E */	rlwimi r0, r4, 0, 0x1c, 0x1f
/* 8036AA58 00367638  98 03 00 10 */	stb r0, 0x10(r3)
lbl_8036AA5C:
/* 8036AA5C 0036763C  7C 83 23 78 */	mr r3, r4
/* 8036AA60 00367640  4E 80 00 20 */	blr 
}

asm u32 HSD_FObjGetState(HSD_FObj* fobj)
{
nofrealloc
/* 8036AA64 00367644  28 03 00 00 */	cmplwi r3, 0
/* 8036AA68 00367648  40 82 00 0C */	bne lbl_8036AA74
/* 8036AA6C 0036764C  38 60 00 00 */	li r3, 0
/* 8036AA70 00367650  4E 80 00 20 */	blr 
lbl_8036AA74:
/* 8036AA74 00367654  88 03 00 10 */	lbz r0, 0x10(r3)
/* 8036AA78 00367658  54 03 07 3E */	clrlwi r3, r0, 0x1c
/* 8036AA7C 0036765C  4E 80 00 20 */	blr 
}



#endif
