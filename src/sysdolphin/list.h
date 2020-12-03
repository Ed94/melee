#ifndef _list_h_
#define _list_h_



typedef struct _HSD_SList HSD_SList;



struct _HSD_SList 
{
    HSD_SList* next;
    void*      data;
};



#endif
