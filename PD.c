# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "PD.h"

Stack *create_stack (){
    Stack *s = (Stack*) malloc (sizeof (Stack));
    s->top = NULL;
    return s;

}

int stack_empty (Stack *s){
    return s->top == NULL ? 1 : 0;
}

void stack_push (Stack *s, char nome[200], int qtd_to_download, int qtd_to_watch){
    Anime *new = (Anime*) malloc (sizeof (Anime));
    new->name = nome;
    new-> q_to_download = qtd_to_download;
    new-> q_to_whatch = qtd_to_watch;
    if (s->top != NULL) 
        s->top->next = new;
    s->top = new;
}

int stack_pop (Stack *s){
    Anime *aux = s->top->next;
    free (s->top);
    s->top = aux;
}