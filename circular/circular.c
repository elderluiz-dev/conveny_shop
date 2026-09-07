#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "circular.h"

void insere_cabeca(p_promo **cauda, p_promo novo_produto, lista_promo *lista)
{
    p_promo *produto = (p_promo *)malloc(sizeof(p_promo));

    if(produto == NULL) return;

    produto->id = novo_produto.id;
    strcpy(produto->nome, novo_produto.nome);
    produto->preco = novo_produto.preco;
    strcpy(produto->validade, novo_produto.validade);
    produto->quantidade = novo_produto.quantidade;
    produto->prox = novo_produto.prox;

    if(*cauda == NULL)
    {
        // O produto conecta a si mesmo
        produto->prox = produto;
        lista->cauda = produto;
        *cauda = produto;
        return;
    }
    else
    {
        p_promo *cabeca = (*cauda)->prox;
        (*cauda)->prox = produto;
        produto->prox = cabeca;
    }
}

void insere_cauda(p_promo **cauda, p_promo novo_produto, lista_promo *lista)
{
    p_promo *produto = (p_promo *)malloc(sizeof(p_promo));

    if(produto == NULL) return;
    
    produto->id = novo_produto.id;
    strcpy(produto->nome, novo_produto.nome);
    produto->preco = novo_produto.preco;
    strcpy(produto->validade, novo_produto.validade);
    produto->quantidade = novo_produto.quantidade;
    produto->prox = novo_produto.prox;

    if(*cauda == NULL)
    {
        // O produto conecta a si mesmo
        produto->prox = produto;
        lista->cauda = produto;
        *cauda = produto;
        return;
    }
    else
    {
        // O ultimo produto adicionado se conecta com o primeiro da lista(cauda->proximo)
        // E o anterior a esse novo se conecta ao novo nó
        produto->prox = (*cauda)->prox;
        (*cauda)->prox = produto;

        lista->cauda = produto;
        *cauda = produto;
    }
}

int main()
{
    p_promo *cauda = NULL;

    lista_promo lista;
    lista.cauda = cauda;
    lista.tamanho = 0;

    p_promo p1 = {1, "Arroz", 2, 6, "10/10", NULL};
    p_promo p2 = {2, "Feijao", 8, 2.50, "11/10", NULL};

    insere_cabeca(&cauda, p1, &lista);
    insere_cauda(&cauda, p1, &lista);

    return 0;
}