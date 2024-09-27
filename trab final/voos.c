#include "declara_variaveis.h"
#include <stdio.h>
#include <stdlib.h>

void menuVoo(){
    int ind=1;
    while(ind){
        printf("\n---MENU VOO---\n");
        printf("Escolha uma opção:\n");
        printf("1) Cadastrar Vôo\n");
        printf("2) Alterar Vôo\n");
        printf("3) Excluir Vôo\n");
        printf("4) Buscar Vôo\n");
        printf("5) Ver Vôos\n");
        printf("6) Voltar\n");
        scanf("%d", &opcao);
        switch(opcao){
            case 1:
                cadastraVoo(&pvoo);
                break;
            case 2:
                printf("Insira o identificador do voo a ser alterado: ");
                scanf("%d", &aux);
                alterarVoo(&pvoo, aux);
                break;
            case 3:
                printf("Insira o identificador do voo a ser excluido: ");
                scanf("%d", &aux);
                excluirVoo(&pvoo, aux);
                break;
            case 4:
                printf("Insira o identificador do voo a ser buscado: ");
                scanf("%d", &aux);
                buscarVoo(pvoo, aux);
                break;
            case 5:
                lerVoo(pvoo);
                break;
            default:
                ind =0;
            break;
        }
    }
}


void alterarVoo(voo *ptr, int numero){
    int nao_achou = 1;
    if(*ptr == NULL || numero == 0){
        printf("Vôo não encontrado.\n");
        return;
    }
    if((*ptr)->identificador == numero){
        printf("\nIdentificador do vôo: %ld", (*ptr)->identificador);
        printf("\nInsira o novo identificador do vôo: ");
        scanf("%ld", &(*ptr)->identificador);
        printf("\nNumero da aeronave do vôo: %ld", (*ptr)->numero_aviao);
        printf("\nInsira o novo numero da aeronave do vôo: ");
        scanf("%ld", &(*ptr)->numero_aviao);
        printf("\nEmpresa do vôo: %s", (*ptr)->empresa);
        printf("\nInsira a nova empresa do vôo: ");
        getchar();
        fgets((*ptr)->empresa, 25, stdin);
        printf("\nOrigem do vôo: %s", (*ptr)->origem);
        printf("\nInsira a nova origem do vôo: ");
        fgets((*ptr)->origem, 50, stdin);
        printf("\nDestino do vôo: %s", (*ptr)->destino);
        printf("\nInsira o novo destino do vôo: ");
        fgets((*ptr)->destino, 50, stdin);
        printf("\nData de partida do vôo: ");
        printf("\nDia: %d", (*ptr)->data_saida.dia);
        printf("\nMes: %d", (*ptr)->data_saida.mes);
        printf("\nAno: %d", (*ptr)->data_saida.ano);
        printf("\nInsira a nova data de partida do vôo: ");
        printf("\nDia: ");
        scanf("%d", &(*ptr)->data_saida.dia);
        printf("Mes: ");
        scanf("%d", &(*ptr)->data_saida.mes);
        printf("Ano: ");
        scanf("%d", &(*ptr)->data_saida.ano);
        printf("\nHorario de partida do vôo:");
        printf("\nHora: ");
        if((*ptr)->horario_saida.hora < 10)
            printf("0");
        printf("%d", (*ptr)->horario_saida.hora);
        printf("\nMinuto: ");
        if((*ptr)->horario_saida.minuto < 10)
            printf("0");
        printf("%d", (*ptr)->horario_saida.minuto);
        printf("\nInsira o novo horario de partida do vôo:");
        printf("\nHora: ");
        scanf("%d", &(*ptr)->horario_saida.hora);
        printf("Minuto: ");
        scanf("%d", &(*ptr)->horario_saida.minuto);
        printf("Quantidade de passageiros do vôo: %d", (*ptr)->qtd_passageiros);
        printf("\nNova quantidade de passageiros do vôo: ");
        scanf("%d", &(*ptr)->qtd_passageiros);
        printf("\nAlterado com Sucesso\n");
        nao_achou = 0;
    }else
        alterarVoo(&(*ptr)->next, numero);
    if(nao_achou){
        printf("Não foi identificado o vôo. Por favor tente denovo.\n");
    }
}

