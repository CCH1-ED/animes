# include "FD.h"

Queue *create_queue (){
    Queue *q = (Queue*) malloc (sizeof (Queue));   //aloca memoria pra fila
    q->start = q->end = NULL;  //inicia o fim e o inicio da fila com nulo
    return q;  //retorna a fila
}


int queue_empty (Queue *q){
    return q->start == NULL ? 1 : 0; // retorna 1 se estiver vazia e 0 caso contrário
}


void queue_push (Queue *q, int time){
    /* 
        Insere um nuvo episódio na fila e adiciona seus dados
    */
    Episode *new = (Episode*) malloc (sizeof (Episode)); 
    new->time_duration = time; 
    new->next = NULL; 
    if (q->end != NULL) 
        q->end->next = new;
    else 
        q->start = new;
    q->end = new;
    free(new);
}


int queue_pop (Queue *q){
    /* 
        retira um episódio da lista
    */
    int time = q->start->time_duration;
    Episode *aux = q->start->next;
    if (q->end == q->start) 
        q->end = NULL;
    free (q->start);
    q->start = aux;
    return time;
}


