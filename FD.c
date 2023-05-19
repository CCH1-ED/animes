# include "FD.h"

Queue *create_queue (){
    Queue *q = (Queue*) malloc (sizeof (Queue));
    q->start = q->end = NULL;
    return q;
}


int queue_empty (Queue *q){
    return q->start == NULL ? 1 : 0;
}


void queue_push (Queue *q, int time){
    Episode *new = (Episode*) malloc (sizeof (Episode));
    new->time_duration = time;
    new->next = NULL;
    if (q->end != NULL) 
        q->end->next = new;
    else 
        q->start = new;
    q->end = new;
}


int queue_pop (Queue *q){
    int time = q->start->time_duration;
    Episode *aux = q->start->next;
    if (q->end == q->start) 
        q->end = NULL;
    free (q->start);
    q->start = aux;
    return time;
}


