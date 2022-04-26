#include "RLEList.h"
#include <string.h>

struct RLEList_t{
    char letter;
    int repeatition;
    struct RLEList_t* next;
};


//implement the functions here

RLEList RLEListCreate(){
    RLEList ptr = malloc(sizeof(*ptr));
    if(!ptr){
        return NULL;    
    }
    ptr->letter = NULL;
    ptr->repeatition=0;
    ptr->next=NULL;
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
    RLEList last = list;
    if(!list || !value){
        return RLE_LIST_NULL_ARGUMENT;
    } 
    else{
        if(list->letter == value){
            list->repeatition++;
        }
        else{
            RLEList newHead = RLEListCreate();
            if(!newHead){
                return RLE_LIST_OUT_OF_MEMORY;
            }
            while(last->next!=NULL){
                last=last->next;
            }
            last->next=newHead;
            newHead->letter=value;
            newHead->repeatition++;
        }

        return RLE_LIST_SUCCESS;
    }    
}

int RLEListSize(RLEList list){
    int counter=0;
    RLEList tmp = list;
    if(!list){
        return -1;
    }
    while(tmp->next != NULL){
        counter += tmp->repeatition;
        tmp=tmp->next;
    }
    counter+=tmp->repeatition;
    return counter;
}

RLEListResult RLEListRemove(RLEList list, int index){
    if(index>=RLEListSize( list) || index<0){
        return RLE_LIST_INDEX_OUT_OF_BOUNDS;
    }
    if(!list){
        return RLE_LIST_NULL_ARGUMENT;
    }
    RLEList tmp = list;
    RLEList prev=tmp;
    int counter=tmp->repeatition-1;
    while(counter<index){
        prev = tmp;
        tmp=tmp->next;
        counter+=tmp->repeatition;
    }

    tmp->repeatition --;
    if(tmp->repeatition==0){
        if(tmp->next == NULL){
            prev->next = NULL;
        }
        else{
            if(prev->letter == tmp->next->letter){
                prev->repeatition+=tmp->next->repeatition;
                prev->next=tmp->next->next;
                free(tmp->next);
            }
            else{
                    prev->next = tmp->next;

            }  
            
        }
        free(tmp);
    }
    return RLE_LIST_SUCCESS;
}

char RLEListGet(RLEList list, int index, RLEListResult *result){
    if(index>=RLEListSize( list) || index<0){
        *result= RLE_LIST_INDEX_OUT_OF_BOUNDS;
    }
    if(!list){
        *result= RLE_LIST_NULL_ARGUMENT;
    }
    else{
        char value;
        *result = RLE_LIST_SUCCESS;
        RLEList tmp = list;
        int counter=tmp->repeatition-1;
        while(counter<index){
            tmp=tmp->next;
            counter+=tmp->repeatition;
        }
        value = tmp->letter;
        return value;
    }
    return 0;
}

char* RLEListExportToString(RLEList list, RLEListResult* result){
    int counter=1;
    RLEList ToCount = list;
    while(ToCount->next!=NULL){
        counter++;
        ToCount=ToCount->next;
    }
    char* ListString = malloc(sizeof(char)*counter*3);
    int index=0;
    if(!list){
        *result= RLE_LIST_NULL_ARGUMENT;
        return NULL;
    }
    RLEList tmp = list;
    while(tmp!=NULL){
        ListString+index++=tmp->letter;
        ListString+index++=tmp->repeatition;
        ListString+index++='\n';
    }
    *result =RLE_LIST_SUCCESS;
    return ListString;
}

RLEListResult RLEListMap(RLEList list, MapFunction map_function){
    RLEListResult* result;
    char prev;
    int length = RLEListSize(list), count=0;
    char* string = RLEListExportToString(list,result);
    if (*result==RLE_LIST_NULL_ARGUMENT){
        return *result;
    }
    char* mappedString = malloc(sizeof(char)*(length+1))
    for(int i = 0; i<strlen(string); i+=3){

        for (int j = 0; j<string[i+1]; j++){
            mappedString[j+count] = map_function(string[i]);
        }
         count+=(j+1);
    }
    return RLE_LIST_SUCCESS;
}


