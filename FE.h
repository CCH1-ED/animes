#ifndef FE_H_INCLUDED
#define FE_H_INCLUDED
#define MAX 1024
#include <stdio.h>
#include <stdlib.h>

typedef struct Queue{
    int vet[MAX];
    int inicio, fim, tamanho;
}Queue;

Queue* create_queue();

int queue_empty(Queue *f);

void queue_push(Queue *f, int x);

int queue_pop(Queue *f);

#endif