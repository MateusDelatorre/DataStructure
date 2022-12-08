#ifndef tHash
#define tHash

#include <stdlib.h>
#include <stdio.h>
#include "hash.h"
#include "city.h"

typedef struct tree_table{
    HashTable * hash_table;
} TreeHashTable;

TreeHashTable * newTreeHashTable(size_t size);
void addDataToTreeHashTable(TreeHashTable * tree_hash_table, GenericData * new_data, int new_key, int (*compare)(void *, void *));
void * getDataFromTreeHashTable(TreeHashTable * tree_hash_table, int key, char * query, int (*compare)(void *, void *));
void testeTree(Municipio * cidades);

#endif