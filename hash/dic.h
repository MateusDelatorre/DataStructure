#ifndef dic
#define dic

#include <stdio.h>
#include <stdlib.h>
#include "generic.h"

typedef struct bigTable{
    int * keys;
    GenericData * vector;
    int size;
} Dictionary;

Dictionary * newDictionary(size_t size);
void addDataToDictionary(Dictionary * dictionary, void * new_data, int new_key, size_t size);
void * getDataFromDictionary(Dictionary * dictionary, int key);

#endif