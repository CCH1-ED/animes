#include "PE.h"

pilha* criaPilha(){
    pilha *p = (pilha*)malloc(sizeof(pilha));
    p->topo = -1;
    return p;
}

int vazia(pilha *p){
    if(p->topo == -1)
        return 1;
    else
        return 0 ;
}

void push(pilha *p, char *nome,int qtd_to_downoad, int qtd_to_watch){
    anime *new = ();
    
    p->topo++;
    p->vet[p->topo] = x;
}

int pop(pilha *p){
    anime *aux = p->vet[p->topo];
    p->topo--;
    return aux;
}