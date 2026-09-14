#pragma once

typedef struct nao_perecivel
{
    int id;
    char nome[50];
    int quantidade;
    float preco;
    char validade[20];
    struct nao_perecivel *prox;
    struct nao_perecivel *ante;
} p_nao_perecivel;

typedef struct lista_nao_pereciveis
{
    p_nao_perecivel *cabeca;
    int tamanho;
} lista_nao_pereciveis;

#include "produto.h"

ERROR_TYPE_T iniciar_list_dupla(lista_nao_pereciveis **lista);
ERROR_TYPE_T inserir_inicio_dupla(p_nao_perecivel novo_prod, p_nao_perecivel **cabeça);
ERROR_TYPE_T inserir_fim_dupla(p_nao_perecivel novo_prod, p_nao_perecivel **cabeça);
ERROR_TYPE_T remover_inicio_dupla(lista_nao_pereciveis *lista);
ERROR_TYPE_T remover_fim_dupla(lista_nao_pereciveis *lista);
ERROR_TYPE_T remover_id_dupla(lista_nao_pereciveis *lista, int id);
ERROR_TYPE_T buscar_dupla(lista_nao_pereciveis *lista, char *prod_busca);
ERROR_TYPE_T atualizar_dupla(lista_nao_pereciveis *lista, int id_prod);
ERROR_TYPE_T exibir_dupla(p_nao_perecivel *prod);
ERROR_TYPE_T exi_inver_dupla(p_nao_perecivel *prod, int temp);
ERROR_TYPE_T limpar_dupla(lista_nao_pereciveis **lista);