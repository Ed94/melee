// Parent Header
#include "displayfunc.h"



extern HSD_ObjAllocData lbl_804C0918;



typedef struct _HSD_ZList_SortType HSD_ZList_SortType;
typedef struct _HSD_ZList          HSD_ZList;



struct _HSD_ZList_SortType
{
	HSD_ZList* texedge;
	HSD_ZList* xlu;
};

struct _HSD_ZList 
{
	Mtx       pmtx;
	MtxPtr    vmtx;
	HSD_JObj* jobj;
	u32       rendermode;

	HSD_ZList_SortType sort;
	HSD_ZList*         next;
};



#ifndef USE_ASM_VERSION



void HSD_ZListInitAllocData(void)
{
	HSD_ObjAllocInit(&lbl_804C0918, sizeof(HSD_ZList), 4);
}



#else   // ASM

asm void HSD_ZListInitAllocData(void)
{
nofrealloc
/* 803738A0 00370480  7C 08 02 A6 */	mflr r0
/* 803738A4 00370484  3C 60 80 4C */	lis r3, lbl_804C0918@ha
/* 803738A8 00370488  90 01 00 04 */	stw r0, 4(r1)
/* 803738AC 0037048C  38 63 09 18 */	addi r3, r3, lbl_804C0918@l
/* 803738B0 00370490  38 80 00 48 */	li r4, 0x48
/* 803738B4 00370494  94 21 FF F8 */	stwu r1, -8(r1)
/* 803738B8 00370498  38 A0 00 04 */	li r5, 4
/* 803738BC 0037049C  48 00 74 8D */	bl func_8037AD48
/* 803738C0 003704A0  80 01 00 0C */	lwz r0, 0xc(r1)
/* 803738C4 003704A4  38 21 00 08 */	addi r1, r1, 8
/* 803738C8 003704A8  7C 08 03 A6 */	mtlr r0
/* 803738CC 003704AC  4E 80 00 20 */	blr 
}


#endif 
