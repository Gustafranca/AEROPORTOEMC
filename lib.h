//BILICIOTECA CONTENDO FUNCOES IMPLEMENTADAS


//pode ser separado para mais estruturas

struct Voo{
    int identificador;
    int numeroAero;
    char empresa[50];
    char origem[50];
    char destino[50];
    int dataPartida;
    int horarioPartida;
    int qtdPassageiro;
    int valorVoo;
}voo[50], *ptr_voo;

struct Passageiros
{
    int cpf;
    char nome[50];
    int identidade;
    char endereco[100];
    int telefone;
    char sexo[5];

}passageiros[50], *ptr_passagerios;

struct Passagem
{
    struct Passageiros passageiro;    
    struct Voo voo;
};
