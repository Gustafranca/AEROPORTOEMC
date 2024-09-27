#include "declara_variaveis.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void menuRelatorio(){

    int ind = 1;
    while(ind){
        printf("\n---MENU RELATORIOS---\n");
        printf("Escolha uma opção:\n");
        printf("1) Quantidade de passagens vendidas por voo\n");
        printf("2) Quantidade de voos por empresa\n");
        printf("3) Lista de passageiros por voo\n");
        printf("4) Voltar\n");
        scanf("%d",&opcao);
        switch (opcao)
        {
        case 1:
            passagens_voos(ppssgm);
            break;
        case 2:
            voos_empresas(pvoo);
            break;
        case 3:
            passageiros_voos(ppssgm);
            break;
        default:
            ind = 0;
            break;
        }
    }
}

void passagens_voos(passagem ptr){
    int aux = 1;
    int indiceVoos = 0;
    long voos[100] = {0};
    int qntd[100] = {0};
    while(ptr != NULL){
        aux = 1;
        for(int i=0; i<=indiceVoos; i++){
            if(ptr->identificador_voo == voos[i]){
                qntd[i] += 1;
                aux = 0;
                break;
            }
        }
        if(aux){
            voos[indiceVoos] = ptr->identificador_voo;
            qntd[indiceVoos] = 1;
            indiceVoos++;
        }
        ptr = ptr->next;
    }
    for(int i=0; voos[i] != 0; i++)
        printf("\nPassagens vendidas para o voo de identificador %ld: %d", voos[i], qntd[i]);
}

void voos_empresas(voo ptr){
    int aux = 1;
    int indice = 0;
    char empresas[50][25];
    int qntd[100] = {0};
    while(ptr != NULL){
        aux = 1;
        for(int i=0; i<=indice; i++){
            if(strcmp(ptr->empresa, empresas[i]) == 0){
                qntd[i] += 1;
                aux = 0;
                break;
            }
        }
        if(aux){
            strcpy(empresas[indice], ptr->empresa);
            qntd[indice] = 1;
            indice++;
        }
        ptr = ptr->next;
    }
    printf("\nVoos vendidos por empresas:");
    for(int i=0; qntd[i] != 0; i++)
        printf("\n%s%d Voos", empresas[i], qntd[i]);
}


void passageiros_voos(passagem ptr){
    int aux = 1;
    int indice = 0;
    long voos[100] = {0};
    long passageiros[100][100] = {0};
    while(ptr != NULL){
        aux = 1;
        for(int i=0; i<=indice && aux; i++)
            if(ptr->identificador_voo == voos[i])
                for(int j=0; j<100; j++)
                    if(passageiros[i][j] == 0){
                        passageiros[i][j] = ptr->identificador_passageiro;
                        aux = 0;
                        break;
                    }
        if(aux){
            voos[indice] = ptr->identificador_voo;
            passageiros[indice][0] = ptr->identificador_passageiro;
            indice++;
        }
        ptr = ptr->next;
    }
    for(int i=0; voos[i] != 0; i++){
        printf("\nIdentificadores dos passageiros do voo de identificador %ld:", voos[i]);
        for(int j=0; passageiros[i][j] != 0; j++)
            printf("\n%ld", passageiros[i][j]);
    }
    printf("\n");
}