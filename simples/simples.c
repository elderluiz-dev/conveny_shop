#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "produto.h"
#include "simples.h"

ERROR_TYPE_T criar_lista_pereciveis(lista_pereciveis **lista_pere){
    *lista_pere = malloc(sizeof(**lista_pere));
    if(*lista_pere == NULL)
    {
        return ALLOCATION_ERROR;
    }

    (*lista_pere)->cabeca = NULL;
    (*lista_pere)->tamanho = 0;

    return SUCCESS;
}

ERROR_TYPE_T adicionar_perecivel_inicio(p_perecivel novo, lista_pereciveis* *lista){
    p_perecivel* novo_produto = malloc(sizeof(*novo_produto));
    if(novo_produto == NULL)
    {
        return ALLOCATION_ERROR;
    }
    
    novo_produto->id = novo.id;
    strcpy(novo_produto->nome, novo.nome);
    novo_produto->preco = novo.preco;
    novo_produto->quantidade = novo.quantidade;
    strcpy(novo_produto->validade, novo.validade);
    novo_produto->prox = novo.prox;

    if((*lista)->tamanho == 0){
        (*lista)->cabeca = novo_produto;
        (*lista)->tamanho++;
        return SUCCESS;
    }

    novo_produto->prox = (*lista)->cabeca;
    (*lista)->cabeca = novo_produto;
    (*lista)->tamanho++;

    return SUCCESS;
}

ERROR_TYPE_T adicionar_perecivel_fim(p_perecivel novo, lista_pereciveis* *lista){
    p_perecivel* novo_produto = malloc(sizeof(*novo_produto));
    if(novo_produto == NULL)
    {
        return ALLOCATION_ERROR;
    }
    
    novo_produto->id = novo.id;
    strcpy(novo_produto->nome, novo.nome);
    novo_produto->preco = novo.preco;
    novo_produto->quantidade = novo.quantidade;
    strcpy(novo_produto->validade, novo.validade);
    novo_produto->prox = novo.prox;

    if((*lista)->tamanho == 0){
        (*lista)->cabeca = novo_produto;
        (*lista)->tamanho++;
        return SUCCESS;
    }

    p_perecivel* atual = (*lista)->cabeca;
    while(atual->prox != NULL)
    {
        atual = atual->prox;
    }

    atual->prox = novo_produto;
    (*lista)->tamanho++;

    return SUCCESS;
}

ERROR_TYPE_T exibir_pereciveis(p_perecivel* atual){
    if(atual == NULL){
        return SUCCESS;
    }

    printf("\nNome: %s\n", atual->nome);
    printf("ID: %d\n", atual->id);
    printf("Preço: R$ %.2f\n", atual->preco);
    printf("Quantidade: %d\n", atual->quantidade);
    printf("Validade: %s\n", atual->validade);

    exibir_pereciveis(atual->prox);

    return SUCCESS;
}

ERROR_TYPE_T remover_perecivel_inicio(lista_pereciveis* *lista){
    p_perecivel* atual = (*lista)->cabeca;
    (*lista)->cabeca = (*lista)->cabeca->prox;

    free(atual);
    (*lista)->tamanho--;
    printf("Produto removido com sucesso!\n");

    return SUCCESS;
}

ERROR_TYPE_T remover_perecivel_final(lista_pereciveis* *lista){
    p_perecivel* atual = (*lista)->cabeca;

    if((*lista)->tamanho == 1){
        free(atual);
        (*lista)->cabeca = NULL;
        (*lista)->tamanho--;
        printf("Produto removido com sucesso!\n");
        return SUCCESS;
    }

    while(atual->prox->prox != NULL)
    {
        atual = atual->prox;
    }

    free(atual->prox);
    atual->prox = NULL;
    (*lista)->tamanho--;
    printf("Produto removido com sucesso!\n");

    return SUCCESS;
}

ERROR_TYPE_T remover_perecivel_id(lista_pereciveis* *lista, int id){
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
        return ID_NOTFOUND;
    }

    if(anterior == NULL){
        (*lista)->cabeca = atual->prox;
    }else{
        anterior->prox = atual->prox;
    }

    free(atual);
    (*lista)->tamanho--;
    printf("Produto removido com sucesso!\n");

    return SUCCESS;
}

ERROR_TYPE_T esvaziar_pereciveis(lista_pereciveis* *lista){
    p_perecivel* atual = (*lista)->cabeca;
    
    while(atual != NULL)
    {
        p_perecivel* prox = atual->prox;
        free(atual);
        atual = prox;
    }

    (*lista)->cabeca = NULL;
    (*lista)->tamanho = 0;

    return SUCCESS;
}

ERROR_TYPE_T editar_qtd_perecivel(lista_pereciveis* *lista, int id){
    p_perecivel* atual = (*lista)->cabeca;

    while(atual != NULL && atual->id != id)
    {
        atual = atual->prox;
    }

    if(atual == NULL)
    {
        printf("Produto não encontrado!\n");
        return ID_NOTFOUND;
    }

    printf("\n-- EDITAR PRODUTO %d\n", id);
    printf("Quantidade atual: %d\n", atual->quantidade);
    printf("Nova quantidade: ");
    scanf("%d", &atual->quantidade);

    printf("\nProduto editado com sucesso!\n");
    return SUCCESS;
}

ERROR_TYPE_T buscar_perecivel(lista_pereciveis* lista, char *substr){
    p_perecivel* atual = lista->cabeca;
    int count = 0;

    while(atual != NULL)
    {
        if(strstr(atual->nome, substr) != NULL)
        {
            printf("\nProduto: %s\n", atual->nome);
            printf("ID: %d\n", atual->id);
            printf("Preço: R$ %.2f\n", atual->preco);
            printf("Quantidade: %d\n", atual->quantidade);
            printf("Validade: %s\n", atual->validade);
            count++;
        }
        
        atual = atual->prox;
    }

    if(count == 0){
        printf("Produto não encontrado.\n");
        return ID_NOTFOUND;
    }

    return SUCCESS;
}