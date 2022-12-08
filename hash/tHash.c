#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "hash.h"
#include "tHash.h"
#include "BinaryTree.h"
#include "city.h"

void addTreeToHashTable(TreeRoot ** root, HashTable ** hash_table, int key);

TreeHashTable * newTreeHashTable(size_t size){
    TreeHashTable * tree_hash_table = (TreeHashTable *) malloc(sizeof(TreeHashTable));
    tree_hash_table->hash_table = newHashTable(size);
    return tree_hash_table;
}

void checkTable(GenericData * buffer){
    int i = 0;
    for (i = 0; i < 10; i++, buffer++);{
        printf("address%d: %p\n", i, buffer);
    }
    printf("saiu\n");
}

void addDataToTreeHashTable(TreeHashTable * tree_hash_table, GenericData * new_data, int new_key, int (*compare)(void *, void *)){
    int check = new_key + 1;
    if (tree_hash_table->hash_table->size < check){
        resizeGenericVector(&tree_hash_table->hash_table->vector, tree_hash_table->hash_table->size, new_key, new_data->size);
        tree_hash_table->hash_table->size = new_key;
        TreeRoot * root = newTree();
        addToTreeSort(&root, &new_data, compare);
        addTreeToHashTable(&root, &tree_hash_table->hash_table, new_key);
        return;
    }
    GenericData * buffer = tree_hash_table->hash_table->vector;
    //checkTable(buffer);
    // printf("address0: %p\n", buffer[0].data);
    // printf("address1: %p\n", buffer[1].data);
    // printf("address2: %p\n", buffer[2].data);
    // printf("address3: %p\n", buffer[3].data);
    // printf("address4: %p\n", buffer[4].data);
    // printf("address5: %p\n", buffer[5].data);
    // printf("address5: %p\n", buffer[6].data);
    // printf("address5: %p\n", buffer[7].data);
    // printf("address5: %p\n", buffer[8].data);
    // printf("address5: %p\n", buffer[9].data);
    // printf("address5: %p\n", buffer[10].data);
    buffer += new_key;
    if (buffer->data == NULL){
        TreeRoot * root = newTree();
        addToTreeSort(&root, &new_data, compare);
        addTreeToHashTable(&root, &tree_hash_table->hash_table, new_key);
    }else{
        TreeRoot * root = newTree();
        GenericData * data2 = newGenericData(sizeof(TreeRoot));
        data2->data = buffer->data;
        root = data2->data;
        // printf("address1: %p\n", buffer->data);
        // printf("address2: %p\n", data2->data);
        // printf("address3: %p\n", root);
        //printf("key: %d\n", new_key);
        //printf("tHash.c:61\n");
        root->first = addSort(root->first, &new_data, compare);
    }
}

void addNewDataToTreeHashTable(TreeHashTable * tree_hash_table, GenericData * new_data, int new_key, int (*compare)(void *, void *)){
    TreeRoot * root = newTree();
    addToTreeSort(&root, &new_data, compare);
    addTreeToHashTable(&root, &tree_hash_table->hash_table, new_key);
}

void addTreeToHashTable(TreeRoot ** root, HashTable ** hash_table, int key){
    GenericData * str = (*hash_table)->vector;
    str += key;
    //TreeRoot * teste = (*root);
    str->data = (*root);
    str->size = sizeof(TreeRoot);
    (*hash_table)->size++;
}

void * getDataFromTreeHashTable(TreeHashTable * tree_hash_table, int key, char * query, int (*compare)(void *, void *)){
    GenericData * buffer = tree_hash_table->hash_table->vector;
    buffer += key;
    TreeRoot * root = newTree();
    root = buffer->data;
    if (root->first == NULL){
        return NULL;
    }
    TreeBranch * branch = NULL;
    //printf("tHash.c:51\n");
    branch = find(root->first, query, compare);
    //printf("tHash.c:53\n");
    if (branch){
        return branch->data->data;
    }
    return NULL;
}

void testeTree(Municipio * cidades){
    
    TreeRoot * root;
    root = newTree();
    GenericData * data = newGenericData(sizeof(Municipio));
    printf("sizeof: %d\n", data->size);
    
    data->data = &cidades[0];
    
    printf("%s\n", ((Municipio *)data->data)->nome);
    printf("%d\n", ((Municipio *)data->data)->codigo_estado);
    root->first = (struct branch*) malloc(sizeof(struct branch));
    root->first->data = data;
    printf("address1: %p\n", &cidades[0]);
    printf("address2: %p\n", data->data);
    printf("address3: %p\n", root->first->data->data);
    GenericData * data2 = newGenericData(sizeof(Municipio));
    data2->data = root->first->data->data;
    printf("address4: %p\n", data2->data);
    //addToTreeSort(&root, &data, compareString);
    Municipio * teste = (Municipio *) root->first->data;
    printf("%s\n", ((Municipio *)data2->data)->nome);
    printf("%d\n", ((Municipio *)data2->data)->codigo_estado);
    printf("%s\n", teste->nome);
    printf("%d\n", teste->codigo_estado);
    printf("%s\n", ((Municipio *)root->first->data)->nome);
    printf("%d\n", ((Municipio *)root->first->data)->codigo_estado);
}