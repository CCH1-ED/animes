# ifndef PD_H_INCLUDED
# define PD_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
# include "FD.h"

# define MAX 1024 

typedef struct Anime{
    char name[MAX];
    int q_to_download;
    int q_to_watch;
    int total_episodes;
    struct Anime * next;
    Queue *queue;
}Anime;



typedef struct Stack{
    Anime *top;
}Stack;



Stack *create_stack ();

int stack_empty (Stack *s);

void stack_push (Stack *s, char name[MAX], int total_episodes, Queue *queue);

Anime* stack_pop (Stack *s);

void download_anime (Stack *s, int qtd_to_download);

void watch_anime (Stack *s, int qtd_to_watch);

char * get_nome (Stack *s);


# endif