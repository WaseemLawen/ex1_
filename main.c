#include <stdio.h>
#include <string.h>

#include "AsciiArtTool.c"

void invertAsciiArt(FILE* source)
{
    

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

    if(!strcmp(argv[1],"-i")){
        //inverted dog

    }
    if(!strcmp(argv[1],"-e")){

        RLEList list = asciiArtRead(source);
        RLEListResult *result = asciiArtPrintEncoded(list, target);

    }

    return 0;
}


