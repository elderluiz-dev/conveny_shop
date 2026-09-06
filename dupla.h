typedef struct nao_perecivel
{
    int id;
    char nome[50];
    int quantidade;
    float preco;
    char validade[10];
    struct nao_perecivel *prox;
    struct nao_perecivel *ante;
} p_nao_perecivel;

typedef struct lista_nao_pereciveis
{
    p_nao_perecivel *cabeca;
    int tamanho;
};