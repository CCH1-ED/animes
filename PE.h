#ifndef PE_H_INCLUDED
#define PE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1024

typedef struct Anime{
    char name[MAX];
    int q_to_download;
    int q_to_watch;
    struct Anime *prox;
}Anime;

typedef struct Stack{
    Anime vet[MAX];
    int top;
}Stack;

Stack* create_stack();

int stack_empty(Stack *p);

void stack_push(Stack *p, char *nome,int qtd_to_download, int qtd_to_watch);

int stack_pop(Stack *p);

#endif