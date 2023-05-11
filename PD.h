typedef struct Anime{
    char name[200];
    int q_to_download;
    int q_to_watch;
    struct Anime * next;
}Anime;



typedef struct Stack{
    Anime *top;
}Stack;



Stack *create_stack ();

int stack_empty (Stack *s);

void stack_push (Stack *s, char nome[200], int qtd_to_download, int qtd_to_watch);

int stack_pop (Stack *s);