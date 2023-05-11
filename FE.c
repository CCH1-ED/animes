#include "FE.h"

fila *criaFila(){
    fila *f = (fila*)malloc(sizeof(fila));
    f->inicio = f->fim = 0;
    f->tamanho = 0;
    return f;
}

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

int pop(fila *f){
    int aux = f->vet[f->inicio];
    f->inicio = (f->inicio + 1) % MAX;
    f->tamanho--;
    return aux;
};