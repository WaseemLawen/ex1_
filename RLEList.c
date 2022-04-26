#include "RLEList.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct RLEList_t{
    char letter;
    int repeatition;
    struct RLEList_t* next;
    struct RLEList_t* last;
};


//implement the functions here

RLEList RLEListCreate(){
    RLEList ptr = malloc(sizeof(*ptr));
    if(!ptr){
        return NULL;    
    }
    ptr->letter = NULL;
    ptr->repeatition=NULL;
    ptr->next=NULL;
    ptr->last=ptr;
    return ptr;
}

void RLEListDestroy(RLEList list){
    while(list){
        RLEList toDelete = list;
        list = list -> next;
        free(toDelete);
    }

}

RLEListResult RLEListAppend(RLEList list, char value){
    if(!list || !value){
        return RLE_LIST_NULL_ARGUMENT;
    } 
    else{
        
    }    
}

//int RLEListSize(RLEList list);

//RLEListResult RLEListRemove(RLEList list, int index);

//char RLEListGet(RLEList list, int index, RLEListResult *result);

//char* RLEListExportToString(RLEList list, RLEListResult* result);

//RLEListResult RLEListMap(RLEList list, MapFunction map_function);


