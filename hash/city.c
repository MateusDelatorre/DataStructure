#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "city.h"

void readDataBase(Municipio cidades[5439]){
    int codigo_estado, codigo_municipio, populacao;
    char nome[100];
    char estado[3];
    cidades[0].codigo_estado = 10;
    //printf("%d", cidades[0].codigo_estado);
    FILE * file;
    file = fopen("database.txt", "r");
    int i = 0;
    while (i <= 5437){
        fscanf(file, "%s %d %d", &cidades[i].estado, &cidades[i].codigo_estado, &cidades[i].codigo_municipio);
        fscanf(file, "%[^0-9]s", &cidades[i].nome);
        fscanf(file, "%d", &cidades[i].populacao);
        //printf("%d: %s", i , cidades[i].nome);
        //printf("%d\n", i);
        cidades[i].store_key = generateKeyConcat(cidades[i].codigo_estado, cidades[i].codigo_municipio);
        i++;
    }
    
    fclose(file);
}

int generateKeyConcat(int codigo_estado, int codigo_municipio){
    //char key[KEY_LIMIT];
    int key;
    int codigo_estado_nDigits = floor(log10(abs(codigo_estado))) + 1;
    int codigo_municipio_nDigits = floor(log10(abs(codigo_municipio))) + 1;

    int key_multiplayer = codigo_estado_nDigits + codigo_municipio_nDigits;
    int codigo_temp = 0; 
    int divisor = 1; 
    int i = 0;

    // key_multiplayer
    for (i = 1; i < key_multiplayer; i++){
        divisor *= 10;
    }
    key_multiplayer = divisor;
    //estado key
    for (i = divisor = 1; i < codigo_estado_nDigits; i++){
        divisor *= 10;
    }
    int digito = 0;
    codigo_temp = codigo_estado;
    for (i = 0; i < codigo_estado_nDigits; i++, divisor/=10, key_multiplayer/=10){
        digito = codigo_temp/divisor;
        codigo_temp -= digito*divisor;
        key += digito * key_multiplayer;
    }

    // municiopio key
    for (i = divisor = 1; i < codigo_municipio_nDigits; i++){
        divisor *= 10;
    }
    codigo_temp = codigo_municipio;
    for (i = 0; i < codigo_municipio_nDigits; i++, divisor/=10, key_multiplayer/=10){
        digito = codigo_temp/divisor;
        codigo_temp -= digito*divisor;
        key += digito * key_multiplayer;
    }
    return key;
}

int checkDuplicate(Municipio cidades[5439]){
    for (int i = 0; i < 5438; i++){
        for (int j = i+1; j < 5438; j++){
            if (cidades[i].store_key == cidades[j].store_key){
                return 0;
            }
        }
    }
    return 1;
}