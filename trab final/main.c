#include <stdio.h>
#include "declara_variaveis.h"
#include <stddef.h>

VOO *pvoo = NULL;
PASSAGEM *ppssgm = NULL;
PASSAGEIRO *ppssgr = NULL;
int opcao = 0, aux = 0, ind = 0;


int main(){
    menu();
}

void menu(){
        while(1){
        ind = 1;
        printf("\n----BEM VINDO---\n");
        printf("Escolha uma opção:\n");
        printf("1) Vôos\n");
        printf("2) Passagens\n");
        printf("3) Passageiros\n");
        printf("4) Relatórios\n");
        printf("5) Sair.\n");
        scanf("%d", &opcao);
        switch(opcao){
            case 1:
                menuVoo();
                break;
            case 2:
                menuPassagens();
                break;
            case 3:
                menuPassageiro();
                break;
            case 4:
                menuRelatorio();
                break;
            case 5:
                printf("Obrigado por voar conosco!\n");
                return;
                break;
            default:
                printf("Opção inválida.\n");
                break;
        }

    }
}
