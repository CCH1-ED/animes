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
int vazia(fila *f);
void push(fila *f, int x);
int pop(fila *f);

#endif