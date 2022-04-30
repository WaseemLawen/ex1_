#include <stdio.h>
#include <string.h>

#include "AsciiArtTool.h"

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
    return asciiArtPrint(list,target);
}

RLEListResult AsciiArtTool (FILE* source,FILE* target,char* flag){
    RLEListResult *result = NULL;
     if(!strcmp(flag,"-i")){
         *result = invertAsciiArt(source,target);
    }
    if(!strcmp(flag,"-e")){

        RLEList list = asciiArtRead(source);
        *result = asciiArtPrintEncoded(list, target);

    }
    return *result;
}
int main(int argc, char** argv)
{
    
    FILE* source = fopen(argv[2], "r");
    FILE* target = fopen(argv[3], "w");

    AsciiArtTool(source,target,argv[1]);

   fclose(source);
   fclose(target);

    return 0;
}


