#include "defines.c"


//Structs
typedef struct Proprietario{
	char nome[MAX_NOME+1];			
	char cpf[TAM_CPF+1];
	char descricao[MAX_DESCRICAO+1];
	char cidade[MAX_CIDADE+1];
	char estado[MAX_ESTADO+1];
	char telefone[MAX_TELEFONE+1];
	int  servRealizado; 		//0 nao e 1 sim		
}Proprietario;		

typedef struct Veiculo{
	char placa[TAM_PLACA+1];
	char modelo[MAX_MODELO+1];
	char fabricante[MAX_FABRICANTE+1];
	char chassi[TAM_CHASSI+1];
	int ano;
	int manutRealizada; 		//0 nao e 1 sim
}Veiculo;

typedef struct Manutencao{
	char idVeiculo[TAM_PLACA];
	char idPropietario[TAM_CPF];
	char descricao[MAX_DESCRICAO];
	float valorPecas[MAX_VALOR];
	float maodeObra[MAX_MAODEOBRA];
}Manutencao;

//OBS: o +1 nas structs sao para o espaco extra para o '\0'
