# include "PD.h"

Stack *create_stack (){
    // aloca uma pilha
    Stack *s = (Stack*) malloc (sizeof (Stack));
    s->top = NULL;
    return s;

}

int stack_empty (Stack *s){
    // verifica se a pilha está vazia
    return s->top == NULL ? 1 : 0;
}

void stack_push (Stack *s, char name[MAX], int total_episodes, Queue *queue){  
    /* 
        empilha um novo anime com as informações do parâmetro
    */
    Anime *new = (Anime*) malloc (sizeof (Anime));
    strcpy (new->name, name);
    new-> q_to_download = 0;
    new-> q_to_watch = 0;
    new-> total_episodes = total_episodes;
    new->queue = queue;
    new-> next = s->top;
    s->top = new;
}

Anime* stack_pop (Stack *s){
    /* 
        desempilha o anime
    */
    Anime *aux = s->top;
    s->top = s->top->next;
    return aux; 
}


void download_anime (Stack *s, int qtd_to_download){
    // aumenta a quantidades de episódios baixados
    s->top->q_to_download += qtd_to_download;
}

void watch_anime (Stack *s, int qtd_to_watch){
    // aumenta a quantidade de episódios assistidos
    s->top->q_to_watch += qtd_to_watch;
}

char * get_nome (Stack *s){
    // retorna o nome do anime
    return s->top->name;
}