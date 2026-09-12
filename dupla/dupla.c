#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dupla.h"
#include "produto.h"

ERROR_TYPE_T iniciar_list_dupla(lista_nao_pereciveis **lista)
{
    *lista = (lista_nao_pereciveis*) malloc(sizeof(**lista));
    if (*lista == NULL)
    {
        return ALLOCATION_ERROR;
    }

    (*lista)->cabeca = NULL;
    (*lista)->tamanho = 0;

    return SUCCESS;
}

ERROR_TYPE_T inserir_inicio_dupla(p_nao_perecivel novo_prod, p_nao_perecivel **cabeça)
{
    p_nao_perecivel *nó = (p_nao_perecivel*) malloc(sizeof(*nó));
    
    if(nó == NULL)
    {
        return ALLOCATION_ERROR;
    }

    *nó = novo_prod;

    if(*cabeça == NULL)
    {
        *cabeça = nó;
        nó->prox = NULL;
        nó->ante = NULL;
    }
    else
    {
        (*cabeça)->ante = nó;
        nó->prox = *cabeça;
        nó->ante = NULL;
        *cabeça = nó;
    }

    return SUCCESS;
}

ERROR_TYPE_T inserir_fim_dupla(p_nao_perecivel novo_prod, p_nao_perecivel **cabeça)
{
    p_nao_perecivel *nó = (p_nao_perecivel*) malloc(sizeof(*nó));
    
    if(nó == NULL)
    {
        printf("\nNão foi possível adicionar o produto! Erro de alocação de memória.\n");
        return ALLOCATION_ERROR;
    }

    *nó = novo_prod;
    
    p_nao_perecivel *aux = *cabeça;
    while(aux->prox != NULL)
    {
        aux = aux->prox;
    }

    aux->prox = nó;
    nó->ante = aux;
    nó->prox = NULL;
    

    return SUCCESS;
}

ERROR_TYPE_T remover_inicio_dupla(lista_nao_pereciveis *lista)
{
    if(lista->tamanho == 0 || lista->cabeca == NULL)
    {
        return SIZE_ERROR;
    }

    p_nao_perecivel *cabeça = lista->cabeca;
   
    if(cabeça->prox == NULL)
    {
        free(cabeça);
        lista->cabeca = NULL;
    }
    else
    {
        lista->cabeca = cabeça->prox;
        (cabeça->prox)->ante = NULL;
        free(cabeça);
    }

    lista->tamanho--;
    return SUCCESS;
}

ERROR_TYPE_T remover_fim_dupla(lista_nao_pereciveis *lista)
{
    if(lista->tamanho == 0 || lista->cabeca == NULL)
    {
        return SIZE_ERROR;
    }

    p_nao_perecivel *prod = lista->cabeca;

    while(prod->prox != NULL)
    {
        prod = prod->prox;
    }

    (prod->ante)->prox = NULL;
    free(prod);
    lista->tamanho--;
    return SUCCESS;
}

ERROR_TYPE_T remover_id_dupla(lista_nao_pereciveis *lista, int id)
{
    if(lista->tamanho == 0 || lista->cabeca == NULL)
    {
        return SIZE_ERROR;
    }

    p_nao_perecivel *prod = lista->cabeca;
    p_nao_perecivel *aux = NULL;

    while(prod->prox != NULL && prod->id != id)
    {
        aux = prod;
        prod = prod->prox;
    }
    if(prod->id != id)
    {
        return ID_NOTFOUND;
    }

    if (aux == NULL)
    {
        remover_inicio_dupla(lista);
        return SUCCESS;
    }   
    else
    {
        aux->prox = prod->prox;
        if(prod->prox != NULL)
        {
            (prod->prox)->ante = aux;
        }
        free(prod);
    } 

    lista->tamanho--;
    return SUCCESS;
}

ERROR_TYPE_T buscar_dupla(p_nao_perecivel *prod, char *prod_busca)
{
    while(prod->prox != NULL)
    {
        if(strpbrk(prod->nome, prod_busca) != NULL)
        {
            printf ("Id: %d\n", prod->id);
            printf("Nome: %s\n", prod->nome);
            printf("Preço: %.2f\n", prod->preco);
            printf("Quantidade: %d\n", prod->quantidade);
            printf("Validade: %s\n\n", prod->validade);
        }
        prod = prod->prox;
    }
    if(prod->prox == NULL && strpbrk(prod->nome, prod_busca) != NULL)
    {
        printf ("Id: %d\n", prod->id);
        printf("Nome: %s\n", prod->nome);
        printf("Preço: %.2f\n", prod->preco);
        printf("Quantidade: %d\n", prod->quantidade);
        printf("Validade: %s\n\n", prod->validade);
    }

    return SUCCESS;
}

ERROR_TYPE_T atualizar_dupla(p_nao_perecivel *prod, int id_prod)
{
    while(prod->prox != NULL && prod->id != id_prod)
    {
        prod = prod->prox;
    }

    if(prod->id != id_prod)
    {
        return ID_NOTFOUND;
    }
    else
    {
        printf("\nProduto encontrado\n");
        printf ("Id: %d\n", prod->id);
        printf("Nome: %s\n", prod->nome);
        printf("Quantidade: %d\n\n", prod->quantidade);


        printf("\nQual a nova quantidade?");
        scanf("%d", &prod->quantidade);
        while(prod->quantidade <= 0)
        {
            printf("\nQuantidade inválida! Digite novamente.\n");
            scanf("%d", &prod->quantidade);
        }
    }

    printf("\nSucesso na alteração!\n");
    return SUCCESS;
}

ERROR_TYPE_T exibir_dupla(p_nao_perecivel *prod)
{
    printf("\nListagem de produtos\n");
    printf ("Id: %d\n", prod->id);
    printf("Nome: %s\n", prod->nome);
    printf("Preço: %.2f\n", prod->preco);
    printf("Quantidade: %d\n", prod->quantidade);
    printf("Validade: %s\n\n", prod->validade);

    if(prod->prox == NULL)
    {
        return SUCCESS;
    }

    return exibir_dupla(prod = prod->prox);
}

ERROR_TYPE_T exi_inver_dupla(p_nao_perecivel *prod, int temp)
{
    if(temp == 1)
    {
        while(prod->prox != NULL)
        {
            prod = prod->prox;

        }

        temp++;
        printf("\nListagem inversa\n");
    }
    
    printf ("Id: %d\n", prod->id);
    printf("Nome: %s\n", prod->nome);
    printf("Preço: %.2f\n", prod->preco);
    printf("Quantidade: %d\n", prod->quantidade);
    printf("Validade: %s\n\n", prod->validade);

    if(prod->ante == NULL)
    {
        return SUCCESS;
    }
    
    return exi_inver_dupla(prod->ante, temp);
}

ERROR_TYPE_T limpar_dupla(lista_nao_pereciveis **lista)
{
    p_nao_perecivel *prod = (*lista)->cabeca;
    p_nao_perecivel *aux;

    while(prod->prox != NULL)
    {
        prod = prod->prox;
        aux = prod->ante;
    }

    if(aux != NULL)
    {
        free(prod);
        free(*lista);
        *lista = NULL;
        printf("\nA lista foi limpada com sucesso!\n");
        return SUCCESS;
    }
    else
    {
        while(aux != NULL)
        {
            free(prod);
            prod = aux;
            aux = aux->ante;
        }
        free(*lista);
        *lista = NULL;
        printf("\nA lista foi limpada com sucesso!\n");
        return SUCCESS;
    }

}