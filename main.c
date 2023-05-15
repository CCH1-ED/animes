# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include "PE.h"
# include "FE.h"

# define MAX 1024 

// limitar e verificar pelo valor total de ep do anime

int main(){
    char name[100], command[10];
    int qtd_to_watch, qtd_to_download, time_duration , qtd_total;
    Stack *stack = create_stack();
    //Queue *queue = create_queue ();
    scanf ("%s", command);

    while( strcmp (command, "F") !=0){
        if( strcmp (command, "comeca") == 0){

            Queue *queue = create_queue();
            scanf (" %s%d", &name, &qtd_total);
            stack_push (stack, name, qtd_total, queue); // ARRUMAR
            printf ("comecando %s\n", name); 
        }
        
        else if( strcmp (command, "download") == 0){
            scanf (" %d %d", &qtd_to_download, &time_duration);

            download_anime(stack, qtd_to_download);
            for (int i = 0; i < qtd_to_download; i++)
                queue_push (queue, time_duration); // pegar topo e envia a fila do topo, quando download == 0 acabo o anime e desce na pilha    
            printf ("%d eps de %s baixados\n", qtd_to_download, get_nome(stack)); 
        }

        else if( strcmp (command, "assiste") == 0){
            int time_watched = 0;
            scanf ("%d", &qtd_to_watch);
            watch_anime(stack, qtd_to_watch);
            for (int i = 0; i <qtd_to_watch; i++)
                time_watched += queue_pop(queue);
            printf ("%d eps de %s assistidos (%d minutos)\n", qtd_to_watch, get_nome(stack), time_watched); 
        }

        scanf (" %s", command);
    }
    
    return 0;
}