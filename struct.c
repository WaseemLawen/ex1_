#include<stdio.h>
#include<string.h>

struct RLEList_t{
    char letter;
    int repeatition;
    struct RLEList_t* next;
};