#include <stdio.h>
#include <stdlib.h>
#define MAX 1024

typedef struct Pilha{
    int vet[MAX];
    int topo;
}pilha;

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

void push(pilha *p, int x){
    p->topo++;
    p->vet[p->topo] = x;
}

int pop(pilha *p){
    int aux = p->vet[p->topo];
    p->topo--;
    return aux;
}