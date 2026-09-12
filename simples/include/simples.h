#pragma once

typedef struct perecivel
{
    int id;
    char nome[50];
    int quantidade;
    float preco;
    char validade[20];
    struct perecivel *prox;
} p_perecivel;

typedef struct lista_pereciveis
{
    p_perecivel *cabeca;
    int tamanho;
} lista_pereciveis;

#include "produto.h"

ERROR_TYPE_T criar_lista_pereciveis(lista_pereciveis **lista);

ERROR_TYPE_T adicionar_perecivel_inicio(p_perecivel novo_perecivel, lista_pereciveis* *lista);
ERROR_TYPE_T adicionar_perecivel_fim(p_perecivel novo_perecivel, lista_pereciveis* *lista);

ERROR_TYPE_T exibir_pereciveis(p_perecivel* atual);

ERROR_TYPE_T remover_perecivel_inicio(lista_pereciveis* *lista);
ERROR_TYPE_T remover_perecivel_final(lista_pereciveis* *lista);
ERROR_TYPE_T remover_perecivel_id(lista_pereciveis* *lista, int id);

ERROR_TYPE_T esvaziar_pereciveis(lista_pereciveis* *lista);
ERROR_TYPE_T editar_qtd_perecivel(lista_pereciveis* *lista, int id);
ERROR_TYPE_T buscar_perecivel(lista_pereciveis* lista, char *substr);