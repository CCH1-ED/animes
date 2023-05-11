#ifndef PE_H_INCLUDED
#define PE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1024

typedef struct Anime{
    char nome[MAX];
    int f_download;
    int f_assistir;
    struct Anime *prox;
}Anime;

typedef struct Stack{
    int vet[MAX];
    Anime *top;
}Stack;

Stack* create_stack();

int stack_empty(stack *p);

void stack_push(stack *p, int x);

int stack_pop(stack *p);

#endif