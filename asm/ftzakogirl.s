.include "macros.inc"

.section .text  # 0x80005940 - 0x803B7240

.global func_8014F418
func_8014F418:
/* 8014F418 0014BFF8  7C 08 02 A6 */	mflr r0
/* 8014F41C 0014BFFC  38 80 00 00 */	li r4, 0
/* 8014F420 0014C000  90 01 00 04 */	stw r0, 4(r1)
/* 8014F424 0014C004  38 A0 00 00 */	li r5, 0
/* 8014F428 0014C008  94 21 FF F8 */	stwu r1, -8(r1)
/* 8014F42C 0014C00C  4B F2 56 21 */	bl func_80074A4C
/* 8014F430 0014C010  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8014F434 0014C014  38 21 00 08 */	addi r1, r1, 8
/* 8014F438 0014C018  7C 08 03 A6 */	mtlr r0
/* 8014F43C 0014C01C  4E 80 00 20 */	blr 

.global func_8014F440
func_8014F440:
/* 8014F440 0014C020  80 A3 00 2C */	lwz r5, 0x2c(r3)
/* 8014F444 0014C024  80 65 01 0C */	lwz r3, 0x10c(r5)
/* 8014F448 0014C028  80 85 02 D8 */	lwz r4, 0x2d8(r5)
/* 8014F44C 0014C02C  80 63 00 04 */	lwz r3, 4(r3)
/* 8014F450 0014C030  80 03 00 00 */	lwz r0, 0(r3)
/* 8014F454 0014C034  90 04 00 00 */	stw r0, 0(r4)
/* 8014F458 0014C038  90 85 02 D4 */	stw r4, 0x2d4(r5)
/* 8014F45C 0014C03C  4E 80 00 20 */	blr 

