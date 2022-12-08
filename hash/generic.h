#ifndef generic
#define generic

#include <stdio.h>
#include <stdlib.h>

typedef struct object{
    size_t size;
    void * data;
} GenericData;

GenericData * newGenericData(size_t size);
GenericData * newGenericVector(size_t size);
void resizeGenericVector(GenericData ** data, int array_size, int new_size, size_t size);

#endif