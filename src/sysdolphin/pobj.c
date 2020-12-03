#include "pobj.h"



#ifndef USE_ASM_VERSION



u16 HSD_PObjGetFlags(HSD_PObj* pobj)
{
	if (pobj != NULL) 
	{
	return pobj->flags;
	}
	return 0;
}



#else   // ASM



asm u16 HSD_PObjGetFlags(HSD_PObj* pobj)
{
nofrealloc
/* 8036B8D0 003684B0  28 03 00 00 */	cmplwi r3, 0
/* 8036B8D4 003684B4  41 82 00 0C */	beq lbl_8036B8E0
/* 8036B8D8 003684B8  A0 63 00 0C */	lhz r3, 0xc(r3)
/* 8036B8DC 003684BC  4E 80 00 20 */	blr 
lbl_8036B8E0:
/* 8036B8E0 003684C0  38 60 00 00 */	li r3, 0
/* 8036B8E4 003684C4  4E 80 00 20 */	blr 
}



#endif
