#include <stdio.h>
#include <string.h>

#include "AsciiArtTool.h"
#include "RLEList.h"

RLEListResult invertAsciiArt(FILE* source,FILE* target)
{
    RLEList list = asciiArtRead(source);
    RLEList tmp = list;
    while(tmp!=NULL)
    {
        if((tmp->letter) == ' ')
        {
            tmp->letter = '@';
        }
        tmp=tmp->next;
    }
    RLEListDestroy(tmp);
    RLEListResult result = asciiArtPrint(list,target);
    RLEListDestroy(list);
    return result;
}

RLEListResult AsciiArtTool (FILE* source,FILE* target,char* flag){
    //RLEListResult *result = NULL;
    RLEList list = RLEListCreate();
    RLEListResult result = RLE_LIST_ERROR;
    
    if(flag!=NULL)
    {
        if(!strcmp(flag,"-i"))
        {
            result = invertAsciiArt(source,target);
            }
        if(!strcmp(flag,"-e"))
        {
            if(source){
                list = asciiArtRead(source);
                result = asciiArtPrintEncoded(list, target);
            }
            else{
                result = RLE_LIST_NULL_ARGUMENT;
            }
        }
    }
    RLEListDestroy(list);
    return result;
}

int main(int argc, char** argv)
{
    if (argv[2]==NULL || argv[3]==NULL){
        return 0;
    }
    if(argc!=4){
        return 0;
    }
    FILE* source = fopen(argv[2], "r");
    FILE* target = fopen(argv[3], "w");
    if(!source || !target){
        return 0;
    } 
    RLEListResult result = AsciiArtTool(source,target,argv[1]);
    if (result == RLE_LIST_SUCCESS)
    {
        printf("success");
    }
    
   fclose(source);
   fclose(target);

    return 0;
}

