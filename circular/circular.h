#pragma once

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
    p_promo *cauda;
    int tamanho;
} lista_promo;

void insere_cabeca(p_promo **cauda, p_promo novo_produto, lista_promo *lista);
void insere_cauda(p_promo **cauda, p_promo novo_produto, lista_promo *lista);

void remove_cabeca(p_promo **cauda);
void remove_cauda(p_promo **cauda, lista_promo *lista);
void remove_id(p_promo **cauda, int id, lista_promo *lista);

void busca_nome(p_promo *cauda, char *nome);

void atualiza_quantidade(p_promo **cauda, int id, int nova_quantidade);

void exibe_lista(p_promo *cauda);

int contar_lista(p_promo *cauda);

void limpa_lista();