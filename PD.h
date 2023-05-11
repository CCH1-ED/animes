# define MAX 1024 

typedef struct Anime{
    char name[MAX];
    int q_to_download;
    int q_to_watch;
    int total_episodes;
    struct Anime * next;
}Anime;



typedef struct Stack{
    Anime *top;
}Stack;



Stack *create_stack ();

int stack_empty (Stack *s);

void stack_push (Stack *s, char nome[MAX], int qtd_to_download, int qtd_to_watch);

int stack_pop (Stack *s);