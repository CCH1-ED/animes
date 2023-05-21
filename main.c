# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include "PE.h"

# define MAX 1024 



int main(){
    char name[100], command[10];    //inicia as variaveis name e commando
    int qtd_to_watch, qtd_to_download, time_duration , qtd_total;   //inicia as varias de quatidade de ep assistidos, baixados, o tempo total do anime e a quantidade total de episodios respectivamente
    Stack *stack = create_stack();  //chama a função pra criar a pilha
    scanf ("%s", command);  //pega o comando do usuario

    while( strcmp (command, "F") !=0){  //cria um loop pra enquanto o usuario não der o comando F
        if( strcmp (command, "comeca") == 0){   //verifica se o comando do usuario foi comeca

            Queue *queue = create_queue();  //cria uma fila pro novo anime
            scanf (" %s%d", name, &qtd_total);  //pega o nome e numero total de episodios do novo anime do usuario
            stack_push (stack, name, qtd_total, queue);     //empilha o nome do anime e o total de episodios
            printf ("comecando %s\n", name); //diz ao usuario que o anime que ele pediu vai iniciar
        }
        
        else if( strcmp (command, "download") == 0){    //verifica se o comando do usuario foi donwload
            scanf (" %d %d", &qtd_to_download, &time_duration);     //pega o numero de episodios a ser baixado e a duração de cada episodio baixado
            if(stack_empty(stack) == 1){    //chama a função que verifica se a pilha ta vaiza
                printf("Nenhum anime a baixar no momento\n");   //se a pilha estiver vazia retorna essa informação pro usuario
            }
            else if(stack_empty(stack) == 0){   //chama a função que verifica a fila está vazia
                Anime *anime = stack_pop(stack);//pegando dados do topo
                stack_push(stack, anime->name, anime->total_episodes, anime->queue);//dando push com a mesma fila do topo antigo

                if(anime->q_to_download + anime->q_to_watch + qtd_to_download > anime->total_episodes){ //verifica se o numero de episodios baixados+episodios assitidos=episodios a serem baixados é maior que total de episodios do anime
                    qtd_to_download = anime->total_episodes - (anime->q_to_download + anime->q_to_watch); //faz o numero de episodios a serem baixados seja igual ao total de episodios-(o total de ep baixados+o total de episodios assistidos)
                }

                for (int i = 0; i < qtd_to_download; i++) //cria um loop pra empilha os episodios baixados

                    queue_push (anime->queue, time_duration); // pegar topo e envia a fila do topo, quando download == 0 acabo o anime e desce na pilha    

                watch_anime(stack, anime->q_to_watch);  //atualiza o numero de episodios que podem ser assistidos
                download_anime(stack, qtd_to_download + anime->q_to_download);  //chama a função download anime
                free(anime);    //da um free na fila do anime
                printf ("%d eps de %s baixados\n",  qtd_to_download, get_nome(stack));  //diz quant ep foram baixados ao usuario       
            }
        }

        else if( strcmp (command, "assiste") == 0){     //verifica se o comando foi assiste
            int time_watched = 0;   //inicia o tempo de episodios em 0
            scanf ("%d", &qtd_to_watch);    //pega o numero de episodios a serem assistidos
            

            if(stack_empty(stack) == 1){    //chama a função que verifica se a pilha esta vazia
                printf("Nenhum anime a assistir no momento\n"); //se estiver vazia retorna essa informção ao usuario
            }

            else if(stack_empty(stack) == 0){   //chama a função que verifica se a pilha esta vazia
                Anime *anime = stack_pop(stack);    //desempilha episodios baixados
                stack_push(stack, anime->name, anime->total_episodes, anime->queue);    //dando push com a mesma fila do topo antigo

                if(qtd_to_watch > anime->q_to_download){    //verifica se o total de episodios é maior que o numero de baixados
                    qtd_to_watch = anime->q_to_download;    //se sim emparelha o numero de episodios a serem assistidos ao numero de baixados
                }

                for (int i = 0; i < qtd_to_watch; i++)  //cria um loop pra aumenta o tempo de episodios assistidos
                    time_watched += queue_pop(anime->queue);
                anime->q_to_download -= qtd_to_watch;   //diminui o numero de episodios baixados em relação ao numero de episodios assistidos
        
                printf ("%d eps de %s assistidos (%d minutos)\n", qtd_to_watch, get_nome(stack), time_watched); //retorna o nomero de episodios e o tempo

                
                watch_anime(stack, anime->q_to_watch + qtd_to_watch);   //diana
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
    printf("---\n");
    while(stack_empty(stack)!=1){
        Anime *anime = stack_pop(stack);
        printf("%s: faltam baixar %d eps e assistir %d eps\n", anime->name, anime->total_episodes-(anime->q_to_download + anime->q_to_watch), anime->total_episodes-anime->q_to_watch);
        while(queue_empty(anime->queue)!=1){
            int i = queue_pop(anime->queue);
        }
        free(anime->queue);
        free(anime);
    }
    
    scanf("%s", &command);

    return 0;
}