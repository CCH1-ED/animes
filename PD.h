# ifndef PD_H_INCLUDED
# define PD_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
# include "FD.h"

# define MAX 1024 

typedef struct Anime{
    char name[MAX]; // nome do anime
    int q_to_download; // quantidade de downloads feitos
    int q_to_watch; // quantidade de animes assistidos
    int total_episodes; // total de episódios do anime
    struct Anime * next; // próximo anime na pilha
    Queue *queue; // fila de episódios do anime
}Anime;



typedef struct Stack{
    Anime *top; // topo da pilha de animes 
}Stack;



Stack *create_stack (); //função que cria a pilha

int stack_empty (Stack *s);  //função que verifica se a pilha esta vazia

void stack_push (Stack *s, char name[MAX], int total_episodes, Queue *queue);    //função que empilha as informações do anime

Anime* stack_pop (Stack *s); //desmpilha as informações da pilha

void download_anime (Stack *s, int qtd_to_download); //função pra aumenta o total de episodios baixados 

void watch_anime (Stack *s, int qtd_to_watch);  //função pra aumenta o total de episodios assistidos

char * get_nome (Stack *s);   //função pra pegar o nome do anime


# endif