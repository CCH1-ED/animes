#ifndef PE_H_INCLUDED
#define PE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FE.h"
#define MAX 1024

typedef struct Anime{ //nodo do anime
    char name[MAX]; //nome dos animes
    int q_to_download;  //episodios baixados e não assistidos
    int q_to_watch; //episodios assistidos
    int total_episodes; //numero total de episodios do anime
    Queue *queue;   //faz a struct anime aponta pra fila
}Anime;

typedef struct Stack{   //nodo da pilha
    Anime *vet[MAX];    //faz o vetor de pilha aponta pra struct anime
    int top;    //inicia o topo da pilha
}Stack;

Stack* create_stack();

int stack_empty(Stack *p);

void stack_push(Stack *p, char *nome, int total_episodes, Queue *queue);

Anime* stack_pop(Stack *p);

void download_anime(Stack *stack, int qtd_to_download);

void watch_anime(Stack *stack, int qtd_to_watch);

char* get_nome (Stack *stack);

#endif