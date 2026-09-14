#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "simples.h"
#include "dupla.h"
#include "circular.h"

#include "interface.h"
#include "produto.h"

int main(){
    lista_pereciveis *lista_pere = NULL;
    criar_lista_pereciveis(&lista_pere);
    lista_nao_pereciveis *list_nao_pereci = NULL;

    lista_promo *lista_promocao = malloc(sizeof(lista_promo));
    if (lista_promocao != NULL)
    {
        lista_promocao->cauda = NULL;
        lista_promocao->tamanho = 0;
    }
    else
    {
        printf("Erro de inicialização da lista de promoções!\n");
        return 1;
    }

    p_promo *cauda_promo = NULL;

    int id_nao_perecivel = 1;
    int id_promocao = 1;
    int id = 1;

    while(1)
    {
        limpa_terminal();
        int choose = menu_principal();
        int option = -1;
        
        switch(choose)
        {
            case 1:
            {
                limpa_terminal();
                while(option != 0)
                {
                    option = menu_pereciveis();
                    switch(option)
                    {
                    case 1:
                        limpa_terminal();
                        p_perecivel novo = {};

                        novo.id = id;

                        printf("Nome: ");
                        fgets(novo.nome, sizeof(novo.nome), stdin);
                        novo.nome[strcspn(novo.nome, "\n")] = '\0';

                        printf("Quantidade: ");
                        scanf("%d", &novo.quantidade);
                        getchar();

                        if(novo.quantidade <= 0)
                        {
                            printf("Quantidade inválida. Operação cancelada.");
                            break;
                        }

                        printf("Preço: ");
                        scanf("%f", &novo.preco);
                        getchar();

                        if(novo.preco <= 0)
                        {
                            printf("Valor inválido. Operação cancelada.");
                            break;
                        }

                        printf("Validade: ");
                        fgets(novo.validade, sizeof(novo.validade), stdin);
                        novo.validade[strcspn(novo.validade, "\n")] = '\0';

                        novo.prox = NULL;
                        int sub_select_add = submenu_adiciona_produto_perecivel();
                        switch(sub_select_add)
                        {
                        case 1:
                            adicionar_perecivel_inicio(novo, &lista_pere);
                            id++;
                            limpa_terminal();
                            printf("Produto adicionado com sucesso!");
                            break;

                        case 2:
                            adicionar_perecivel_fim(novo, &lista_pere);
                            id++;
                            limpa_terminal();
                            printf("Produto adicionado com sucesso!");
                            break;
                        
                        case 0:
                            limpa_terminal();
                            break;

                        default:
                            printf("Opção inválida\n");
                            break;
                        }

                        break;
                    
                    case 2:
                        limpa_terminal();

                        if(lista_pere->tamanho == 0){
                            printf("Lista vazia\n");
                            break;
                        }

                        int sub_select_rem = submenu_remove_produto_perecivel();
                        switch(sub_select_rem)
                        {
                        case 1:
                            remover_perecivel_inicio(&lista_pere);
                            break;

                        case 2:
                            remover_perecivel_final(&lista_pere);
                            break;

                        case 3:
                            int rem_id;
                            limpa_terminal();
                            printf("Digite o ID do produto que quer remover: ");
                            scanf("%d", &rem_id);
                            getchar();
                            remover_perecivel_id(&lista_pere, rem_id);
                            break;

                        case 0:
                            limpa_terminal();
                            break;

                        default:
                            limpa_terminal();
                            printf("Opção inválida\n");
                            break;
                        }

                        break;

                    case 3:
                        limpa_terminal();
                        
                        if(lista_pere->tamanho == 0){
                            printf("Lista vazia\n");
                            break;
                        }

                        char substr[50];

                        printf("Digite o nome do produto: ");
                        fgets(substr, sizeof substr, stdin);
                        substr[strcspn(substr, "\n")] = '\0';

                        buscar_perecivel(lista_pere, substr);
                        
                        break;

                    case 4:
                        limpa_terminal();
                        if(lista_pere->tamanho == 0)
                        {
                            printf("Lista vazia\n");
                            break;
                        }

                        printf("\n== LISTA DE PRODUTOS PERECIVEIS CADASTRADOS ==\n");
                        exibir_pereciveis(lista_pere->cabeca);

                        break;

                    case 5:
                        limpa_terminal();
                        if(lista_pere->tamanho == 0)
                        {
                            printf("Lista vazia\n");
                            break;
                        }

                        int id;

                        printf("Digite o ID do produto a ser editado: ");
                        scanf("%d", &id);
                        getchar();

                        editar_qtd_perecivel(&lista_pere, id);
                        break;

                    case 6:
                        limpa_terminal();
                        printf("Quantidade de produtos perecíveis: %d\n", lista_pere->tamanho);
                        break;

                    case 7:
                        limpa_terminal();
                        if(lista_pere->tamanho == 0)
                        {
                            printf("Lista vazia\n");
                            break;
                        }

                        char verify[20];
                        
                        printf("Tem certeza que deseja esvaziar a lista? Esta ação é irreversível!\n");
                        printf("Para confirmar o esvaziamento da lista digite CONFIRMO.\n> ");
                        
                        fgets(verify, sizeof(verify), stdin);
                        verify[strcspn(verify, "\n")] = '\0';

                        limpa_terminal();

                        if(strcmp(verify, "CONFIRMO") == 0 || strcmp(verify, "confirmo") == 0){
                            esvaziar_pereciveis(&lista_pere);
                            printf("Lista esvaziada!\n");
                        }else{
                            printf("Operação cancelada pelo usuário.");
                        }

                        break;

                    case 0:
                        limpa_terminal();
                        break;
                    
                    default:
                        limpa_terminal();
                        printf("Opção inválida, tente novamente.\n");
                        break;;
                    }
                }

                break;
            }

            case 2:
            {
                limpa_terminal();
                while(option != 0)
                {
                    ERROR_TYPE_T err;
                    int id_temp;
                    option = menu_n_pereciveis();
                    switch(option)
                    {
                        case 1:
                        {
                            p_nao_perecivel nov_item = {};
                            if(list_nao_pereci == NULL)
                            {
                                err = iniciar_list_dupla(&list_nao_pereci);
                                if(err == ALLOCATION_ERROR)
                                {
                                    printf("Não foi possível iniciar a lista: Erro na alocação de memória.\n");
                                    break;
                                }
                            }

                            limpa_terminal();

                            nov_item.id = id_nao_perecivel;
                            printf("Preencha as informações abaixo: \n");
                            printf("Nome do item: ");

                            fgets(nov_item.nome, sizeof(nov_item.nome), stdin);
                            nov_item.nome[strcspn(nov_item.nome, "\n")] = '\0';

                            printf("Quantidade: ");
                            scanf("%d", &nov_item.quantidade);
                            while(nov_item.quantidade <= 0)
                            {
                                printf("Quantidade inválida!\n");
                                printf("Digite novamente: ");
                                scanf("%d", &nov_item.quantidade);
                            }

                            printf("Preco: ");
                            scanf("%f", &nov_item.preco);
                            while(nov_item.preco <= 0)
                            {
                                printf("Preço inválido!\n");
                                printf("Digite novamente: ");
                                scanf("%f", &nov_item.preco);
                            }    

                            printf("Validade: ");

                            while (getchar() != '\n' && getchar() != EOF);
                            fgets(nov_item.validade, sizeof(nov_item.validade), stdin);
                            nov_item.validade[strcspn(nov_item.validade, "\n")] = '\0';

                            if(list_nao_pereci->cabeca == NULL)
                            {
                                err = inserir_inicio_dupla(nov_item, &list_nao_pereci->cabeca);
                                if(err == ALLOCATION_ERROR)
                                {
                                    printf("\nNão foi possível adicionar o produto! Erro de alocação de memória.\n");
                                    break;
                                }

                                limpa_terminal();
                                printf("Produto adicionado com sucesso\n");
                                id_nao_perecivel++;
                                list_nao_pereci->tamanho++;
                                break;
                            }

                            limpa_terminal();
                            int sub_menu = submenu_adiciona_produto_nperecivel();

                            while (sub_menu != 0)
                            {
                                switch (sub_menu)
                                {
                                    case 1:
                                    {
                                        limpa_terminal();

                                        err = inserir_inicio_dupla(nov_item, &list_nao_pereci->cabeca);
                                        if(err == ALLOCATION_ERROR)
                                        {
                                            printf("\nNão foi possível adicionar o produto! Erro de alocação de memória.\n");
                                            break;
                                        }

                                        limpa_terminal();
                                        printf("Produto adicionado com sucesso\n");
                                        id_nao_perecivel++;
                                        list_nao_pereci->tamanho++;

                                        break;
                                    }

                                    case 2:
                                    {
                                        limpa_terminal();

                                        err = inserir_fim_dupla(nov_item, &list_nao_pereci->cabeca);

                                        if(err == ALLOCATION_ERROR)
                                        {
                                            limpa_terminal();
                                            printf("Não foi possível adicionar o produto! Erro de alocação de memória.\n");
                                            break;
                                        }

                                        limpa_terminal();
                                        printf("Produto adicionado com sucesso\n");
                                        id_nao_perecivel++;
                                        list_nao_pereci->tamanho++;
                                        
                                        break;
                                    }

                                    case 0:
                                    {
                                        limpa_terminal();
                                        break;
                                    }
                                    default:
                                    {
                                        limpa_terminal();

                                        printf("Opção inválida, tente novamente.\n");
                                        break;
                                    }
                                }

                                break;
                            }

                            break;
                        }

                        case 2:
                        {
                            limpa_terminal();

                            int sub_menu = submenu_remove_produto_nperecivel();

                            while (sub_menu != 0)
                            {
                                switch (sub_menu)
                                {
                                    case 1:
                                    {
                                        limpa_terminal();
                                        err = remover_inicio_dupla(list_nao_pereci);

                                        if(err == SIZE_ERROR)
                                        {
                                            printf("A lista está vazia!\n");
                                            break;
                                        }

                                        printf("Produto removido!\n");
                                        break;
                                    }

                                    case 2:
                                    {
                                        limpa_terminal();
                                        err = remover_fim_dupla(list_nao_pereci);

                                        if(err == SIZE_ERROR)
                                        {
                                            printf("A lista está vazia!\n");

                                            break;
                                        }

                                        printf("Produto removido!\n");

                                        break;
                                    }

                                    case 3:
                                    {
                                        limpa_terminal();

                                        printf("Digite o id que deseja remover: ");
                                        scanf("%d", &id_temp);

                                        err = remover_id_dupla(list_nao_pereci, id_temp);

                                        if(err == SIZE_ERROR)
                                        {
                                            limpa_terminal();
                                            printf("A lista está vazia!\n");

                                            break;
                                        }
                                        if(err == ID_NOTFOUND)
                                        {
                                            limpa_terminal();
                                            printf("Id não encontrado.\n");

                                            break;
                                        }

                                        printf("Produto removido!\n");
                                        break;
                                    }

                                    case 0:
                                    {
                                        limpa_terminal();
                                        break;
                                    }

                                    default:
                                    {
                                        limpa_terminal();

                                        printf("Opção inválida, tente novamente.\n");
                                        break;
                                    }
                                }

                                break;
                            }

                            break;
                        }

                        case 3:
                        {
                            limpa_terminal();
                            char prod_busca[50];

                            if(list_nao_pereci == NULL || list_nao_pereci->tamanho == 0)
                            {
                                printf("A lista está vazia.\n");
                                break;
                            }

                            printf("Digite o nome: ");
                            fgets(prod_busca, sizeof(prod_busca), stdin);
                            prod_busca[strcspn(prod_busca, "\n")] = '\0';

                            err = buscar_dupla(list_nao_pereci, prod_busca);

                            break;
                        }

                        case 4:
                        {
                            limpa_terminal();

                            if(list_nao_pereci == NULL || list_nao_pereci->tamanho == 0)
                            {
                                printf("A lista está vazia.\n");
                                break;
                            }

                            exibir_dupla(list_nao_pereci->cabeca);

                            break;
                        }

                        case 5:
                        {
                            limpa_terminal();

                            if(list_nao_pereci == NULL || list_nao_pereci->tamanho == 0)
                            {
                                printf("A lista está vazia.\n");
                                break;
                            }

                            exi_inver_dupla(list_nao_pereci->cabeca, 1);

                            break;
                        }

                        case 6:
                        {
                            limpa_terminal();

                            if(list_nao_pereci == NULL || list_nao_pereci->tamanho == 0)
                            {
                                printf("A lista está vazia.\n");
                                break;
                            }

                            printf("Digite o id do produto que deseja editar: ");
                            scanf("%d", &id_temp);

                            err = atualizar_dupla(list_nao_pereci, id_temp);

                            if(err == ID_NOTFOUND)
                            {
                                limpa_terminal();
                                printf("Id não encontrado!\n");
                                break;
                            }

                            break;
                        }

                        case 7:
                        {
                            limpa_terminal();
                            if(list_nao_pereci == NULL || list_nao_pereci->tamanho == 0)
                            {
                                printf("A lista está vazia.\n");
                                break;
                            }
                            
                            printf("Quantidade de produtos não perecíveis: %d\n", list_nao_pereci->tamanho);

                            break;
                        }

                        case 8:
                        {
                            limpa_terminal();

                            err = limpar_dupla(&list_nao_pereci);
                            if(err == SIZE_ERROR)
                            {
                                printf("Voce ainda não possui uma lista!\n");
                                break;
                            }
                            printf("A lista foi limpa!\n");

                            break;
                        }

                        case 0:
                        {
                            break;
                        }

                        default:
                        {
                            limpa_terminal();
                            printf("Opção inválida.");
                            break;
                        }
                    }
                }
                
                break;
            }

            case 3:
            {
                limpa_terminal();
                while(option != 0)
                {
                    option = menu_promo();
                    switch(option)
                    {
                        case 1:
                        {
                            limpa_terminal();
                            int sub_option = submenu_adiciona_produto_circular();

                            while(sub_option != 0)
                            {
                                switch(sub_option)
                                {
                                    case 1:
                                    {
                                        limpa_terminal();
                                        p_promo novo_produto = {0};

                                        novo_produto.id = id_promocao;
                                        id_promocao++;

                                        printf("Digite o nome do produto: ");

                                        fgets(novo_produto.nome, sizeof(novo_produto.nome), stdin);
                                        novo_produto.nome[strcspn(novo_produto.nome, "\n")] = '\0';

                                        printf("Digite a quantidade do produto: ");
                                        scanf("%d", &novo_produto.quantidade);
                                        
                                        printf("Digite o preço do produto: ");
                                        scanf("%f", &novo_produto.preco);
                                        
                                        printf("Digite a data de validade do produto: ");

                                        int c;
                                        while ((c = getchar()) != '\n' && c != EOF);
                                        fgets(novo_produto.validade, sizeof(novo_produto.validade), stdin);
                                        novo_produto.validade[strcspn(novo_produto.validade, "\n")] = '\0';

                                        novo_produto.prox = NULL;

                                        circular_insere_cabeca(&cauda_promo, novo_produto, lista_promocao);
                                        break;
                                    }

                                    case 2:
                                    {
                                        limpa_terminal();
                                        p_promo novo_produto = {0};
                                        
                                        novo_produto.id = id_promocao;
                                        id_promocao++;

                                        printf("Digite o nome do produto: ");

                                        fgets(novo_produto.nome, sizeof(novo_produto.nome), stdin);
                                        novo_produto.nome[strcspn(novo_produto.nome, "\n")] = '\0';

                                        printf("Digite a quantidade do produto: ");
                                        scanf("%d", &novo_produto.quantidade);
                                        
                                        printf("Digite o preço do produto: ");
                                        scanf("%f", &novo_produto.preco);
                                        
                                        printf("Digite a data de validade do produto: ");

                                        int c;
                                        while ((c = getchar()) != '\n' && c != EOF);
                                        fgets(novo_produto.validade, sizeof(novo_produto.validade), stdin);
                                        novo_produto.validade[strcspn(novo_produto.validade, "\n")] = '\0';

                                        novo_produto.prox = NULL;

                                        circular_insere_cauda(&cauda_promo, novo_produto, lista_promocao);
                                        break;
                                    }

                                    case 0:
                                    {
                                        limpa_terminal();
                                        break;
                                    }

                                    default:
                                    {
                                        limpa_terminal();
                                        printf("A Opção selecionada é inválida.\n");
                                        break;
                                    }
                                }

                                break;
                            }

                            break;
                        }

                        case 2:
                        {
                            int sub_option = submenu_remove_produto_circular();

                            limpa_terminal();
                            while(sub_option != 0)
                            {
                                switch(sub_option)
                                {
                                    case 1:
                                    {
                                        circular_remove_cabeca(&cauda_promo);
                                        break;
                                    }

                                    case 2:
                                    {
                                        circular_remove_cauda(&cauda_promo, lista_promocao);
                                        break;
                                    }

                                    case 3:
                                    {
                                        limpa_terminal();
                                        int id_produto = 0;

                                        if(cauda_promo == NULL)
                                        {
                                            printf("Não foi possível realizar a remoção pois a lista está vazia\n");
                                            break;
                                        }
                                        
                                        printf("Digite o ID do produto a ser removido: ");
                                        scanf("%d", &id_produto);
                                        
                                        circular_remove_id(&cauda_promo, id_produto, lista_promocao);
                                        

                                        break;
                                    }
                                    
                                    case 0:
                                    {
                                        limpa_terminal();
                                        break;
                                    }

                                    default:
                                    {
                                        limpa_terminal();
                                        printf("A Opção selecionada é inválida.\n");
                                        break;
                                    }
                                }
                                break;
                            }
                            break;
                        }
                        
                        case 3:
                        {
                            limpa_terminal();

                            if(cauda_promo == NULL)
                            {
                                printf("Não foi possível buscar o produto, pois a lista está vazia.\n");
                                break;
                            }

                            char nome_produto[50];

                            printf("Digite o nome do produto a ser buscado: ");

                            fgets(nome_produto, sizeof(nome_produto), stdin);
                            nome_produto[strcspn(nome_produto, "\n")] = '\0';

                            circular_busca_nome(cauda_promo, nome_produto);
                            break;
                        }
                        
                        case 4:
                        {
                            limpa_terminal();
                            circular_exibe_lista(&cauda_promo);
                            break;
                        }

                        case 5:
                        {
                            limpa_terminal();

                            int id_produto;
                            int nova_quantidade;

                            if(cauda_promo == NULL)
                            {
                                printf("Não foi possível atualizar a quantidade, pois a lista está vazia.\n");
                                break;
                            }

                            printf("Digite o ID do produto: ");
                            scanf("%d", &id_produto);

                            printf("Digite a nova quantidade do produto: ");
                            scanf("%d", &nova_quantidade);

                            circular_atualiza_quantidade(&cauda_promo, id, nova_quantidade);
                            break;
                        }
                        
                        case 6:
                        {
                            limpa_terminal();
                            int tamanho_lista = circular_conta_lista(cauda_promo);
                            printf("O tamanho atual da lista de promoções é de: %d\n", tamanho_lista);
                            break;
                        }

                        case 7:
                        {
                            limpa_terminal();
                            circular_limpa_lista(&cauda_promo, lista_promocao);
                            break;
                        }
                        
                        case 0:
                        {
                            limpa_terminal();
                            break;
                        }

                        default:
                        {
                            limpa_terminal();
                            printf("A Opção selecionada é inválida.\n");
                            break;
                        }
                    }
                }

                break;
            }

            case 0:
            {
                limpa_terminal();
                printf("O programa foi encerrado pelo usuário.\n");

                esvaziar_pereciveis(&lista_pere);
                if(list_nao_pereci != NULL){
                    limpar_dupla(&list_nao_pereci);
                }
                circular_limpa_lista(&cauda_promo, lista_promocao);

                free(lista_pere);
                free(lista_promocao);
                return 0;
            }

            default:
            {
                limpa_terminal();
                printf("A Opção selecionada é inválida.\n");
                break;
            }
        }
    }
}