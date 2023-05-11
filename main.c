# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include "PD.h"
# include "FD.h"

// limitar e verificar pelo valor total de ep do anime

int main(){
    char name[200], command[100];
    int qtd_to_watch, qtd_to_download, time_duration;
    Stack *stack = create_stack();
    Queue *queue = create_queue ();
    scanf ("%s", &command);

    while( strcmp (command, "F") !=0){
        if( strcmp (command, "comeca") == 0){
            Queue *queue = create_queue();
            scanf ("%s%d", &name, &qtd_to_download);
            stack_push (stack, name, qtd_to_download, qtd_to_download);
            printf ("comecando %s\n", name); 
        }
        
        else if( strcmp (command, "download") == 0){
            scanf ("%d %d", &qtd_to_download, &time_duration);
            stack->top->q_to_download -= qtd_to_download;
            for (int i = 0; i < qtd_to_download; i++)
                queue_push (queue, time_duration);
            printf ("%d eps de %s baixados\n", qtd_to_download, stack->top->name); 
        }

        else if( strcmp (command, "assiste") == 0){
            int time_watched = 0;
            scanf ("%d", &qtd_to_watch);
            stack->top->q_to_watch -= qtd_to_watch;
            for (int i = 0; i <qtd_to_watch; i++)
                time_watched += queue_pop(queue);
            printf ("%d eps de %s assistidos (%d minutos)\n", qtd_to_watch, stack->top->name, time_watched); 
        }

        scanf (" %s", command);
    }
    
    return 0;
}