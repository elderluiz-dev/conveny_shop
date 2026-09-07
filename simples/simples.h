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
};
