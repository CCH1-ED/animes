#include "FE.h"

Queue *create_queue(){
    Queue *f = (Queue*)malloc(sizeof(Queue));
    f->inicio = f->fim = 0;
    f->tamanho = 0;
    return f;
}

int queue_empty(Queue *f){
    if(f->tamanho == 0)
        return 1;
    return 0;
}

void queue_push(Queue *f, int x){
    f->vet[f->fim] = x;
    f->fim = (f->fim+1) % MAX;
    f->tamanho++;
}

int queue_pop(Queue *f){
    int aux = f->vet[f->inicio];
    f->inicio = (f->inicio + 1) % MAX;
    f->tamanho--;
    return aux;
}