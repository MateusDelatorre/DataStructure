#ifndef hash
#define hash

#include "generic.h"

typedef struct table{
    GenericData * vector;
    int size;
} HashTable;

int generateKeyConcatInt(int prefix, int suffix);
int midSquare(int data, int list_size);
int simpleMod(int data, int list_size);
int Binning(int data, int binning_size);
int modBinning(int data, int list_size, int binning_size);

HashTable * newHashTable(size_t size);
void addData(HashTable * hash_table, void * new_data, int new_key, size_t size);
void * getData(HashTable * hash_table, int key);

#endif