void buscarVoo(voo ptr, int numero){
    if(ptr == NULL){
        printf("Vôo não cadastrado.\n");
        return;
    }
    if(numero == ptr->identificador){
        printf("Identificador do vôo: %ld\n", ptr->identificador);
        printf("Numero da aeronave do vôo: %ld\n", ptr->numero_aviao);
        printf("Empresa do vôo: %s\n", ptr->empresa);
        printf("Origem do vôo: %s\n", ptr->origem);
        printf("Destino do vôo: %s\n", ptr->destino);
        printf("Data de partida do vôo: %d/%d/%d\n", ptr->data_saida.dia, ptr->data_saida.mes, ptr->data_saida.ano);
        printf("Horario de partida do vôo: %d:%d\n", ptr->horario_saida.hora, ptr->horario_saida.minuto);
        printf("Quantidade de passageiros do vôo: %d\n", ptr->qtd_passageiros);
    }else
        buscarVoo(ptr->next, numero);
}


void excluirVoo(voo *ptr, int numero){
    int encontrado = 1;
    if(*ptr == NULL){
        printf("Vôo não cadastrado.");
        return;
    }
    if((*ptr)->identificador == numero){
        *ptr = (*ptr)->next;
        encontrado = 0;
    }else{
        excluirVoo(&(*ptr)->next, numero);
        }
    if(encontrado){
        printf("Não identificamos o vôo. Tente novamente.\n");
    }else{
        printf("Voo excluido com sucesso\n");
    }
}


void cadastraVoo(voo *ptr){
    if(*ptr == NULL){
        *ptr = (voo) malloc(sizeof(VOO));
        if(*ptr == NULL){
            printf("Erro ao alocar memória\n");
            return;
        }
        printf("\nInsira o identificador do vôo: ");
        scanf("%ld", &(*ptr)->identificador);
        printf("\nInsira o numero da aeronave do vôo: ");
        scanf("%ld", &(*ptr)->numero_aviao);
        printf("\nInsira a empresa do vôo: ");
        getchar();
        fgets((*ptr)->empresa, 25, stdin);
        printf("\nInsira a origem do vôo: ");
        fgets((*ptr)->origem, 50, stdin);
        printf("\nInsira o destino do vôo: ");
        fgets((*ptr)->destino, 50, stdin);
        printf("\nInsira a data de partida do vôo\n");
        printf("\nDia: ");
        scanf("%d", &(*ptr)->data_saida.dia);
        printf("\nMes: ");
        scanf("%d", &(*ptr)->data_saida.mes);
        printf("\nAno: ");
        scanf("%d", &(*ptr)->data_saida.ano);
        printf("\nInsira o horario de partida do vôo \n");
        printf("\nHora: ");
        scanf("%d", &(*ptr)->horario_saida.hora);
        printf("\nMinuto: ");
        scanf("%d", &(*ptr)->horario_saida.minuto);
        printf("\nQuantidade de passageiros do vôo: ");
        scanf("%d", &(*ptr)->qtd_passageiros);
        printf("\n\n");
    }else
        cadastraVoo(&(*ptr)->next);
        
}


void lerVoo(voo ptr){
    if(ptr == NULL){
        return;
    }else{
        printf("Identificador do vôo: %ld\n", ptr->identificador);
        printf("Numero da aeronave do vôo: %ld\n", ptr->numero_aviao);
        printf("Empresa do vôo: %s", ptr->empresa);
        printf("Origem do vôo: %s", ptr->origem);
        printf("Destino do vôo: %s", ptr->destino);
        printf("Data de partida do vôo: %d/%d/%d\n", ptr->data_saida.dia, ptr->data_saida.mes, ptr->data_saida.ano);
        printf("Horario de partida do vôo: ");
        if(ptr->horario_saida.hora < 10)
            printf("0");
        printf("%d:", ptr->horario_saida.hora);
        if(ptr->horario_saida.minuto < 10)
            printf("0");
        printf("%d\n", ptr->horario_saida.minuto);
        printf("Quantidade de passageiros do voo: %d\n", ptr->qtd_passageiros);
        printf("\n");
        lerVoo(ptr->next);
    }
 
}