#include "PE.h"

Stack* create_stack(){  //função que cria a pilha
    Stack *p = (Stack*)malloc(sizeof(Stack));   //aloca memoria da pilha
    p->top = -1;    //faz o topo da pilha aponta pra posição -1
    return p;   //retorna a pilha
}

int stack_empty(Stack *p){  //função que verifica se a pilha esta vazia
    if(p->top == -1)    //verifica se o topo aponta para a posição -1
        return 1;   //retorna 1/true se a pilha estiver vazia ou o topo aponta pra posição -1  
    else
        return 0;   //retorna 0/false se a pilha não estiver vazia ou o não topo aponta pra posição -1
}

void stack_push(Stack *p, char *nome, int total_episodes, Queue *queue){    //função que empilha as informações do anime
    Anime *new = (Anime*)malloc(sizeof(Anime)); //aloca memoria pro anime

    strcpy (new->name, nome);   //copia o nome do anime e aloca na pilha de nome da estrutura anime
    new-> q_to_download = 0;    //zera os downloads
    new-> q_to_watch = 0;       //zera os episodios assistidos
    new-> total_episodes = total_episodes;  //empilha o total de episodios
    new->queue = queue; //faz anime aponta pra fila

    p->top++;   //aumenta em 1 a posição que o topo aponta
    p->vet[p->top] = new;   //faz o topo aponta pra new
}

Anime* stack_pop(Stack *p){     //desmpilha as informações da pilha
    Anime *aux = p->vet[p->top];    //faz o auxiliar aponta pro topo da pilha
    p->top--;   //diminui em 1 o topo da ílha
    return aux; //retorna aux
}

void download_anime(Stack *stack, int qtd_to_download){ //função pra aumenta o total de episodios baixados 
    stack->vet[stack->top]->q_to_download += qtd_to_download;
}

void watch_anime(Stack *stack, int qtd_to_watch){   //função pra aumenta o total de episodios assistidos
    stack->vet[stack->top]->q_to_watch += qtd_to_watch;
}


char* get_nome (Stack *stack){  //função pra pegar o nome do anime
    return stack->vet[stack->top]->name; 
}