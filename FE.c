#include "FE.h"

Queue *create_queue(){  //função que cria a fila
    Queue *f = (Queue*)malloc(sizeof(Queue));   //aloca memoria pra fila
    f->inicio = f->fim = 0; //inicia o fim e o inicio da fila em 0
    f->tamanho = 0; //inicia o tamanho da fila em 0
    return f;   //retorna a fila
}

int queue_empty(Queue *f){  //função que verifica se a fila esta vazia
    if(f->tamanho == 0) //verifica se a variavel tamanho é 0
        return 1;   //retorna 1/true se a fila estiver vazia
    return 0;   //retorna 0/false se a fila não estiver vazia
}

void queue_push(Queue *f, int x){   //função que enfileira um anime
    f->vet[f->fim] = x; //faz o final da fila aponta pro anime adicionado
    f->fim = (f->fim+1) % MAX;  
    f->tamanho++;   //aumenta o tamanho em 1
}

int queue_pop(Queue *f){    //função que desinfileira um anime
    int aux = f->vet[f->inicio];    //faz o aux armazenar o inicio da fila
    f->inicio = (f->inicio + 1) % MAX;  
    f->tamanho--;   //diminui em 1 o tamanho da fila
    return aux; //retorna aux
}