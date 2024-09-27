#include "declara_variaveis.h"
#include <stdio.h>
#include <stdlib.h>

void menuPassagens(){
    int ind=1;
    while(ind){
        printf("\n---MENU PASSAGEM---\n");
        printf("Escolha uma opção:\n");
        printf("1) Cadastrar Passagem\n");
        printf("2) Alterar Passagem\n");
        printf("3) Excluir Passagem\n");
        printf("4) Buscar Passagem\n");
        printf("5) Ver Passagens\n");
        printf("6) Voltar\n");
        scanf("%d", &opcao);
        switch(opcao){
            case 1:
                cadastraPassagens(&ppssgm);
                break;
            case 2:
                lerPassagens(ppssgm);
                printf("Insira o número da passagem a ser alterada: ");
                scanf("%d", &aux);
                alterarPassagens(&ppssgm, aux);
                break;
            case 3:
                printf("Insira o número da passagem a ser excluida: ");
                scanf("%d", &aux);
                excluirPassagens(&ppssgm, aux);
                break;
            case 4:
                printf("Insira o número da passagem a ser buscada: ");
                scanf("%d", &aux);
                buscarPassagens(ppssgm, aux);
            case 5:
                lerPassagens(ppssgm);
                break;
            default:
                ind = 0;
                break;
        }
    }
}

void alterarPassagens(passagem *ptr, int numero){
    if(*ptr == NULL || numero == 0){
        printf("Passagem não cadastrada.\n");
        return;
    }
    if((*ptr)->numero == numero){
        printf("\nNúmero da passagem: %d", (*ptr)->numero);
        printf("\nInsira o novo número da passagem: ");
        scanf("%d", &(*ptr)->numero);
        printf("\nIdentificador do passageiro: %d", (*ptr)->identificador_passageiro);
        printf("\nInsira o novo identificador do passageiro: ");
        scanf("%d", &(*ptr)->identificador_passageiro);
        printf("\nIdentificador do voo: %d", (*ptr)->identificador_voo);
        printf("\nInsira o novo identificador do voo: ");
        scanf("%d", &(*ptr)->identificador_voo);
        printf("\nValor da passagem: %d", (*ptr)->valor);
        printf("\nInsira o novo valor: ");
        scanf("%d", &(*ptr)->valor);
        printf("\nData da venda: %d/%d/%d", (*ptr)->data.dia, (*ptr)->data.mes, (*ptr)->data.ano);
        printf("\nInsira a nova data da venda:");
        printf("\nDia: ");
        scanf("%d", &(*ptr)->data.dia);
        printf("\nMes: ");
        scanf("%d", &(*ptr)->data.mes);
        printf("\nAno: ");
        scanf("%d", &(*ptr)->data.ano);
        printf("\nAlterado com Sucesso\n");
    }else
        alterarPassagens(&(*ptr)->next, numero);
}

void buscarPassagens(passagem ptr, int numero){
    if(ptr == NULL){
        printf("Passagem não cadastrada.\n");
        return;
    }
    if(numero == ptr->numero){
        printf("Numero da passagem: %d\n", ptr->numero);
        printf("Identificador de passageiro: %d\n", ptr->identificador_passageiro);
        printf("Identificador de voo: %d\n", ptr->identificador_voo);
        printf("Valor: %d\n", ptr->valor);
        printf("Data da venda: %d/%d/%d\n", ptr->data.dia, ptr->data.mes, ptr->data.ano);
    }else
        buscarPassagens(ptr->next, numero);
}


void excluirPassagens(passagem *ptr, int numero){
    int encontrado = 1;
    if(*ptr == NULL){
        printf("Passagem não cadastrada.\n");
        return;
    }
    if((*ptr)->numero = numero){
        *ptr = (*ptr)->next;
        encontrado = 0;
    }else{
        excluirPassagens(&(*ptr)->next, numero);
    }
    if(encontrado){
        printf("Passagem não encontrada. Tente novamente.\n");
    }else{
        printf("Passagem excluida com sucesso!\n");
    }
}


void cadastraPassagens(passagem *ptr){
    if(*ptr == NULL){
        *ptr = (passagem) malloc(sizeof(PASSAGEM));
        if(*ptr == NULL){
            printf("Erro ao alocar memória\n");
            return;
        }
        printf("\nInsira o número da passagem: ");
        scanf("%d", &(*ptr)->numero);
        printf("\nInsira o identificador do passageiro: ");
        scanf("%d", &(*ptr)->identificador_passageiro);
        printf("\nInsira o identificador do voo: ");
        scanf("%d", &(*ptr)->identificador_voo);
        printf("\nInsira o valor: ");
        scanf("%d", &(*ptr)->valor);
        printf("\nInsira a data da venda\n");
        printf("\nDia: ");
        scanf("%d", &(*ptr)->data.dia);
        printf("\nMes: ");
        scanf("%d", &(*ptr)->data.mes);
        printf("\nAno: ");
        scanf("%d", &(*ptr)->data.ano);
        printf("\n");
    }else
        cadastraPassagens(&(*ptr)->next);
    printf("Passagem adcionada com sucesso!\n");

}


void lerPassagens(passagem ptr){
    if(ptr == NULL){
        return;
    }

    printf("Número da passagem: %d\n", ptr->numero);
    printf("Identificador de passageiro: %d\n", ptr->identificador_passageiro);
    printf("Identificador de voo: %d\n", ptr->identificador_voo);
    printf("Valor: %d\n", ptr->valor);
    printf("Data da venda: %d/%d/%d\n", ptr->data.dia, ptr->data.mes, ptr->data.ano);
    printf("\n");

    lerPassagens(ptr->next);
}