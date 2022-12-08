#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "hash.h"
#include "MyMath.h"

int generateKeyConcatInt(int prefix, int suffix){
    //char key[KEY_LIMIT];
    int key;
    int prefix_nDigits = getDigitCount(prefix);
    int suffix_nDigits = getDigitCount(suffix);

    int key_multiplayer = prefix_nDigits + suffix_nDigits;
    int key_temp = 0;
    int divisor = 1;
    int i = 0;

    // key_multiplayer
    for (i = 1; i < key_multiplayer; i++){
        divisor *= 10;
    }
    key_multiplayer = divisor;
    //prefix key
    for (i = divisor = 1; i < prefix_nDigits; i++){
        divisor *= 10;
    }
    int digit = 0;
    key_temp = prefix;
    for (i = 0; i < prefix_nDigits; i++, divisor/=10, key_multiplayer/=10){
        digit = key_temp/divisor;
        key_temp -= digit*divisor;
        key += digit * key_multiplayer;
    }

    // municiopio key
    for (i = divisor = 1; i < suffix_nDigits; i++){
        divisor *= 10;
    }
    key_temp = suffix;
    for (i = 0; i < suffix_nDigits; i++, divisor/=10, key_multiplayer/=10){
        digit = key_temp/divisor;
        key_temp -= digit*divisor;
        key += digit * key_multiplayer;
    }
    return key;
}

int midSquare(int data, int list_size) {
    int temp_size = list_size - 1;
    int list_nDigits = floor(log10(abs(temp_size))) + 1;
    return 1;
}

int simpleMod(int data, int list_size){
    return (data % list_size);
}

int Binning(int data, int binning_size){
    return (data / binning_size);
}

int modBinning(int data, int list_size, int binning_size){
    int mod = simpleMod(data, list_size);
    return Binning(mod, binning_size);
}

HashTable * newHashTable(size_t size){
    HashTable * hash_table = (HashTable *) malloc(sizeof(HashTable));
    hash_table->vector = newGenericData(size);
    hash_table->size = 1;
    return hash_table;
}

void addData(HashTable * hash_table, void * new_data, int new_key, size_t size){
    if (hash_table->size <= new_key){
        resizeGenericVector(&hash_table->vector, hash_table->size, new_key, size);
    }
    GenericData * str = hash_table->vector;
    str += new_key;
    str->data = new_data;
    str->size = size;
    hash_table->size = new_key + 1;
}

void * getData(HashTable * hash_table, int key){
    GenericData * str = hash_table->vector;
    str += key;
    return str->data;
}