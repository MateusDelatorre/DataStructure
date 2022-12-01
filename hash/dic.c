#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "dic.h"
#include "city.h"

Data * newData(size_t size){
    Data *p = malloc(/*offsetof(Data, data) + */size);
    if (p) {
        p->size = size;
    }
    return p;
}

Dictionary * newDictionary(size_t size){
    Dictionary * dictionary = (Dictionary *) malloc(sizeof(Dictionary));
    dictionary->keys = malloc(sizeof(int));
    dictionary->vector = newData(size);
    dictionary->size = 1;
    return dictionary;
}

void addData(Dictionary * dictionary, void * new_data, int new_key, size_t size){
    if (dictionary->size < new_key){
        resize(&dictionary->vector, &dictionary->keys, new_key, size);
    }
    Data * str = dictionary->vector;
    str += new_key;
    str->data = new_data;
    str->size = size;
    dictionary->size++;
}

void * getData(Dictionary * dictionary, int key){
    Data * str = dictionary->vector;
    str += key;
    return str->data;
}

void resize(Data ** data, int ** keys, int new_size, size_t size){
    //*keys = realloc(*keys, new_size * sizeof(int));
    *data = realloc(*data, /*offsetof(Data, data) + */new_size * size);
}