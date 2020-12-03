#ifndef _id_h_
#define _id_h_



#include "global.h"

#include "objalloc.h"



#define hash(s) (s % 0x65)



typedef struct _IDEntry     IDEntry;
typedef struct _HSD_IDTable HSD_IDTable;



struct _IDEntry 
{
	IDEntry* next;
	u32      id;
	void*    data;
};

struct _HSD_IDTable 
{
	IDEntry table[101];
};



// Address: 8037CD80 - 8037CD88
HSD_ObjAllocData* HSD_IDGetAllocData(void);

// Address: 8037CD8C - 8037CDB8
void HSD_IDInitAllocData(void);

// Address: 8037CDBC - 8037CDE8
void HSD_IDSetup(void);

// Address: 8037CDEC - 8037CEE4
void HSD_IDInsertToTable(HSD_IDTable* table, u32 id, void* data);

// Address: 8037CEE8 - 8037CF94
void HSD_IDRemoveByIDFromTable(HSD_IDTable* table, u32 id);

// Address: 8037CF98 - 8037D01C
void* HSD_IDGetDataFromTable(HSD_IDTable* table, u32 id, s32* success);

// Address: 8037D020 - 8037D04C
void _HSD_IDForgetMemory(void);



#endif
