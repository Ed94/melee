#include "include/dolphin/types.h"



extern const void* lbl_80005918; //info
extern s32         lbl_804D5B40; //fragmentID

extern s32  __register_fragment(struct __eti_init_info*, char*);
extern void __unregister_fragment(s32);



#ifndef USE_ASM_VERSION



#ifdef NON_MATCHING
// Address  : 80322F20 - 80322F24?
extern char* GetR2(void)
{

}
#else
extern asm char* GetR2(void)
{
nofralloc
	mr r3, r2
	blr
}
#endif

// Address  : 80322F28 - 80322F58?
extern void __fini_cpp_exceptions(void)
{
	if (lbl_804D5B40 != -2) 
	{
		__unregister_fragment(lbl_804D5B40);

		lbl_804D5B40 = -2;
	}
}

#ifdef NON_MATCHING
extern void __init_cpp_exceptions(void)
{
	
}
#else
// Address  : 80322F5c - 803230A4?
// Left as asm due to lbl_80005918 being in extabindex, which throws an error about an incompatible section
extern asm void __init_cpp_exceptions(void)
{
nofralloc
/* 80322F5C 0031FB3C  7C 08 02 A6 */	mflr r0
/* 80322F60 0031FB40  90 01 00 04 */	stw r0, 4(r1)
/* 80322F64 0031FB44  94 21 FF F8 */	stwu r1, -8(r1)
/* 80322F68 0031FB48  80 0D A4 A0 */	lwz r0, lbl_804D5B40(r13)
/* 80322F6C 0031FB4C  2C 00 FF FE */	cmpwi r0, -2
/* 80322F70 0031FB50  40 82 00 1C */	bne lbl_80322F8C
/* 80322F74 0031FB54  4B FF FF AD */	bl GetR2
/* 80322F78 0031FB58  3C A0 80 00 */	lis r5, lbl_80005918@ha
/* 80322F7C 0031FB5C  7C 64 1B 78 */	mr r4, r3
/* 80322F80 0031FB60  38 65 59 18 */	addi r3, r5, lbl_80005918@l
/* 80322F84 0031FB64  4B FF F8 0D */	bl __register_fragment
/* 80322F88 0031FB68  90 6D A4 A0 */	stw r3, lbl_804D5B40(r13)
lbl_80322F8C:
/* 80322F8C 0031FB6C  80 01 00 0C */	lwz r0, 0xc(r1)
/* 80322F90 0031FB70  38 21 00 08 */	addi r1, r1, 8
/* 80322F94 0031FB74  7C 08 03 A6 */	mtlr r0
/* 80322F98 0031FB78  4E 80 00 20 */	blr 
}
#endif



#else   // ASM



extern asm void __fini_cpp_exceptions(void)
{
nofralloc
/* 80322F28 0031FB08  7C 08 02 A6 */	mflr r0
/* 80322F2C 0031FB0C  90 01 00 04 */	stw r0, 4(r1)
/* 80322F30 0031FB10  94 21 FF F8 */	stwu r1, -8(r1)
/* 80322F34 0031FB14  80 6D A4 A0 */	lwz r3, lbl_804D5B40-_SDA_BASE_(r13)
/* 80322F38 0031FB18  2C 03 FF FE */	cmpwi r3, -2
/* 80322F3C 0031FB1C  41 82 00 10 */	beq lbl_80322F4C
/* 80322F40 0031FB20  4B FF F8 1D */	bl func_8032275C
/* 80322F44 0031FB24  38 00 FF FE */	li r0, -2
/* 80322F48 0031FB28  90 0D A4 A0 */	stw r0, lbl_804D5B40-_SDA_BASE_(r13)
lbl_80322F4C:
/* 80322F4C 0031FB2C  80 01 00 0C */	lwz r0, 0xc(r1)
/* 80322F50 0031FB30  38 21 00 08 */	addi r1, r1, 8
/* 80322F54 0031FB34  7C 08 03 A6 */	mtlr r0
/* 80322F58 0031FB38  4E 80 00 20 */	blr 
}



#endif