#include "object.h"



extern HSD_ClassInfo lbl_804072A8;       // hsdObj
extern const char    lbl_804072E4[24];   // "sysdolphin_base_library\0"
extern HSD_ClassInfo lbl_80407590;       // hsdClass
extern       char    lbl_804D5F68[8];    // "hsd_obj\0"



#ifndef USE_ASM_VERSION



// Address: 8037E6C4 -> 8037E704
void ObjInfoInit(void)
{
	hsdInitClassInfo(&lbl_804072A8, &lbl_80407590, lbl_804072E4, lbl_804D5F68, sizeof(HSD_ObjInfo), sizeof(HSD_Obj));
}



#else



asm void ObjInfoInit(void)
{
nofrealloc
/* 8037E6C4 0037B2A4  7C 08 02 A6 */	mflr r0
/* 8037E6C8 0037B2A8  3C 60 80 40 */	lis r3, lbl_804072A8@ha
/* 8037E6CC 0037B2AC  90 01 00 04 */	stw r0, 4(r1)
/* 8037E6D0 0037B2B0  3C 80 80 40 */	lis r4, lbl_80407590@ha
/* 8037E6D4 0037B2B4  3C A0 80 40 */	lis r5, lbl_804072E4@ha
/* 8037E6D8 0037B2B8  94 21 FF F8 */	stwu r1, -8(r1)
/* 8037E6DC 0037B2BC  38 63 72 A8 */	addi r3, r3, lbl_804072A8@l
/* 8037E6E0 0037B2C0  38 84 75 90 */	addi r4, r4, lbl_80407590@l
/* 8037E6E4 0037B2C4  38 A5 72 E4 */	addi r5, r5, lbl_804072E4@l
/* 8037E6E8 0037B2C8  38 CD A8 C8 */	addi r6, r13, lbl_804D5F68-_SDA_BASE_
/* 8037E6EC 0037B2CC  38 E0 00 3C */	li r7, 0x3c
/* 8037E6F0 0037B2D0  39 00 00 08 */	li r8, 8
/* 8037E6F4 0037B2D4  48 00 35 25 */	bl func_80381C18
/* 8037E6F8 0037B2D8  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8037E6FC 0037B2DC  38 21 00 08 */	addi r1, r1, 8
/* 8037E700 0037B2E0  7C 08 03 A6 */	mtlr r0
/* 8037E704 0037B2E4  4E 80 00 20 */	blr 
}



#endif