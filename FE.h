#ifndef FE_H_INCLUDED
#define FE_H_INCLUDED
#define MAX 1024
#include <stdio.h>
#include <stdlib.h>

typedef struct Queue{
    int vet[MAX];
    int inicio, fim, tamanho;
}Queue;

queue* create_queue();
int queue_empty(queue *f);
void queue_push(queue *f, int x);
int queue_pop(queue *f);

#endif