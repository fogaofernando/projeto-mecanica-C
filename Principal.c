//ALUNOS:		Wendell						Fernando Jorge Araújo da Silva 			
//MATRÍCULAS:	UC							UC15200459

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//#include <locale.h>
#include "structs.c"


#define NOME_OPCOES 100
#define MAX_PROPRIETARIOS 500
#define MAX_VEICULOS 500

//macros importadas
#define POS_Y_TOPO 2


//Principal
int main(){
	//setlocale(LC_ALL,"portuguese");
	
	//Variaveis
	
	char testeC[20],menuPrincipal[4][NOME_OPCOES],menuProprietario[3][NOME_OPCOES],menuVeiculo[3][NOME_OPCOES];
	int opMenu, teste,qtdeCadastros=0,flag,qtdeVeiculos=0;
	float testeF;
//	Proprietario prop[MAX_PROPRIETARIOS];
	Proprietario *prop = malloc(MAX_PROPRIETARIOS*sizeof(struct Proprietario));   // Alocação Dinamica
	Veiculo veic[MAX_VEICULOS];
	
	//Texto do menu
	
	strcpy(menuPrincipal[0],"1-Proprietario");
	strcpy(menuPrincipal[1],"2-Veiculo");
	strcpy(menuPrincipal[2],"3-Manutencao");
	strcpy(menuPrincipal[3],"4-Relatorios");
	strcpy(menuProprietario[0],"1-Cadastrar cliente");
	strcpy(menuProprietario[1],"2-Alterar");
	strcpy(menuProprietario[2],"3-Excluir ");
	strcpy(menuVeiculo[0],"1-Cadastrar veiculo");
	strcpy(menuVeiculo[1],"2-Renomear");
	strcpy(menuVeiculo[2],"3-Excluir ");
	//configuração inicial da tela
	configTela();
	
	do{	
		opMenu = menuOpcoes(4,menuPrincipal,"Menu Principal");
		
		if(opMenu==1){
			opMenu = menuOpcoes(3,menuProprietario,"Proprietario");
			
			//cadastro do cliente_________________________________________________________________________________________________
			if(opMenu == 1){
				cadastraProprietario(&qtdeCadastros,prop,"Cadastrar cliente");
				
			}else if(opMenu == 2){
				alteraProprietario(&qtdeCadastros,prop,"Alterar");
				
			}
		}else if(opMenu == 2){
			opMenu = menuOpcoes(3,menuVeiculo,"Veiculo");
			
			//Cadastrar veiculo_________________________________________________________________________________________________________
			if(opMenu == 1){
				cadastraVeiculo(&qtdeVeiculos,veic,"Cadastrar veiculo");
				
		}
		}else if(opMenu == 2){
			
		}else if(opMenu == 3){
			
		}else{
			//Para finalizacao do programa
			opMenu = -1;
		}	
	
	}while(opMenu != -1);
	
	
	//Finalizacao
	printf("\n");
	free(prop);
	system("pause");
	return 0;
}