.global func_8014F460
func_8014F460:
/* 8014F460 0014C040  7C 08 02 A6 */	mflr r0
/* 8014F464 0014C044  90 01 00 04 */	stw r0, 4(r1)
/* 8014F468 0014C048  94 21 FF D8 */	stwu r1, -0x28(r1)
/* 8014F46C 0014C04C  93 E1 00 24 */	stw r31, 0x24(r1)
/* 8014F470 0014C050  93 C1 00 20 */	stw r30, 0x20(r1)
/* 8014F474 0014C054  7C 9E 23 78 */	mr r30, r4
/* 8014F478 0014C058  93 A1 00 1C */	stw r29, 0x1c(r1)
/* 8014F47C 0014C05C  7C 7D 1B 78 */	mr r29, r3
/* 8014F480 0014C060  83 E3 00 2C */	lwz r31, 0x2c(r3)
/* 8014F484 0014C064  80 7F 19 74 */	lwz r3, 0x1974(r31)
/* 8014F488 0014C068  48 11 BE 2D */	bl func_8026B2B4
/* 8014F48C 0014C06C  2C 03 00 00 */	cmpwi r3, 0
/* 8014F490 0014C070  40 82 00 94 */	bne lbl_8014F524
/* 8014F494 0014C074  80 7F 19 74 */	lwz r3, 0x1974(r31)
/* 8014F498 0014C078  48 11 BE 89 */	bl func_8026B320
/* 8014F49C 0014C07C  2C 03 00 03 */	cmpwi r3, 3
/* 8014F4A0 0014C080  41 82 00 4C */	beq lbl_8014F4EC
/* 8014F4A4 0014C084  40 80 00 14 */	bge lbl_8014F4B8
/* 8014F4A8 0014C088  2C 03 00 01 */	cmpwi r3, 1
/* 8014F4AC 0014C08C  41 82 00 18 */	beq lbl_8014F4C4
/* 8014F4B0 0014C090  40 80 00 28 */	bge lbl_8014F4D8
/* 8014F4B4 0014C094  48 00 00 5C */	b lbl_8014F510
lbl_8014F4B8:
/* 8014F4B8 0014C098  2C 03 00 05 */	cmpwi r3, 5
/* 8014F4BC 0014C09C  40 80 00 54 */	bge lbl_8014F510
/* 8014F4C0 0014C0A0  48 00 00 40 */	b lbl_8014F500
lbl_8014F4C4:
/* 8014F4C4 0014C0A4  38 7D 00 00 */	addi r3, r29, 0
/* 8014F4C8 0014C0A8  38 80 00 00 */	li r4, 0
/* 8014F4CC 0014C0AC  38 A0 00 01 */	li r5, 1
/* 8014F4D0 0014C0B0  4B F2 1A E5 */	bl func_80070FB4
/* 8014F4D4 0014C0B4  48 00 00 3C */	b lbl_8014F510
lbl_8014F4D8:
/* 8014F4D8 0014C0B8  38 7D 00 00 */	addi r3, r29, 0
/* 8014F4DC 0014C0BC  38 80 00 00 */	li r4, 0
/* 8014F4E0 0014C0C0  38 A0 00 00 */	li r5, 0
/* 8014F4E4 0014C0C4  4B F2 1A D1 */	bl func_80070FB4
/* 8014F4E8 0014C0C8  48 00 00 28 */	b lbl_8014F510
lbl_8014F4EC:
/* 8014F4EC 0014C0CC  38 7D 00 00 */	addi r3, r29, 0
/* 8014F4F0 0014C0D0  38 80 00 00 */	li r4, 0
/* 8014F4F4 0014C0D4  38 A0 00 02 */	li r5, 2
/* 8014F4F8 0014C0D8  4B F2 1A BD */	bl func_80070FB4
/* 8014F4FC 0014C0DC  48 00 00 14 */	b lbl_8014F510
lbl_8014F500:
/* 8014F500 0014C0E0  38 7D 00 00 */	addi r3, r29, 0
/* 8014F504 0014C0E4  38 80 00 00 */	li r4, 0
/* 8014F508 0014C0E8  38 A0 00 03 */	li r5, 3
/* 8014F50C 0014C0EC  4B F2 1A A9 */	bl func_80070FB4
lbl_8014F510:
/* 8014F510 0014C0F0  2C 1E 00 00 */	cmpwi r30, 0
/* 8014F514 0014C0F4  41 82 00 10 */	beq lbl_8014F524
/* 8014F518 0014C0F8  38 7D 00 00 */	addi r3, r29, 0
/* 8014F51C 0014C0FC  38 80 00 00 */	li r4, 0
/* 8014F520 0014C100  4B F2 17 29 */	bl func_80070C48
lbl_8014F524:
/* 8014F524 0014C104  80 01 00 2C */	lwz r0, 0x2c(r1)
/* 8014F528 0014C108  83 E1 00 24 */	lwz r31, 0x24(r1)
/* 8014F52C 0014C10C  83 C1 00 20 */	lwz r30, 0x20(r1)
/* 8014F530 0014C110  83 A1 00 1C */	lwz r29, 0x1c(r1)
/* 8014F534 0014C114  38 21 00 28 */	addi r1, r1, 0x28
/* 8014F538 0014C118  7C 08 03 A6 */	mtlr r0
/* 8014F53C 0014C11C  4E 80 00 20 */	blr 
/* 8014F540 0014C120  7C 08 02 A6 */	mflr r0
/* 8014F544 0014C124  90 01 00 04 */	stw r0, 4(r1)
/* 8014F548 0014C128  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 8014F54C 0014C12C  93 E1 00 14 */	stw r31, 0x14(r1)
/* 8014F550 0014C130  7C 7F 1B 78 */	mr r31, r3
/* 8014F554 0014C134  80 63 00 2C */	lwz r3, 0x2c(r3)
/* 8014F558 0014C138  80 63 19 74 */	lwz r3, 0x1974(r3)
/* 8014F55C 0014C13C  48 11 BD 59 */	bl func_8026B2B4
/* 8014F560 0014C140  2C 03 00 00 */	cmpwi r3, 0
/* 8014F564 0014C144  40 82 00 10 */	bne lbl_8014F574
/* 8014F568 0014C148  38 7F 00 00 */	addi r3, r31, 0
/* 8014F56C 0014C14C  38 80 00 00 */	li r4, 0
/* 8014F570 0014C150  4B F2 17 55 */	bl func_80070CC4
lbl_8014F574:
/* 8014F574 0014C154  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 8014F578 0014C158  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 8014F57C 0014C15C  38 21 00 18 */	addi r1, r1, 0x18
/* 8014F580 0014C160  7C 08 03 A6 */	mtlr r0
/* 8014F584 0014C164  4E 80 00 20 */	blr 
/* 8014F588 0014C168  7C 08 02 A6 */	mflr r0
/* 8014F58C 0014C16C  90 01 00 04 */	stw r0, 4(r1)
/* 8014F590 0014C170  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 8014F594 0014C174  93 E1 00 14 */	stw r31, 0x14(r1)
/* 8014F598 0014C178  7C 7F 1B 78 */	mr r31, r3
/* 8014F59C 0014C17C  80 63 00 2C */	lwz r3, 0x2c(r3)
/* 8014F5A0 0014C180  80 63 19 74 */	lwz r3, 0x1974(r3)
/* 8014F5A4 0014C184  48 11 BD 11 */	bl func_8026B2B4
/* 8014F5A8 0014C188  2C 03 00 00 */	cmpwi r3, 0
/* 8014F5AC 0014C18C  40 82 00 10 */	bne lbl_8014F5BC
/* 8014F5B0 0014C190  38 7F 00 00 */	addi r3, r31, 0
/* 8014F5B4 0014C194  38 80 00 00 */	li r4, 0
/* 8014F5B8 0014C198  4B F2 16 91 */	bl func_80070C48
lbl_8014F5BC:
/* 8014F5BC 0014C19C  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 8014F5C0 0014C1A0  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 8014F5C4 0014C1A4  38 21 00 18 */	addi r1, r1, 0x18
/* 8014F5C8 0014C1A8  7C 08 03 A6 */	mtlr r0
/* 8014F5CC 0014C1AC  4E 80 00 20 */	blr 
/* 8014F5D0 0014C1B0  7C 08 02 A6 */	mflr r0
/* 8014F5D4 0014C1B4  38 A0 FF FF */	li r5, -1
/* 8014F5D8 0014C1B8  90 01 00 04 */	stw r0, 4(r1)
/* 8014F5DC 0014C1BC  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 8014F5E0 0014C1C0  93 E1 00 14 */	stw r31, 0x14(r1)
/* 8014F5E4 0014C1C4  3B E4 00 00 */	addi r31, r4, 0
/* 8014F5E8 0014C1C8  38 80 00 00 */	li r4, 0
/* 8014F5EC 0014C1CC  93 C1 00 10 */	stw r30, 0x10(r1)
/* 8014F5F0 0014C1D0  3B C3 00 00 */	addi r30, r3, 0
/* 8014F5F4 0014C1D4  4B F2 19 C1 */	bl func_80070FB4
/* 8014F5F8 0014C1D8  2C 1F 00 00 */	cmpwi r31, 0
/* 8014F5FC 0014C1DC  41 82 00 10 */	beq lbl_8014F60C
/* 8014F600 0014C1E0  38 7E 00 00 */	addi r3, r30, 0
/* 8014F604 0014C1E4  38 80 00 00 */	li r4, 0
/* 8014F608 0014C1E8  4B F2 16 BD */	bl func_80070CC4
lbl_8014F60C:
/* 8014F60C 0014C1EC  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 8014F610 0014C1F0  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 8014F614 0014C1F4  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 8014F618 0014C1F8  38 21 00 18 */	addi r1, r1, 0x18
/* 8014F61C 0014C1FC  7C 08 03 A6 */	mtlr r0
/* 8014F620 0014C200  4E 80 00 20 */	blr 
/* 8014F624 0014C204  80 63 00 2C */	lwz r3, 0x2c(r3)
/* 8014F628 0014C208  80 83 01 0C */	lwz r4, 0x10c(r3)
/* 8014F62C 0014C20C  80 63 02 D4 */	lwz r3, 0x2d4(r3)
/* 8014F630 0014C210  80 84 00 04 */	lwz r4, 4(r4)
/* 8014F634 0014C214  80 04 00 00 */	lwz r0, 0(r4)
/* 8014F638 0014C218  90 03 00 00 */	stw r0, 0(r3)
/* 8014F63C 0014C21C  4E 80 00 20 */	blr 
