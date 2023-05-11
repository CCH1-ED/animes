# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "PD.h"

# define MAX 1024 

Stack *create_stack (){
    Stack *s = (Stack*) malloc (sizeof (Stack));
    s->top = NULL;
    return s;

}

int stack_empty (Stack *s){
    return s->top == NULL ? 1 : 0;
}

void stack_push (Stack *s, char nome[MAX], int qtd_total, int qtd){   // ARRUMAR
    Anime *new = (Anime*) malloc (sizeof (Anime));
    strcpy (new->name, nome);
    new-> q_to_download = qtd_total;
    new-> q_to_watch = qtd;
    new-> total_episodes = qtd_total;
    if (s->top != NULL) 
        s->top->next = new;
    s->top = new;
}

int stack_pop (Stack *s){
    Anime *aux = s->top->next;
    free (s->top);
    s->top = aux;
    return 0; // arrumar depois
}

