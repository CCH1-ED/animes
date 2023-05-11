#ifndef FE_H_INCLUDED
#define FE_H_INCLUDED
#define MAX 1024
#include <stdio.h>
#include <stdlib.h>

typedef struct Fila{
    int vet[MAX];
    int inicio, fim, tamanho;
}fila;

fila* criaFila();
int f_vazia(fila *f);
void f_push(fila *f, int x);
int f_pop(fila *f);

#endif