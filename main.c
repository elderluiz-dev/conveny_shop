#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dupla/dupla.h"
#include "simples/simples.h"
#include "interface/interface.h"
#include "produto.h"

int main(){
    lista_pereciveis* lista_pere = criar_lista_pereciveis();
    lista_nao_pereciveis* list_nao_pereci = NULL;
    int id_nao_perecivel = 1;
    int id = 1;

    while(1)
    {
        limpa_terminal();
        int choose = menu_principal();
        int option = -1;
        
        switch(choose)
        {
        case 1:
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
                    adicionar_perecivel(novo, &lista_pere);

                    id++;
                    limpa_terminal();
                    printf("Produto adicionado com sucesso!");
                    break;
                
                case 2:
                    int rem_id;
                    limpa_terminal();
                    printf("Digite o ID do produto que quer remvoer: ");
                    scanf("%d", &rem_id);
                    getchar();
                    remover_perecivel(&lista_pere, rem_id);
                    break;

                case 3:
                    limpa_terminal();
                    
                    if(lista_pere->tamanho == 0){
                        printf("lista_pere vazia!");
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
                        printf("Lista vazia");
                        break;
                    }

                    printf("\n== LISTA DE PRODUTOS PERECIVEIS CADASTRADOS ==\n");
                    exibir_pereciveis(lista_pere->cabeca);

                    break;

                case 5:
                    int id;
                    limpa_terminal();

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
                    char verify[20];
                    
                    printf("Tem certeza que deseja esvaziar a lista? Esta ação é irreversível!\n");
                    printf("Para confirmar o esvaziamento da lista digite CONFIRMO.\n> ");
                    
                    fgets(verify, sizeof(verify), stdin);
                    verify[strcspn(verify, "\n")] = '\0';

                    if(strcmp(verify, "CONFIRMO") == 0 || strcmp(verify, "confirmo") == 0){
                        esvaziar_pereciveis(&lista_pere);
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
            
        case 2:
            limpa_terminal();
            while(option != 0)
            {
                ERROR_TYPE_T tratamento;
                option = menu_n_pereciveis();
                switch(option)
                {
                case 1:
                    p_nao_perecivel nov_item = {};
                    if(list_nao_pereci == NULL)
                    {
                        iniciar_lista_nperecivel(&list_nao_pereci);
                        if(list_nao_pereci == NULL)
                        {
                            break;
                        }
                    }

                    limpa_terminal();

                    nov_item.id = id_nao_perecivel;
                    printf("\nPreencha as informações abaixo: \n");
                    printf("Nome do item: ");

                    fgets(nov_item.nome, sizeof(nov_item.nome), stdin);
                    nov_item.nome[strcspn(nov_item.nome, "\n")] = '\0';
                    
                    printf("Quantidade: ");
                    scanf("%d", &nov_item.quantidade);
                    while(nov_item.quantidade <= 0)
                    {
                        printf("Preco invalido!\n");
                        printf("Digite novamente: ");
                        scanf("%d", &nov_item.quantidade);
                    }
                    
                    printf("Preco: ");
                    scanf("%f", &nov_item.preco);
                    while(nov_item.preco <= 0)
                    {
                        printf("Preco invalido!\n");
                        printf("Digite novamente: ");
                        scanf("%f", &nov_item.preco);
                    }    

                    printf("Validade: ");

                    while (getchar() != '\n' && getchar() != EOF);
                    fgets(nov_item.validade, sizeof(nov_item.validade), stdin);
                    nov_item.validade[strcspn(nov_item.validade, "\n")] = '\0';

                    tratamento = inserir(nov_item, &list_nao_pereci->cabeca);
                        
                    if(tratamento == ALLOCATION_ERROR) break;

                    printf("\nProduto adicionado com sucesso\n");
                    id_nao_perecivel++;
                    list_nao_pereci->tamanho++;
                    
                    break;
                
                case 2:
                    limpa_terminal();

                    break;

                case 4:
                    limpa_terminal();
                    exibir(list_nao_pereci->cabeca);
                    break;

                case 0:
                    break;
                
                default:
                    limpa_terminal();
                    printf("Opção inválida.");
                    break;
                }
            }
            
            break;
        
        case 3:
            limpa_terminal();
            while(option != 0)
            {
                option = menu_promo();
                switch(option)
                {
                case 1:
                    limpa_terminal();
                    printf("Algo\n");
                    break;

                case 0:
                    break;
                
                default:
                    limpa_terminal();
                    printf("Opção inválida.");
                    break;
                }
            }
            
            break;
        
        case 0:
            limpa_terminal();
            printf("O usuário encerrou o programa.\n");
            return 0;

        default:
            printf("Opção inválida.");
            break;
        }
    }
    
}