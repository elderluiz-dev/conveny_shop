#pragma once

#include "produto.h"

typedef struct promo
{
    int id;
    char nome[50];
    int quantidade;
    float preco;
    char validade[20];
    struct promo *prox;
} p_promo;

typedef struct lista_promo
{
    p_promo *cauda;
    int tamanho;
} lista_promo;

void circular_insere_cabeca(p_promo **cauda, p_promo novo_produto, lista_promo *lista);
void circular_insere_cauda(p_promo **cauda, p_promo novo_produto, lista_promo *lista);

void circular_remove_cabeca(p_promo **cauda);
void circular_remove_cauda(p_promo **cauda, lista_promo *lista);
void circular_remove_id(p_promo **cauda, int id, lista_promo *lista);

void circular_busca_nome(p_promo *cauda, char *nome);
void circular_atualiza_quantidade(p_promo **cauda, int id, int nova_quantidade);
void circular_exibe_lista(p_promo **cauda);
int circular_conta_lista(p_promo *cauda);
void circular_limpa_lista(p_promo **cauda, lista_promo *lista);