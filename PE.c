#include "PE.h"

Stack* create_stack(){
    Stack *p = (Stack*)malloc(sizeof(Stack));
    p->top = -1;
    return p;
}

int stack_empty(Stack *p){
    if(p->top == -1)
        return 1;
    else
        return 0 ;
}

void stack_push(Stack *p, char *nome,int qtd_to_download, int qtd_to_watch){
    Anime *new = (Anime*)malloc(sizeof(Anime));
    strcpy (new->nome, nome);
    new-> f_download = qtd_to_download;
    new-> f_assistir= qtd_to_watch;
    p->top++;
    p->vet[p->top] = x;
}

int stack_pop(Stack *p){
    Anime *aux = p->vet[p->top];
    p->top--;
    // return aux;
    return 0;
}