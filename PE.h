#ifndef PE_H_INCLUDED
#define PE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#define MAX 1024

typedef struct Pilha{
    int vet[MAX];
    anime *topo;
}pilha;

typedef struct Anime{
    char nome[MAX];
    int f_download;
    int f_assistir;
    struct Anime * next;
}anime;

pilha* criaPilha();
int p_vazia(pilha *p);
void p_push(pilha *p, int x);
int p_pop(pilha *p);

#endif