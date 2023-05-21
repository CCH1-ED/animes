#ifndef FE_H_INCLUDED
#define FE_H_INCLUDED
#define MAX 1024
#include <stdio.h>
#include <stdlib.h>

typedef struct Queue{   //nodo da fila 
    int vet[MAX];   //inicia o vetor da fila
    int inicio, fim, tamanho;   //inicia o inicio,fim e tamanho da fila
}Queue;

Queue* create_queue();

int queue_empty(Queue *f);

void queue_push(Queue *f, int x);

int queue_pop(Queue *f);

#endif