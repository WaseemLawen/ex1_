#include <string.h>
#include<stdio.h>
#include "AsciiArtTool.h"

RLEList asciiArtRead(FILE* in_stream)
{
  RLEList list = RLEListCreate();
  RLEListResult* result=NULL;
  int length = 0, i=0;
  char c;
  FILE* fptr = in_stream;
  while(c=fgetc(fptr)!=EOF) {
	  length++;
  }
  char* string = malloc(sizeof(char)*(length+1));
  fgets(string, length, in_stream);
  for(i=0; i<length; i++)
  {
    result = RLEListResult RLEListAppend(list, string[i]) {
  }
  char* exportedString = RLEListExportToString(list, result); // where is exportedString used
  free(string); //
  return list;
}


RLEListResult asciiArtPrint(RLEList list, FILE *out_stream)
{
  int length = RLEListSize(list), i=0;
  char c;
  char* string = malloc(sizeof(char)*(length+1))
  RLEListResult* result=NULL;
  for(i=0; i<=length; i++)
  {
    c = RLEListGet(list, i, result)
    string[i] = c;
  }
  fputs(string, out_stream);
  return result;
}

RLEListResult asciiArtPrintEncoded(RLEList list, FILE *out_stream)
{
  RLEListResult* result=NULL;
  char* exportedString = RLEListExportToString(list, result);
  fputs(exportedString, out_stream)
  return result;
}



