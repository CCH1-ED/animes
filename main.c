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
            scanf (" %s%d", name, &qtd_total);
            stack_push (stack, name, qtd_total, queue); 
            printf ("comecando %s\n", name); 
        }
        
        else if( strcmp (command, "download") == 0){
            scanf (" %d %d", &qtd_to_download, &time_duration);

            if(stack_empty(stack) == 1){
                printf("Nenhum anime a baixar no momento\n");
            }
            else if(stack_empty(stack) == 0){
                Anime *anime = stack_pop(stack);//pegando dados do topo
                stack_push(stack, anime->name, anime->total_episodes, anime->queue);//dando push com a mesma fila do topo antigo
                // arrumar o topo dps

                if(anime->q_to_download + anime->q_to_watch + qtd_to_download > anime->total_episodes){
                    qtd_to_download = anime->total_episodes - (anime->q_to_download + anime->q_to_watch);
                }

                for (int i = 0; i < qtd_to_download; i++)
                    queue_push (anime->queue, time_duration); // pegar topo e envia a fila do topo, quando download == 0 acabo o anime e desce na pilha    


                //stack_push(stack, anime->name, anime->total_episodes, anime->queue);
                watch_anime(stack, anime->q_to_watch);
                download_anime(stack, qtd_to_download + anime->q_to_download);
                free(anime);
                printf ("%d eps de %s baixados\n",  qtd_to_download, get_nome(stack));                 
            }
        }

        else if( strcmp (command, "assiste") == 0){
            int time_watched = 0;
            scanf ("%d", &qtd_to_watch);
            

            if(stack_empty(stack) == 1){
                printf("Nenhum anime a assistir no momento\n");
            }

            else if(stack_empty(stack) == 0){
                Anime *anime = stack_pop(stack);
                stack_push(stack, anime->name, anime->total_episodes, anime->queue);

                if(qtd_to_watch > anime->q_to_download){
                    qtd_to_watch = anime->q_to_download;
                }

                for (int i = 0; i < qtd_to_watch; i++)
                    time_watched += queue_pop(anime->queue);
                anime->q_to_download -= qtd_to_watch;
        
                printf ("%d eps de %s assistidos (%d minutos)\n", qtd_to_watch, get_nome(stack), time_watched);

                
                watch_anime(stack, anime->q_to_watch + qtd_to_watch);
                download_anime(stack, anime->q_to_download);
                
                if(anime->q_to_watch + qtd_to_watch == anime->total_episodes && anime->q_to_download == 0){
                    free(anime);
                    anime = stack_pop(stack);
                    printf("acabou %s\n", anime->name);
                    free(anime->queue);
                }
                free(anime); 
            }
        }

        scanf (" %s", command);
    }
    getchar();
    return 0;
}