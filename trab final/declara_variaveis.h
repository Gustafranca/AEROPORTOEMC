#include <stddef.h>
typedef struct passageiro{
    long identificador;
    char nome[50];
    long identidade;
    char endereco[100];
    long telefone;
    char sexo[10];
    struct passageiro *next;
}PASSAGEIRO;

typedef PASSAGEIRO *passageiro;

typedef struct data{
    int dia;
    int mes;
    int ano;
}DATA;

typedef struct hora{
    int hora;
    int minuto;
}HORA;

typedef struct voo{
    long identificador;
    long numero_aviao;
    char empresa[25];
    char origem[50];
    char destino[50];
    DATA data_saida;
    HORA horario_saida;
    int qtd_passageiros;
    struct voo *next;
}VOO;

typedef VOO *voo;

typedef struct passagem{
    int numero;
    int identificador_passageiro;
    int identificador_voo;
    int valor;
    DATA data;
    struct passagem *next;
}PASSAGEM;

typedef PASSAGEM *passagem;

extern VOO *pvoo;       
extern PASSAGEM *ppssgm;
extern PASSAGEIRO *ppssgr;
extern int opcao, aux, ind;


// funcoes gerais
//void relatorio();
void menu();
//funces voos

void menuVoo();
void buscarVoo(voo ptr, int numero);
void excluirVoo(voo *ptr, int numero);
void cadastraVoo(voo *ptr);
void lerVoo(voo ptr);
void alterarVoo(voo *ptr, int numero);

//funcoes passageiros

void menuPassageiro();
void buscarPassageiro(passageiro ptr, int numero);
void excluirPassageiro(passageiro *ptr, int numero);
void cadastraPassageiro(passageiro *ptr);
void lerPassageiro(passageiro ptr);
void alterarPassageiro(passageiro *ptr, int numero);


//funcoes passagens

void menuPassagens();
void buscarPassagens(passagem ptr, int numero);
void excluirPassagens(passagem *ptr, int numero);
void cadastraPassagens(passagem *ptr);
void lerPassagens(passagem ptr);
void alterarPassagens(passagem *ptr, int numero);

//relatorio

void menuRelatorio();
void passagens_voos(PASSAGEM *ppssgm);
void voos_empresas(voo ptr);
void passageiros_voos(passagem ptr);


