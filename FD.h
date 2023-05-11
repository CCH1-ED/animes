typedef struct Episode{
    int time_duration;
    struct Episode *next;
}Episode;



typedef struct Queue{
    Episode *start;
    Episode *end;
}Queue;



Queue *create_queue ();

int queue_empty (Queue *q);

void queue_push (Queue *q, int time);

int queue_pop (Queue *q);


