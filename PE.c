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
        return 0;
}

void stack_push(Stack *p, char *nome,int qtd_to_download, int qtd_to_watch){
    Anime *new = (Anime*)malloc(sizeof(Anime));
    strcpy (new->name, nome);
    new-> q_to_download = qtd_to_download;
    new-> q_to_watch= qtd_to_watch;
    p->top++;
    p->vet[p->top] = new;
}

int stack_pop(Stack *p){
    Anime *aux = p->vet[p->top];
    p->top--;
    // return aux;
    return 0;
}

void download_anime(Stack *stack, int qtd_to_download){
    stack->vet[stack->top]->q_to_download -= qtd_to_download;
}

void watch_anime(Stack *stack, int qtd_to_watch){
    stack->vet[stack->top]->q_to_watch -= qtd_to_watch;
}

char* get_nome (Stack *stack){
    return stack->vet[stack->top]->name; 
}