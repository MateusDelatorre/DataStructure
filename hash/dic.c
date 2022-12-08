#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "dic.h"
#include "generic.h"

Dictionary * newDictionary(size_t size){
    Dictionary * dictionary = (Dictionary *) malloc(sizeof(Dictionary));
    dictionary->keys = malloc(sizeof(int));
    dictionary->vector = newGenericData(size);
    dictionary->size = 1;
    return dictionary;
}

void addDataToDictionary(Dictionary * dictionary, void * new_data, int new_key, size_t size){
    if (dictionary->size < new_key){
        resizeGenericVector(&dictionary->vector, dictionary->size, new_key, size);
    }
    GenericData * str = dictionary->vector;
    str += new_key;
    str->data = new_data;
    str->size = size;
    dictionary->size++;
}

void * getDataFromDictionary(Dictionary * dictionary, int key){
    GenericData * str = dictionary->vector;
    str += key;
    return str->data;
}