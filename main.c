#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "produto.h"
#include "interface.h"

int main(){
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
            
        case 2:
            limpa_terminal();
            while(option != 0)
            {
                option = menu_n_pereciveis();
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