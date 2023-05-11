# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include "PD.h"
# Include "FD.h"

int main(){
    char name[200], command[100];
    int qtd_to_watch, qtd_to_download, time_duration;
    Stack *stack = create_stack()
    while( scanf ("%[^ ]", &command) != "F"){
        if( strcmp (command, "comeca") == 0){
            Queue *queue = create_queue();
            scanf("%s%d", &name, &qtd_to_download);
            qtd_to_watch = qtd_to_download;
            stack_push(stack, name, qtd_to_download, qtd_to_watch);
        }
        
        else if( strcmp (command, "download") == 0){

        }

        else if( strcmp (command, "assiste") == 0){

        }
    }
}