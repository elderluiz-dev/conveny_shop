#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "simples.h"

lista_pereciveis* criar_lista_pereciveis(){
    lista_pereciveis* lista_pere = malloc(sizeof(*lista_pere));
    lista_pere->cabeca = NULL;
    lista_pere->tamanho = 0;

    return lista_pere;
}

p_perecivel* criar_p_perecivel(p_perecivel novo){
    p_perecivel* novo_produto = malloc(sizeof(*novo_produto));

    novo_produto->id = novo.id;
    strcpy(novo_produto->nome, novo.nome);
    novo_produto->preco = novo.preco;
    novo_produto->quantidade = novo.quantidade;
    strcpy(novo_produto->validade, novo.validade);
    novo_produto->prox = novo.prox;

    return novo_produto;
}

void adicionar_perecivel(p_perecivel novo, lista_pereciveis* *lista){
    p_perecivel* produto = criar_p_perecivel(novo);
    
    if((*lista)->tamanho == 0){
        (*lista)->cabeca = produto;
        (*lista)->tamanho = 1;

        return;
    }

    p_perecivel* atual = (*lista)->cabeca;
    while(atual->prox != NULL)
    {
        atual = atual->prox;
    }

    atual->prox = produto;
    (*lista)->tamanho++;

    return;
}

void exibir_pereciveis(p_perecivel* atual){
    if(atual == NULL){
        return;
    }

    printf("\nNome: %s\n", atual->nome);
    printf("ID: %d\n", atual->id);
    printf("Preço: %.2f\n", atual->preco);
    printf("Quantidade: %d\n", atual->quantidade);
    printf("Validade: %s\n", atual->validade);

    exibir_pereciveis(atual->prox);
}

void remover_perecivel(lista_pereciveis* *lista, int id){
    p_perecivel* atual = (*lista)->cabeca;
    p_perecivel* anterior = NULL;

    while(atual != NULL && atual->id != id)
    {
        anterior = atual;
        atual = atual->prox;
    }
    

    if(atual == NULL)
    {
        printf("Produto não encontrado!\n");
        return;
    }

    if(anterior == NULL){
        (*lista)->cabeca = atual->prox;
    }else{
        anterior->prox = atual->prox;
    }

    free(atual);
    (*lista)->tamanho--;
    printf("Produto removido com sucesso!\n");

    return;
}

void esvaziar_pereciveis(lista_pereciveis* *lista){
    p_perecivel* atual = (*lista)->cabeca;
    
    while(atual != NULL)
    {
        p_perecivel* prox = atual->prox;
        free(atual);
        atual = prox;
    }

    (*lista)->cabeca = NULL;
    (*lista)->tamanho = 0;

    printf("Lista esvaziada!\n");
    return;
}

void editar_qtd_perecivel(lista_pereciveis* *lista, int id){
    p_perecivel* atual = (*lista)->cabeca;

    if(atual == NULL){
        printf("Lista vazia.");
        return;
    }

    while(atual != NULL && atual->id != id)
    {
        atual = atual->prox;
    }

    if(atual == NULL)
    {
        printf("Produto não encontrado!\n");
        return;
    }

    printf("\n-- EDITAR PRODUTO %d\n", id);
    printf("Quantidade atual: %d\n", atual->quantidade);
    printf("Nova quantidade: ");
    scanf("%d", &atual->quantidade);

    printf("\nProduto editado com sucesso!\n");
    return;
}

void buscar_perecivel(lista_pereciveis* lista, char *substr){
    p_perecivel* atual = lista->cabeca;
    int count = 0;

    while(atual != NULL)
    {
        if(strstr(atual->nome, substr) != NULL)
        {
            printf("\nProduto: %s\n", atual->nome);
            printf("ID: %d\n", atual->id);
            printf("Preço: %.2f\n", atual->preco);
            printf("Quantidade: %d\n", atual->quantidade);
            printf("Validade: %s\n", atual->validade);
            count++;
        }
        
        atual = atual->prox;
    }

    if(count == 0){
        printf("Produto não encontrado.\n");
        return;
    }

    return;
}