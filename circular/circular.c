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

void remove_cabeca(p_promo **cauda)
{
    if(*cauda == NULL)
    {
        printf("Não foi possível realizar a remoção do item pois a lisa está vazia\n");
        return;
    }
    
    p_promo *cabeca = (*cauda)->prox;

    free(cabeca);

    (*cauda)->prox = (*cauda)->prox->prox;
}

void remove_cauda(p_promo **cauda, lista_promo *lista)
{
    if(*cauda == NULL)
    {
        printf("Não foi possível realizar a remoção pois a lisa está vazia\n");
        return;
    }

    p_promo *atual = *cauda;

    while(atual->prox != *cauda)
    {
        atual = atual->prox;
    }

    free(atual->prox);

    atual->prox = (*cauda)->prox;
    lista->cauda = atual->prox;
}

void remove_id(p_promo **cauda, int id, lista_promo *lista)
{
    if(*cauda == NULL)
    {
        printf("Não foi possível realizar a remoção pois a lista está vazia\n");
        return;
    }

    p_promo *atual = *cauda;
    int encontrou = 0;

    do {
        if (atual->prox->id == id) {
            encontrou = 1;
            break;
        }
        atual = atual->prox;
    } while (atual != *cauda);

    if (!encontrou) {
        printf("ID não encontrado na lista.\n");
        return;
    }

    if (atual->prox == (*cauda)->prox)
    {
        remove_cabeca(cauda); 
        return;
    }
    else if (atual->prox == *cauda)
    {
        remove_cauda(cauda, lista);
        return;
    }

    p_promo *remover = atual->prox; 
    atual->prox = remover->prox;    
    free(remover);                  
}

void busca_nome(p_promo *cauda, char *nome)
{
    if (cauda == NULL)
    {
        printf("Não foi possível buscar o produto, pois a lista está vazia.\n");
        return; 
    }

    p_promo *atual = cauda->prox;
    int encontrou = 0;

    do
    {
        if(strstr(atual->nome, nome) != NULL)
        {
            printf("ID: %d\n", atual->id);
            printf("Nome: %s\n", atual->nome);
            printf("Quantidade: %d\n", atual->quantidade);
            printf("Preço: R$ %.2f\n", atual->preco); 
            printf("Validade: %s\n", atual->validade);
            printf("------------------------\n");
            
            encontrou = 1;
        }
        
        atual = atual->prox;
    } while(atual != cauda->prox); 

    if (encontrou != 1)
    {
        printf("Nenhum produto encontrado com o nome '%s'.\n", nome);
    }
}

void atualiza_quantidade(p_promo **cauda, int id, int nova_quantidade)
{
    if(*cauda == NULL)
    {
        printf("Não foi possível atualizar a quantidade, pois a lista está vazia.\n");
        return;
    }

    p_promo *atual = (*cauda)->prox;
    int encontrou = 0;

    do
    {
        if(atual->id == id)
        {
            atual->quantidade = nova_quantidade;
            encontrou = 1;
            break;
        }
        atual = atual->prox;
    } while (atual != (*cauda)->prox);
    
    if(encontrou != 1)
    {
        printf("ID não encontrado na lista.\n");
        return;
    }
}

int conta_lista(p_promo *cauda)
{
    if(cauda == NULL)
    {
        return 0;
    }

    p_promo *atual = cauda->prox;
    int qty_produtos = 0;

    do
    {
        qty_produtos++;
        atual = atual->prox;
    } while(atual != cauda->prox);

    return qty_produtos;
}

void exibe_lista(p_promo **cauda)
{
    if(*cauda == NULL)
    {
        printf("Não foi possível exibir a lista, pois está vazia.\n");
        return;
    }

    p_promo *atual = (*cauda)->prox;

    do
    {
        printf("ID: %d\n", atual->id);
        printf("Nome: %s\n", atual->nome);
        printf("Quantidade: %d\n", atual->quantidade);
        printf("Preço: R$ %.2f\n", atual->preco); 
        printf("Validade: %s\n", atual->validade);
        printf("------------------------\n");
        
        atual = atual->prox;
    } while(atual != (*cauda)->prox);
}

void limpa_lista(p_promo **cauda, lista_promo *lista)
{
    if(*cauda == NULL)
    {
        printf("A lista já se encontra vazia.\n");
        return;
    }

    p_promo *atual = (*cauda)->prox; 
    p_promo *proximo;

    (*cauda)->prox = NULL;

    while(atual != NULL)
    {
        proximo = atual->prox;
        free(atual);
        atual = proximo;
    }

    *cauda = NULL;
    
    if(lista != NULL)
    {
        lista->cauda = NULL;
    }
}

int main()
{
    p_promo *cauda = NULL;

    lista_promo lista;
    lista.cauda = cauda;
    lista.tamanho = 0;

    p_promo p1 = {1, "Arroz", 2, 6, "14/12", NULL};
    p_promo p2 = {2, "Feijao", 8, 2.50, "01/09", NULL};

    printf("Quantidade de produtos na lista: %d\n", conta_lista(cauda));

    insere_cabeca(&cauda, p1, &lista);

    printf("Quantidade de produtos na lista: %d\n", conta_lista(cauda));
    
    insere_cauda(&cauda, p2, &lista);

    printf("Quantidade de produtos na lista: %d\n", conta_lista(cauda));

    //remove_id(&cauda, 1, &lista);

    atualiza_quantidade(&cauda, 1, 23);
    atualiza_quantidade(&cauda, 2, 12);

    //exibe_lista(cauda);

    //busca_nome(cauda, "Arr");
    //busca_nome(cauda, "Fei");

    limpa_lista(&cauda, &lista);

    exibe_lista(&cauda);

    insere_cabeca(&cauda, p1, &lista);
    insere_cabeca(&cauda, p1, &lista);
    insere_cauda(&cauda, p2, &lista);

    exibe_lista(&cauda);

    return 0;
}