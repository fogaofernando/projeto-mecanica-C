//ALUNOS:		Wendell						Fernando Jorge Araújo da Silva 			
//MATRÍCULAS:	UC							UC15200459

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//#include <locale.h>
#include "structs.c"
#include "defines.c"




//Principal
int main(){
	//setlocale(LC_ALL,"portuguese");
	
	//Variaveis
	
	char testeC[20],menuPrincipal[4][NOME_OPCOES],menuProprietario[3][NOME_OPCOES],menuVeiculo[3][NOME_OPCOES],menuManutencao[3][NOME_OPCOES],menuRelatorios[5][NOME_OPCOES];
	int opMenu, teste,*qtdeCadastros=0,flag,*qtdeVeiculos=0,*qtdeManutencoes;
	float testeF;

//	Proprietario prop[MAX_PROPRIETARIOS];

	//alocacao dinamica das estruturas
	Proprietario *prop = malloc(MAX_PROPRIETARIOS*sizeof(struct Proprietario));   
	Veiculo *veic = malloc(MAX_VEICULOS*sizeof(struct Veiculo));
	Manutencao *manu = malloc(MAX_MANUTENCAO*sizeof(struct Manutencao));
	
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
	strcpy(menuRelatorios[0],"R1-Apresentar Cadastros");
	strcpy(menuRelatorios[1],"R2-Apresentar Veiculos de um Proprietario");
	strcpy(menuRelatorios[2],"R3-Pesquisar Veiculo");
	strcpy(menuRelatorios[3],"R4-Apresentar todas as Manutencoes em um periodo");
	strcpy(menuRelatorios[4],"R5-Pesquisar Proprietario");
	
	//configuração inicial da tela
	configTela();
	
	//menu principal______________________________________________________________________________________________________________________________________
	do{	
		opMenu = menuOpcoes(4,menuPrincipal,"Menu Principal");
		
		//Propetario_______________________________________________________________________________________________________________________________________	
		if(opMenu==1){
			opMenu = menuOpcoes(3,menuProprietario,"Proprietario");
			
			//Cadastro do cliente
			if(opMenu == 1){
				cadastraProprietario(&qtdeCadastros,prop,"Cadastrar Proprietario");
			
			//Alteracao do cliente
			}else if(opMenu == 2){
				alteraProprietario(qtdeCadastros,prop,"Alterar Proprietario");
				
			}else if(opMenu == 3)
			{
				excluiProprietario(qtdeCadastros,prop,"Excluir Proprietario");
			}
			
		//Veiculo__________________________________________________________________________________________________________________________________________
		}else if(opMenu == 2){
			opMenu = menuOpcoes(3,menuVeiculo,"Veiculo");
			
			//Cadastrar veiculo
			if(opMenu == 1){
				cadastraVeiculo(&qtdeVeiculos,veic,"Cadastrar veiculo");
				
		} 	else if(opMenu ==2){
				alteraVeiculo(qtdeVeiculos,veic,"Alterar Veiculo");
		
		}	else if(opMenu == 2){

		}
		//Manutenção__________________________________________________________________________________________________________________________________________
		}else if(opMenu == 3){
			opMenu = menuOpcoes(3,menuManutencao,"Manutencao");
			//Cadastrar Manudenção
			if(opMenu == 1){
				
			}
		
		}else if(opMenu == 4){
			opMenu = menuOpcoes(5,menuRelatorios,"Relatorios");
			//Apresenta todos os cadastros
			if(opMenu == 1){
				apresentaCadastros(qtdeCadastros,qtdeVeiculos,qtdeManutencoes,prop,veic,"Cadastros Existentes");
			}
		}
		else{
			//Para finalizacao do programa
			opMenu = -1;
		}	
	
	}while(opMenu != -1);
	
	
	//Finalizacao
	printf("\n");
	free(prop);
	free(veic);
	system("pause");
	return 0;
}
