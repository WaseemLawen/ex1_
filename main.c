#include <stdio.h>
#include <string.h>

#include "AsciiArtTool.c"

void invertAsciiArt(FILE* source)
{
    

}
void AsciiArtTool (FILE* source,FILE* target,char* flag){
     if(!strcmp(flag,"-i")){
        //inverted dog

    }
    if(!strcmp(flag,"-e")){

        RLEList list = asciiArtRead(source);
        RLEListResult *result = asciiArtPrintEncoded(list, target);

    }
}
void error(char* message, char* filename)
{
    printf("%s %s\n", message);
}

int main(int argc, char** argv)
{
    if (argc!=4)
    {

    }
    FILE* source = fopen(argv[2], "r");
    FILE* target = fopen(argv[3], "w");

    AsciiArtTool(source,target,argv[1]);

   fclose(source);
   fclose(target);

    return 0;
}


