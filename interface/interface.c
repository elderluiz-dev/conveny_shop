#include <stdlib.h>
#include <stdio.h>

#include "interface.h"

int menu_principal(){
    int x;

    printf("\n===== LOJA DE CONVENIÊNCIAS =====\n");
    printf("1. Gerenciar Perecíveis (Simples)\n");
    printf("2. Gerenciar Não Perecíveis (Dupla)\n");
    printf("3. Gerenciar Promoções (Circular)\n");
    printf("0. Sair\n");
    printf("> ");

    scanf("%d%*c", &x);

    return x;
}

int menu_pereciveis(){
    int x;

    printf("\n===== PRODUTOS PERECÍVEIS =====\n");
    printf("1. Adicionar produto\n");
    printf("2. Remover produto\n");
    printf("3. Buscar produto\n");
    printf("4. Listar produtos\n");
    printf("5. Editar produto\n");
    printf("6. Contar produtos\n");
    printf("7. Limpar lista\n");
    printf("0. Voltar\n");
    printf("> ");
    
    scanf("%d%*c", &x);

    return x;
}

int menu_n_pereciveis(){
    int x;

    printf("\n===== PRODUTOS NÃO PERECÍVEIS =====\n");
    printf("1. Adicionar produto\n");
    printf("2. Remover produto\n");
    printf("3. Buscar produto\n");
    printf("4. Listar produtos\n");
    printf("5. Listar produtos reverso\n");
    printf("6. Editar produto\n");
    printf("7. Contar produtos\n");
    printf("8. Limpar lista\n");
    printf("0. Voltar\n");
    printf("> ");
    
    scanf("%d%*c", &x);

    return x;
}

int menu_promo(){
    int x;

    printf("\n===== PRODUTOS EM PROMOÇÃO =====\n");
    printf("1. Adicionar produto\n");
    printf("2. Remover produto\n");
    printf("3. Buscar produto\n");
    printf("4. Listar produtos\n");
    printf("5. Editar produto\n");
    printf("6. Contar produtos\n");
    printf("7. Limpar lista\n");
    printf("0. Voltar\n");
    printf("> ");

    scanf("%d%*c", &x);

    return x;
}

int submenu_adiciona_produto_circular()
{
    int x;

    printf("1. Adicionar produto no início\n");
    printf("2. Adicionar produto no fim\n");
    printf("0. Voltar");
    printf("> ");

    scanf("%d%*c", &x);

    return x;
}

int submenu_remove_produto_circular()
{
    int x;

    printf("1. Remover produto no início\n");
    printf("2. Remover produto no fim\n");
    printf("3. Remover produto por ID\n");
    printf("0. Voltar");
    printf("> ");

    scanf("%d%*c", &x);
    
    return x;
}

void limpa_terminal(){
    system("clear");
}
