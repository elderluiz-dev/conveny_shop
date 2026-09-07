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

void remove_inicio();
void remove_fim();
void remove_id();

p_promo busca_nome();

void atualiza_quantidade();

void limpa_lista();