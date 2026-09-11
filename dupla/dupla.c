#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dupla.h"
#include "produto.h"

ERROR_TYPE_T iniciar_lista_nperecivel(lista_nao_pereciveis** lista)
{
    *lista = (lista_nao_pereciveis*) malloc(sizeof(**lista));
    if (*lista == NULL)
    {
        printf("Não foi possível iniciar a lista: Erro na alocação de memória.\n");
        return ALLOCATION_ERROR;
    }

    (*lista)->cabeca = NULL;
    (*lista)->tamanho = 0;

    return SUCCESS;
}

ERROR_TYPE_T inserir(p_nao_perecivel novo_prod, p_nao_perecivel** prod)
{
    p_nao_perecivel* nó = (p_nao_perecivel*) malloc(sizeof(*nó));
    
    if(nó == NULL)
    {
        printf("\nNão foi possível adicionar o produto! Erro de alocação de memória.\n");
        return ALLOCATION_ERROR;
    }

    *nó = novo_prod;

    if(*prod == NULL)
    {
        *prod = nó;
        (*prod)->ante = NULL;
        (*prod)->prox = NULL;
    }
    else
    {
        p_nao_perecivel* aux = *prod;
        while(aux->prox != NULL)
        {
            aux = aux->prox;
        }

        aux->prox = nó;
        nó->ante = aux;
        nó->prox = NULL;
    }

    return SUCCESS;
}

ERROR_TYPE_T remover(lista_nao_pereciveis* lista, int id)
{
    p_nao_perecivel* prod = lista->cabeca;
    p_nao_perecivel* aux = NULL;

    while(prod->prox != NULL && prod->id != id)
    {
        aux = prod;
        prod = prod->prox;
    }

    if(prod->id != id)
    {
        printf("\nId não existente.\n");
        return ID_NOTFOUND;
    }

    if (aux == NULL && prod->prox == NULL)
    {
        free(prod);
        lista->cabeca = NULL;
        lista->tamanho--;
        return SUCCESS;
    }   else
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

ERROR_TYPE_T buscar(p_nao_perecivel* prod, char* prod_busca)
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

ERROR_TYPE_T atualizar_quant(p_nao_perecivel* prod, int id_prod)
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

ERROR_TYPE_T exibir(p_nao_perecivel* prod)
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

    return exibir(prod = prod->prox);
}

ERROR_TYPE_T exi_remover(p_nao_perecivel* prod)
{
    if(prod->ante == NULL)
    {
        printf("\nProdutos atuais:\n");
    }
    printf ("Id: %d\n", prod->id);
    printf("Nome: %s\n\n", prod->nome);

    if(prod->prox == NULL)
    {
        return SUCCESS;
    }

    return exi_remover(prod = prod->prox);
}

ERROR_TYPE_T exi_inverso(p_nao_perecivel* prod)
{
    p_nao_perecivel* aux;
    while(prod->prox != NULL)
    {
        prod = prod->prox;
        aux = prod;
    }
    
    if(aux->prox == NULL)
    {
        printf("\nListagem inversa\n");
    }

    printf ("Id: %d\n", prod->id);
    printf("Nome: %s\n", prod->nome);
    printf("Preço: %.2f\n", prod->preco);
    printf("Quantidade: %d\n", prod->quantidade);
    printf("Validade: %s\n\n", prod->validade);

    if(aux->ante == NULL)
    {
        return SUCCESS;
    }

    aux = aux->ante;
    
    return exi_inverso(prod);
}

ERROR_TYPE_T limpar_list(lista_nao_pereciveis** lista)
{
    p_nao_perecivel* prod = (*lista)->cabeca;
    p_nao_perecivel* aux;

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
