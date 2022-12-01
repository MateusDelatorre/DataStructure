#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int i;
} Banco;

void * searchByName();

void main() {
    int * i = searchByName();
    printf("retornou: %d", *i);
}

void * searchByName(){
    int * enroll = malloc(sizeof(int));
    *enroll = 30;
    return enroll;
}