#include "declara_variaveis.h"
#include <stdio.h>
#include <stdlib.h>

void menuPassageiro(){
    int ind = 1;
    while(ind){
        printf("\n---MENU PASSAGEIRO---\n");
        printf("Escolha uma opção:\n");
        printf("1) Cadastrar Passageiro\n");
        printf("2) Alterar Passageiro\n");
        printf("3) Excluir Passageiro\n");
        printf("4) Buscar Passageiro\n");
        printf("5) Ver Passageiros\n");
        printf("6) Voltar\n");
        scanf("%d",&opcao);
        switch(opcao){
            case 1:
                cadastraPassageiro(&ppssgr);
                break;
            case 2:
                lerPassageiro(ppssgr);
                printf("Insira o identificador do passageiro a ser alterado: ");
                scanf("%d", &aux);
                alterarPassageiro(&ppssgr, aux);
                break;
            case 3:
                printf("Insira o identificador do passageiro a ser excluido: ");
                scanf("%d", &aux);
                excluirPassageiro(&ppssgr, aux);
                break;
            case 4:
                printf("Insira o identificador do passageiro a ser buscado: ");
                scanf("%d", &aux);
                buscarPassageiro(ppssgr, aux);
                break;
            case 5:
                lerPassageiro(ppssgr);
                break;
            default:
                ind = 0;
                break;
        }
    }
}
void alterarPassageiro(passageiro *ptr, int numero){
    if(*ptr == NULL | numero == 0){
        return;
    }
    if((*ptr)->identificador == numero){
        printf("\nIdentificador do passageiro: %ld", (*ptr)->identificador);
        printf("\nInsira o novo identificador do passageiro: ");
        scanf("%ld", &(*ptr)->identificador);
        printf("\nNome do passageiro: %s", (*ptr)->nome);
        printf("\nInsira o novo nome do passageiro: ");
        getchar();
        fgets((*ptr)->nome, 50, stdin);
        printf("\nIdentidade do passageiro: %ld", (*ptr)->identidade);
        printf("\nInsira a nova identidade do passageiro: ");
        scanf("%ld", &(*ptr)->identidade);
        printf("\nEndereço do passageiro: %s", (*ptr)->endereco);
        printf("\nInsira o novo endereco do passageiro: ");
        getchar();
        fgets((*ptr)->endereco, 100, stdin);
        printf("\nTelefone do passageiro: %ld", (*ptr)->telefone);
        printf("\nInsira o novo telefone do passageiro:");
        scanf("%ld", &(*ptr)->telefone);
        printf("\nSexo do passageiro: %s", (* ptr)->sexo);
        printf("\nInsira o novo sexo do passageiro: ");
        getchar();
        fgets((*ptr)->sexo, 10, stdin);
        printf("\nAlterado com Sucesso\n");
    }else
        alterarPassageiro(&(*ptr)->next, numero);
}

void buscarPassageiro(passageiro ptr, int numero){
    int encontrado = 0;
    if(ptr == NULL){
        return;
    }
    if(numero == ptr->identificador){
        printf("Identificador do passageiro: %ld\n", ptr->identificador);
        printf("Nome do passageiro: %s\n", ptr->nome);
        printf("Identidade do passageiro: %ld\n", ptr->identidade);
        printf("Endereco do passageiro: %s\n", ptr->endereco);
        printf("Telefone do passageiro: %ld\n", ptr->telefone);
        printf("Sexo do passageiro: %s\n", ptr->sexo);
        encontrado =1;
    }else{
        buscarPassageiro(ptr->next, numero);
    }
}


void excluirPassageiro(passageiro *ptr, int numero){
    int encontrado = 0;
    if(*ptr == NULL){
        printf("Nenhum passageiro cadastrado. Cadastre um passageiro para continuar.\n");
        return;
    }
    if((*ptr)->identificador == numero){
        *ptr = (*ptr)->next;
        encontrado = 1;
        printf("Passageiro excluido com sucesso.\n");
    }
    else{
        excluirPassageiro(&(*ptr)->next, numero);
    }
    if(!encontrado){
        printf("Não encontramos o passageiro. Tente denovo.\n");
    }
}


void cadastraPassageiro(passageiro *ptr){
    int aux;
    if(*ptr == NULL){
        *ptr = (passageiro) malloc(sizeof(PASSAGEIRO));
        if(*ptr == NULL){
            printf("Erro ao alocar memória\n");
            return;
        }
        printf("\nInsira o identificador do passageiro: ");
        scanf("%ld", &(*ptr)->identificador);
        printf("\nInsira o nome do passageiro: ");
        getchar();
        fgets((*ptr)->nome, 50, stdin);
        printf("\nInsira a identidade do passageiro: ");
        scanf("%ld", &(*ptr)->identidade);
        printf("\nInsira o endereco do passageiro: ");
        getchar();
        fgets((*ptr)->endereco, 100, stdin);
        printf("\nInsira o telefone do passageiro: ");
        scanf("%ld", &(*ptr)->telefone);
        printf("\nInsira o sexo do passageiro: ");
        getchar();
        fgets((*ptr)->sexo, 10, stdin);
        printf("\n");
    }else
        cadastraPassageiro(&(*ptr)->next);
}


void lerPassageiro(passageiro ptr){
    if(ptr == NULL){
        printf("Nenhum passageiro cadastrado. Cadastre um passageiro para continuar.\n");
        return;
    }
    printf("\nIdentificador do passageiro: %ld\n", ptr->identificador);
    printf("Nome do passageiro: %s", ptr->nome);
    printf("Identidade do passageiro: %ld\n", ptr->identidade);
    printf("Endereco do passageiro: %s", ptr->endereco);
    printf("Telefone do passageiro: %ld\n", ptr->telefone);
    printf("Sexo do passageiro: %s", ptr->sexo);
    printf("\n");
    lerPassageiro(ptr->next);
}