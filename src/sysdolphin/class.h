#ifndef _class_h_
#define _class_h_



#include "global.h"



#define HSD_CLASS_INFO(o)   ((HSD_ClassInfo*)o)
#define HSD_CLASS_METHOD(o) (o->parent.class_info)
#define HSD_PARENT_INFO(o)  ((o)->parent.head.parent)



typedef struct _HSD_Class         HSD_Class;
typedef struct _HSD_ClassInfo     HSD_ClassInfo;
typedef struct _HSD_ClassInfoHead HSD_ClassInfoHead;
typedef struct _HSD_FreeList      HSD_FreeList;
typedef struct _HSD_MemoryEntry   HSD_MemoryEntry;



struct _HSD_Class 
{
	HSD_ClassInfo* class_info;
};

struct _HSD_ClassInfoHead 
{
	void (*info_init)();

	u32            flags;
	char*          library_name;
	char*          class_name;
	s16            obj_size;
	s16            info_size;
	HSD_ClassInfo* parent;
	HSD_ClassInfo* next;
	HSD_ClassInfo* child;
	u32            nb_exist;
	u32            nb_peak;
};


struct _HSD_ClassInfo 
{
	HSD_ClassInfoHead head;

	HSD_Class* (*alloc  )(struct _HSD_ClassInfo* c);
	void       (*init   )(struct _HSD_Class*     c);
	void       (*release)(struct _HSD_Class*     c);
	void       (*destroy)(struct _HSD_Class*     c);
	void       (*amnesia)(struct _HSD_ClassInfo* c);
};

struct _HSD_FreeList 
{
	HSD_FreeList* next;
};

typedef struct _HSD_MemoryEntry 
{
	u32              size;
	u32              nb_alloc;
	u32              nb_free;
	HSD_FreeList*    free_list;
	HSD_MemoryEntry* next;
};



#endif
