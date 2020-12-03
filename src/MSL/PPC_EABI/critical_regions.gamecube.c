
#ifndef USE_ASM_VERSION



// Address  : 8032355c
extern void __kill_critical_regions(void)
{
	return;
}



#else   // ASM



asm extern void __kill_critical_regions(void)
{
nofrealloc
/* 8032355C 0032013C  4E 80 00 20 */	blr 
}



#endif
