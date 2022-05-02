//#include <stdio.h>
//#include <stdbool.h>
//#include<stdlib.h>

#ifndef AsciiArtTool_H
#define AsciiArtTool_H
#include "RLEList.h"
//#include "struct.c"


RLEList asciiArtRead(FILE* in_stream);

RLEListResult asciiArtPrint(RLEList list, FILE *out_stream);

RLEListResult asciiArtPrintEncoded(RLEList list, FILE *out_stream);

#endif