#include "defines.c"


//Structs
typedef struct Proprietario{
	char nome[TAM_NOME+1];			
	char cpf[TAM_CPF+1];
	char descricao[TAM_DESCRICAO+1];
	char cidade[TAM_CIDADE+1];
	char estado[TAM_ESTADO+1];
	char telefone[TAM_TELEFONE+1];
	int  servRealizado; 		//0 nao e 1 sim		
}Proprietario;		

typedef struct Veiculo{
	char placa[TAM_PLACA+1];
	char modelo[TAM_MODELO+1];
	char fabricante[TAM_FABRICANTE+1];
	char chassi[TAM_CHASSI+1];
	int ano;
	int manutRealizada; 		//0 nao e 1 sim
}Veiculo;

typedef struct Manutencao{
	char idVeiculo[TAM_PLACA];
	char idPropietario[TAM_CPF];
	char descricao[TAM_DESCRICAO];
	float valorPecas[TAM_VALOR];
	float maodeObra[TAM_MAODEOBRA];
}Manutencao;

//OBS: o +1 nas structs sao para o espaco extra para o '\0'
