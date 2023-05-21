# ifndef FD_H_INCLUDED
# define FD_H_INCLUDED
# include <stdio.h>
# include <stdlib.h>

typedef struct Episode{
    int time_duration; // tempo de duração de cada episódio
    struct Episode *next; // ponteiro para o próximo episódio
}Episode;



typedef struct Queue{
    Episode *start; // ponteiro para o primeiro episódio da lista
    Episode *end;   // ponteiro para o último episódio da lista
}Queue;



Queue *create_queue ();  //função que cria a fila

int queue_empty (Queue *q);  //função que verifica se a fila esta vazia

void queue_push (Queue *q, int time);   //função que enfileira um anime

int queue_pop (Queue *q); //função que desinfileira um anime


# endif