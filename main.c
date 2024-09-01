// ARQUIVO MAIN IMPLEMENTAÇÃO AEROPORTO

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include "lib.h"


void main(void){
    
    int choice;
    printf("\n------BEM VINDO A FLYBENTIVI---------\n");
    printf("\nVamos ao menu de opções\n");
    printf("\nConsultar:\n");
    printf("\n1) Vôos\n");
    printf("2) Passageiros\n");
    printf("3) Passagem\n");
    printf("0) Sair\n");
    printf("Sua opção: ");
    

    while (scanf("%d",&choice))
    {
    switch (choice){
        case 1:
            printf("Menu 1\n");
            break;
        case 2:
            printf("Menu 2\n");
            break;
        case 3:
            printf("Menu 3\n");
            break;
        case 0:
            printf("Saindo...\n");
            exit(0);
        default:
            printf("Envie uma das opções anteriores!\n");
            continue;
        }
    }
}