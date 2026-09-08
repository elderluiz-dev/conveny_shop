typedef struct perecivel
{
    int id;
    char nome[50];
    int quantidade;
    float preco;
    char validade[10];
    struct perecivel *prox;
} p_perecivel;

typedef struct lista_pereciveis
{
    p_perecivel *cabeca;
    int tamanho;
} lista_pereciveis;

p_perecivel* criar_p_perecivel(p_perecivel novo);
lista_pereciveis* criar_lista_pereciveis();
void adicionar_perecivel(p_perecivel novo, lista_pereciveis* *lista);
void exibir_pereciveis(p_perecivel* atual);
void remover_perecivel(lista_pereciveis* *lista, int id);
void esvaziar_pereciveis(lista_pereciveis* *lista);
void editar_qtd_perecivel(lista_pereciveis* *lista, int id);
void buscar_perecivel(lista_pereciveis* lista, char *substr);