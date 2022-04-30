#include <stdio.h>
#include <stdbool.h>
#include<stdlib.h>


#include "RLEList.c"

RLEList asciiArtRead(FILE* in_stream);

RLEListResult asciiArtPrint(RLEList list, FILE *out_stream);

RLEListResult asciiArtPrintEncoded(RLEList list, FILE *out_stream);