#ifndef PE_H_INCLUDED
#define PE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1024

typedef struct Pilha{
    int vet[MAX];
    Anime *topo;
}pilha;

typedef struct Anime{
    char nome[MAX];
    int f_download;
    int f_assistir;
    struct Anime *prox;
}Anime;

pilha* criaPilha();
int p_vazia(pilha *p);
void p_push(pilha *p, int x);
int p_pop(pilha *p);

#endif