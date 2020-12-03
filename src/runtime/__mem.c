// Parent Header
#include "__mem.h"



#ifndef USE_ASM_VERSION



void* memset(void* dst, int val, unsigned long /*size_t*/ n)
{
	__fill_mem(dst, val, n);
	
	return(dst);
}

void __fill_mem(void * dst, int val, unsigned long n)
{
	unsigned long			v = (unsigned char) val;
	unsigned long			i;
	
	((unsigned char *) dst) = ((unsigned char *) dst) - 1;
	
	if (n >= 32)
	{
		i = (~ (unsigned long) dst) & 3;

		if (i) 
		{
			n -= i;
			
			do
			{
				*++(((unsigned char *) dst)) = v;
			} 
			while (--i);
		}
	
		if (v)
			v |= v << 24 | v << 16 | v <<  8;
		
		((unsigned long *) dst) = ((unsigned long *) (((unsigned char *) dst) + 1)) - 1;
		
		i = n >> 5;
		
		if (i)
		{
			do
			{
				*++((unsigned long *) dst) = v;
				*++((unsigned long *) dst) = v;
				*++((unsigned long *) dst) = v;
				*++((unsigned long *) dst) = v;
				*++((unsigned long *) dst) = v;
				*++((unsigned long *) dst) = v;
				*++((unsigned long *) dst) = v;
				*++((unsigned long *) dst) = v;
			}
			while (--i);
		}
		
		i = (n & 31) >> 2;
		
		if (i) 
		{
			do 
			{
				*++((unsigned long *) dst) = v;
			}
			while (--i);
		}
		
		((unsigned char *) dst) = ((unsigned char *) (((unsigned long *) dst) + 1)) - 1;
		
		n &= 3;
	}
	
	if (n)
	{
		do 
		{
			*++((unsigned char *) dst) = v;
		}
		while (--n);
	}
	
	return;
}



#else   // ASM



asm void* memset(void* dst, int val, unsigned long /*size_t*/ n)
{
nofralloc
/* 80003100 00000100  7C 08 02 A6 */	mflr r0
/* 80003104 00000104  90 01 00 04 */	stw r0, 4(r1)
/* 80003108 00000108  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8000310C 0000010C  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 80003110 00000110  7C 7F 1B 78 */	mr r31, r3
/* 80003114 00000114  48 00 00 1D */	bl func_80003130
/* 80003118 00000118  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8000311C 0000011C  7F E3 FB 78 */	mr r3, r31
/* 80003120 00000120  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 80003124 00000124  38 21 00 20 */	addi r1, r1, 0x20
/* 80003128 00000128  7C 08 03 A6 */	mtlr r0
/* 8000312C 0000012C  4E 80 00 20 */	blr 
}

asm void __fill_mem(void * dst, int val, unsigned long n)
{
nofralloc
/* 80003130 00000130  28 05 00 20 */	cmplwi r5, 0x20
/* 80003134 00000134  54 80 06 3E */	clrlwi r0, r4, 0x18
/* 80003138 00000138  7C 07 03 78 */	mr r7, r0
/* 8000313C 0000013C  38 C3 FF FF */	addi r6, r3, -1
/* 80003140 00000140  41 80 00 98 */	blt lbl_800031D8
/* 80003144 00000144  7C C0 30 F8 */	nor r0, r6, r6
/* 80003148 00000148  54 00 07 BF */	clrlwi. r0, r0, 0x1e
/* 8000314C 0000014C  7C 03 03 78 */	mr r3, r0
/* 80003150 00000150  41 82 00 18 */	beq lbl_80003168
/* 80003154 00000154  7C A3 28 50 */	subf r5, r3, r5
/* 80003158 00000158  54 E0 06 3E */	clrlwi r0, r7, 0x18
lbl_8000315C:
/* 8000315C 0000015C  34 63 FF FF */	addic. r3, r3, -1
/* 80003160 00000160  9C 06 00 01 */	stbu r0, 1(r6)
/* 80003164 00000164  40 82 FF F8 */	bne lbl_8000315C
lbl_80003168:
/* 80003168 00000168  28 07 00 00 */	cmplwi r7, 0
/* 8000316C 0000016C  41 82 00 1C */	beq lbl_80003188
/* 80003170 00000170  54 E3 C0 0E */	slwi r3, r7, 0x18
/* 80003174 00000174  54 E0 80 1E */	slwi r0, r7, 0x10
/* 80003178 00000178  54 E4 40 2E */	slwi r4, r7, 8
/* 8000317C 0000017C  7C 60 03 78 */	or r0, r3, r0
/* 80003180 00000180  7C 80 03 78 */	or r0, r4, r0
/* 80003184 00000184  7C E7 03 78 */	or r7, r7, r0
lbl_80003188:
/* 80003188 00000188  54 A0 D9 7F */	rlwinm. r0, r5, 0x1b, 5, 0x1f
/* 8000318C 0000018C  38 66 FF FD */	addi r3, r6, -3
/* 80003190 00000190  41 82 00 2C */	beq lbl_800031BC
lbl_80003194:
/* 80003194 00000194  90 E3 00 04 */	stw r7, 4(r3)
/* 80003198 00000198  34 00 FF FF */	addic. r0, r0, -1
/* 8000319C 0000019C  90 E3 00 08 */	stw r7, 8(r3)
/* 800031A0 000001A0  90 E3 00 0C */	stw r7, 0xc(r3)
/* 800031A4 000001A4  90 E3 00 10 */	stw r7, 0x10(r3)
/* 800031A8 000001A8  90 E3 00 14 */	stw r7, 0x14(r3)
/* 800031AC 000001AC  90 E3 00 18 */	stw r7, 0x18(r3)
/* 800031B0 000001B0  90 E3 00 1C */	stw r7, 0x1c(r3)
/* 800031B4 000001B4  94 E3 00 20 */	stwu r7, 0x20(r3)
/* 800031B8 000001B8  40 82 FF DC */	bne lbl_80003194
lbl_800031BC:
/* 800031BC 000001BC  54 A0 F7 7F */	rlwinm. r0, r5, 0x1e, 0x1d, 0x1f
/* 800031C0 000001C0  41 82 00 10 */	beq lbl_800031D0
lbl_800031C4:
/* 800031C4 000001C4  34 00 FF FF */	addic. r0, r0, -1
/* 800031C8 000001C8  94 E3 00 04 */	stwu r7, 4(r3)
/* 800031CC 000001CC  40 82 FF F8 */	bne lbl_800031C4
lbl_800031D0:
/* 800031D0 000001D0  38 C3 00 03 */	addi r6, r3, 3
/* 800031D4 000001D4  54 A5 07 BE */	clrlwi r5, r5, 0x1e
lbl_800031D8:
/* 800031D8 000001D8  28 05 00 00 */	cmplwi r5, 0
/* 800031DC 000001DC  4D 82 00 20 */	beqlr 
/* 800031E0 000001E0  54 E0 06 3E */	clrlwi r0, r7, 0x18
lbl_800031E4:
/* 800031E4 000001E4  34 A5 FF FF */	addic. r5, r5, -1
/* 800031E8 000001E8  9C 06 00 01 */	stbu r0, 1(r6)
/* 800031EC 000001EC  40 82 FF F8 */	bne lbl_800031E4
/* 800031F0 000001F0  4E 80 00 20 */	blr 
}



#endif