//#include <string.h>
//#include<stdio.h>


#include "AsciiArtTool.h"
#include "RLEList.h"

RLEList asciiArtRead(FILE* in_stream)
{
  RLEList list = RLEListCreate();
  RLEListResult *result = NULL; //reuslt ? *result
  int length = 0, i = 0;
  char c;
  FILE* fptr = in_stream;
  while((c=fgetc(fptr))!=EOF) {
	  length++;
  }
  char* string = malloc(sizeof(char)*(length+1));
  fgets(string, length, in_stream);
  for(i=0; i<length; i++)
  {
    *result =  RLEListAppend(list, string[i]); 
  }

   //char* exportedString = RLEListExportToString(list, result); // where is exportedString used
   free(string); 
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
  free(exportedString);
  return RLE_LIST_SUCCESS;
}



