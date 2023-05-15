# include "PD.h"

Stack *create_stack (){
    Stack *s = (Stack*) malloc (sizeof (Stack));
    s->top = NULL;
    return s;

}

int stack_empty (Stack *s){
    return s->top == NULL ? 1 : 0;
}

void stack_push (Stack *s, char name[MAX], int qtd_total, Queue *queue){   // ARRUMAR
    Anime *new = (Anime*) malloc (sizeof (Anime));
    strcpy (new->name, nome);
    new-> q_to_download = qtd_total;
    new-> q_to_watch = qtd;
    new-> total_episodes = qtd_total;
    new->queue = queue;
    new-> next = s->top;
    s->top = new;
}

Anime* stack_pop (Stack *s){
    Anime *aux = s->top;
    s->top = s->top->next;
    return aux; // arrumar depois
}


void download_anime (Stack *s, int qtd_to_download){
    s->top->q_to_download -= qtd_to_download;
}

void watch_anime (Stack *s, int qtd_to_watch){
    s->top->q_to_watch -= qtd_to_watch;
}

char * get_nome (Stack *s){
    return s->top->name;
}