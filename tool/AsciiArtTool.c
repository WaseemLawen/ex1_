//#include <string.h>
//#include<stdio.h>


#include "AsciiArtTool.h"
#include "RLEList.h"
#define BUFFER_SIZE 2

RLEList asciiArtRead(FILE* in_stream)
{
  RLEList list = RLEListCreate();
  char buffer[BUFFER_SIZE]="\n";
  while(fgets(buffer,BUFFER_SIZE, in_stream)!= NULL)
  {
    RLEListAppend(list, buffer[0]);
  }
  return list;
}


RLEListResult asciiArtPrint(RLEList list, FILE *out_stream)
{
  if(!list || !out_stream){
        return RLE_LIST_NULL_ARGUMENT;
    } 
  int length = RLEListSize(list), i=0;
  char c;
  if(length>0){
    char* string = malloc(sizeof(char)*(length+1));
    RLEListResult* result=NULL;
    for(i=0; i<=length; i++)
    {
      c = RLEListGet(list, i, result);
      string[i] = c;
    }
    fputs(string, out_stream);
    free(string);
    return RLE_LIST_SUCCESS;
    }
  return RLE_LIST_ERROR;
}

RLEListResult asciiArtPrintEncoded(RLEList list, FILE *out_stream)
{

  if(!list || !out_stream){
        return RLE_LIST_NULL_ARGUMENT;
    } 
  RLEListResult* result=NULL;
  char* exportedString = RLEListExportToString(list, result);
  fputs(exportedString, out_stream);
  if (exportedString)
  {
    free(exportedString);
  }
  
  return RLE_LIST_SUCCESS;
}



