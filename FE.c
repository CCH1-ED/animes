#include <stdio.h>
#include <stdlib.h>
#define MAX 1024

typedef struct Nodo{
    int info;
    struct Nodo *prox;
}nodo;

typedef struct Fila{
    int vet[MAX];
    int inicio, fim, tamanho;
}fila;

fila *criaFila(){
    fila *f = (fila*)malloc(sizeof(fila));
    f->inicio = f->fim = 0;
    f->tamanho = 0;
    return f;
};

int vazia(fila *f){
    if(f->tamanho == 0)
        return 1;
    return 0;
};

void push(fila *f, int x){
    f->vet[f->fim] = x;
    f->fim = (f->fim+1) % MAX;
    f->tamanho++;
};

