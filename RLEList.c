#include <string.h>


#include "struct.c"
#include "RLEList.h"
//implement the functions here

RLEList RLEListCreate(){
    RLEList ptr = malloc(sizeof(*ptr));
    if(!ptr){
        return NULL;    
    }
    ptr->letter = 0;
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
    if((list != NULL) && (index>=RLEListSize( list) || index<0)){
        return RLE_LIST_INDEX_OUT_OF_BOUNDS;
    }
    if(list==NULL){
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
    if((list != NULL) && (index>=RLEListSize( list) || index<0)){
        if(result != NULL)
         *result= RLE_LIST_INDEX_OUT_OF_BOUNDS;
        return 0;
    }
    else if(list==NULL){
        if(result != NULL)
            *result= RLE_LIST_NULL_ARGUMENT;
        return 0;
    }
    else{
        char value;
        if(result != NULL)
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

int intLength(int x)
{
    int count = 0;
    while (x != 0)
    {
        count++;
        x/=10;

    }
    return count;
}

int power(int a,int b){
    while(b-1){
        a*=a;
        b--;
    }
    return a;
}

char* RLEListExportToString(RLEList list, RLEListResult* result){
    if(list==NULL){
        *result= RLE_LIST_NULL_ARGUMENT;
        return NULL;
    }
    RLEList ToCount = list;
    int counter=0;
    while(ToCount!=NULL){
        counter+=(2+intLength(ToCount->repeatition));
        ToCount=ToCount->next;
    }
    char* ListString = malloc(sizeof(char)*(counter+1));
    if (ListString==NULL)
    {
        free(ListString);
        return NULL;
    }
    int index=0;
    RLEList tmp = list;
    while(tmp!=NULL){
        ListString[index++]=tmp->letter;
        int len = intLength(tmp->repeatition);
        int num =tmp->repeatition;
        while(len)
        {
            int division = power(10,len-1);
            int curr_num = num/division;
            ListString[index++]=(char)curr_num;
            num-=curr_num*division;
            len--;
        }
        ListString[index++]='\n';
        tmp=tmp->next;
    }
    *result =RLE_LIST_SUCCESS;
    return ListString;
}


RLEListResult RLEListMap(RLEList list, MapFunction map_function){
    RLEListResult* result=NULL;
    //char prev;
    int i = 0, j=0;
    int length = RLEListSize(list), count=0;
    char* string = RLEListExportToString(list,result);
    if (*result==RLE_LIST_NULL_ARGUMENT){
        return *result;
    }
    char* mappedString = malloc(sizeof(char)*(length+1));
    for(i = 0; i<strlen(string); i+=3){

        for (j = 0; j<string[i+1]; j++){
            mappedString[j+count] = map_function(string[i]);
            count+=(j+1);
        }
         
    }
    return RLE_LIST_SUCCESS;
}


