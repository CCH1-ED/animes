# include <stdio.h>
# include <stdlib.h>
# include "FD.h"

Queue *create_queue (){
    Queue *q = (Queue*) malloc (sizeof (Queue));
    q->start = q->end = NULL;
}


int queue_empty (Queue *q){
    return q->start == NULL ? 1 : 0;
}


void queue_push (Queue *q, int x){
    Episode *new = (Episode*) malloc (sizeof (Episode));
    new->time_duration = x;
    new->next = NULL;
    if (q->end != NULL) 
        q->end->next = new;
    q->end = new;
    if (q->start ==NULL) 
        q->start = new;
}


int queue_pop (Queue *q){
    int x = q->start->time_duration;
    Episode *aux = q->start->next;
    if (q->end == q->start) 
        q->end = NULL;
    free (q->start);
    q->start = aux;
    return x;
}

