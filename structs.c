#include "defines.c"

//Structs

typedef struct Proprietario{
	char nome[MAX_NOME];
	char cpf[TAM_CPF];
	char descricao[MAX_DESCRICAO];
	char cidade[MAX_CIDADE];
	char estado[MAX_ESTADO];
	char telefone[MAX_TELEFONE];
	int cadastrado;
}Proprietario;

typedef struct Veiculo{
	char placa[TAM_PLACA+1];
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
