#include "defines.c"

//Structs

typedef struct Proprietario{
	char nome[MAX_NOME];
	char cpf[TAM_CPF];
	char descricao[MAX_DESCRICAO];			//0 descrição, 1 cidade e 2 estado
	char cidade[MAX_CIDADE];
	char estado[MAX_ESTADO];
	int tefefone;
//	char copiaNomePesquisa [][MAX_NOME];
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
