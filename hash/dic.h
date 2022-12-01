#ifndef dic
#define dic

#include <stdio.h>
#include <stdlib.h>

typedef struct array{
    size_t size;
    void * data;
} Data;

typedef struct bigTable{
    int * keys;
    Data * vector;
    int size;
} Dictionary;

Dictionary * newDictionary(size_t size);
void addData(Dictionary * dictionary, void * new_data, int new_key, size_t size);
Data * newData(size_t size);
void * getData(Dictionary * dictionary, int key);
void resize(Data ** data, int ** keys, int new_size, size_t size);

#endif