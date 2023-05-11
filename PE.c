#include "PE.h"

Stack* create_stack(){
    Stack *p = (Stack*)malloc(sizeof(Stack));
    p->topo = NULL;
    return p;
}

int stack_empty(Stack *p){
    if(p->topo == NULL)
        return 1;
    else
        return 0;
}

void stack_push(Stack *p, char *nome,int qtd_to_download, int qtd_to_watch){
    Anime *new = (Anime*)malloc(sizeof(Anime));
    strcpy (new->name, nome);
    new-> q_to_download = qtd_to_download;
    new-> q_to_watch= qtd_to_watch;
    p->topo++;
    p->vet[p->topo] = new;
}

int stack_pop(Stack *p){
    Anime *aux = p->vet[p->topo];
    p->topo--;
    // return aux;
    return 0;
}