#include <stdio.h>
#include <stdlib.h>
#include "generic.h"

GenericData * newGenericData(size_t size){
    GenericData *p = malloc(/*offsetof(Data, data) + */size);
    if (p) {
        p->data = NULL;
        p->size = size;
    }
    return p;
}

GenericData * newGenericVector(size_t size){
    GenericData *p = malloc(/*offsetof(Data, data) + */size);
    if (p) {
        p->data = NULL;
        p->size = size;
    }
    return p;
}

void resizeGenericVector(GenericData ** data, int array_size, int new_size, size_t size){
    *data = realloc(*data, (new_size + 1) * size);
    GenericData *p = *data;
    p += array_size;
    printf("a_size: %d\n", array_size);
    printf("size: %d\n", new_size);
    for (; array_size <= new_size; array_size++, p++){
        p->data = NULL;
        p->size = size;
    }
    
}