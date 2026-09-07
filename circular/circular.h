typedef struct promo
{
    int id;
    char nome[50];
    int quantidade;
    float preco;
    char validade[10];
    struct promo *prox;
} p_promo;

typedef struct lista_promo
{
    p_promo *cabeca;
    int tamanho;
};