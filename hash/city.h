#ifndef city
#define city

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define KEY_LIMIT 30

typedef struct municipio{
    char estado[3];
    char nome[100];
    int codigo_estado;
    int codigo_municipio;
    int populacao;
    int store_key;
} Municipio;

void readDataBase(Municipio cidades[5439]);
int generateKeyConcat(int codigo_estado, int codigo_municipio);
int checkDuplicate(Municipio cidades[5439]);
int compare(void * municipio1, void * municipio2);
int compareString(void * municipio1, void * query);
#endif