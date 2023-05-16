#ifndef PE_H_INCLUDED
#define PE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FE.h"
#define MAX 1024

typedef struct Anime{
    char name[MAX];
    int q_to_download;
    int q_to_watch;
    int total_episodes;
    Queue *queue;
}Anime;

typedef struct Stack{
    Anime *vet[MAX];
    int top;
}Stack;

Stack* create_stack();

int stack_empty(Stack *p);

void stack_push(Stack *p, char *nome, int total_episodes, Queue *queue);

Anime* stack_pop(Stack *p);

void download_anime(Stack *stack, int qtd_to_download);

void watch_anime(Stack *stack, int qtd_to_watch);



char* get_nome (Stack *stack);

#endif