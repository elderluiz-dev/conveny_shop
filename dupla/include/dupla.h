#pragma once

#include "produto.h"

typedef struct nao_perecivel
{
    int id;
    char nome[50];
    int quantidade;
    float preco;
    char validade[10];
    struct nao_perecivel *prox;
    struct nao_perecivel *ante;
} p_nao_perecivel;

typedef struct lista_nao_pereciveis
{
    p_nao_perecivel *cabeca;
    int tamanho;
} lista_nao_pereciveis;

ERROR_TYPE_T iniciar_lista_nperecivel(lista_nao_pereciveis** lista);
ERROR_TYPE_T inserir_inicio(p_nao_perecivel novo_prod, p_nao_perecivel** prod);
ERROR_TYPE_T atualizar_quant(p_nao_perecivel* prod, int id_prod);
ERROR_TYPE_T exibir(p_nao_perecivel* prod);
ERROR_TYPE_T exi_remover(p_nao_perecivel* prod);
ERROR_TYPE_T exi_inverso(p_nao_perecivel* prod);