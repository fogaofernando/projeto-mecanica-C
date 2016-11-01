//Macros

//primeira struct

#define MAX_NOME 20
#define MIN_NOME 3
#define TAM_CPF 12
#define MAX_ENDERECO 50
#define MIN_ENDERECO 5
#define MAX_CIDADE 20
#define MAX_ESTADO 20
#define MAX_TELEFONE 12

//segunda struct

#define MAX_PLACA 7
#define MAX_MODELO 20
#define MAX_FABRICANTE 20
#define MAX_CHASSI 20
#define MAX_ANO 2016

//terceira struct
#define MAX_IDVEICULO 9999
#define MIN_IDVEICULO 1000
#define MAX_IDPROPRIETARIO 9999
#define MIN_IDPROPRIETARIO 1000
#define DESCRICAO 500
#define MAX_VALOR 10000
#define MIN_VALOR 11
//Structs

typedef struct Proprietario{
	char nome[MAX_NOME];
	char cpf[TAM_CPF];
	char endereco[MAX_ENDERECO];			//0 descrição, 1 cidade e 2 estado
	//char cidade[MAX_CIDADE];
	//char estado[MAX_ESTADO];
	int tefefone;
}Proprietario;

typedef struct Veiculo{
	char placa[MAX_PLACA];
	char modelo[MAX_MODELO];
	char fabricante[MAX_FABRICANTE];
	int chassi;
	int ano;
}Veiculo;

typedef struct Manutencao{
	int idVeiculo;
	int idPropietario;
	char descricao;
	float valorPecas;
	float maodeObra;
}Manutencao;
