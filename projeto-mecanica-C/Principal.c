//ALUNOS:		Wendell						Fernando Jorge Araújo da Silva 			
//MATRÍCULAS:	UC							UC15200459

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "structs.c" 
#include "defines.c"



//Objetivo:
//Entrada
//Retorno:

//Principal
int main(){
	//configuração inicial da tela
	configTela();

	//Variaveis e inicializacao___________________________________________________________________________________________________________________________________
	
	char testeC[20],menuPrincipal[4][NOME_OPCOES],menuProprietario[3][NOME_OPCOES],menuVeiculo[3][NOME_OPCOES],menuManutencao[2][NOME_OPCOES],menuRelatorios[5][NOME_OPCOES],opFinalizacao[2][NOME_OPCOES];
	int opMenu, teste,qtdeProprietarios=0,flag,qtdeVeiculos=0,qtdeManutencoes=0,cont;
	float testeF;


	//alocacao dinamica das estruturas
	Proprietario *prop = malloc(TAM_PROPRIETARIOS*sizeof(struct Proprietario));   
	Veiculo *veic = malloc(TAM_VEICULOS*sizeof(struct Veiculo));
	Manutencao *manu = malloc(TAM_MANUTENCAO*sizeof(struct Manutencao));
	
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
	strcpy(menuManutencao[0],"1-Cadastrar Manutencao");
	strcpy(menuManutencao[1],"2-Excluir Manutencao");
	strcpy(menuRelatorios[0],"R1-Apresentar Cadastros");
	strcpy(menuRelatorios[1],"R2-Apresentar Veiculos de um Proprietario");
	strcpy(menuRelatorios[2],"R3-Pesquisar Veiculo");
	strcpy(menuRelatorios[3],"R4-Apresentar todas as Manutencoes em um periodo");
	strcpy(menuRelatorios[4],"R5-Pesquisar Proprietario");
	strcpy(opFinalizacao[0],"Sim");
	strcpy(opFinalizacao[1],"Nao");
	
	
	//Leitura dos Arquivos 
	if(leituraInicialDados(prop,veic,manu,&qtdeProprietarios,&qtdeVeiculos,&qtdeManutencoes) == 0){
		return 0;
	}
	
	
	
	//menu principal______________________________________________________________________________________________________________________________________
	do{	
		opMenu = menuOpcoes(4,menuPrincipal,"Menu Principal");
		
		//Propetario_______________________________________________________________________________________________________________________________________	
		if(opMenu==1){
			opMenu = menuOpcoes(3,menuProprietario,"Proprietario");
			
			//Cadastro do cliente
			if(opMenu == 1){
				if(cadastraProprietario(&qtdeProprietarios,prop,"Cadastrar Proprietario") == -1){
					return 0;
				}
			  
			//Alteracao do cliente  
			}else if(opMenu == 2){
				if(alteraProprietario(qtdeProprietarios,prop,"Alterar Proprietario")== -1){
					return 0;
				}
			
			//Excluir cliente
			}else if(opMenu == 3){
				if(excluiProp(&qtdeProprietarios,prop,"Excluir Proprietario")==-1){
					return 0;
				}
			}
			
		//Veiculo__________________________________________________________________________________________________________________________________________
		}else if(opMenu == 2){
			opMenu = menuOpcoes(3,menuVeiculo,"Veiculo");
			
			//Cadastrar veiculo
			if(opMenu == 1){
				if(cadastraVeiculo(&qtdeVeiculos,veic,"Cadastrar veiculo") == -1){
					return 0;
				}			
			
			//Alterar veiculo	
			}else if(opMenu ==2){
				if(alteraVeiculo(qtdeVeiculos,veic,"Alterar Veiculo") == -1){
					return 0;
				}
			
			//Excluir veiculo	
			}else if(opMenu == 3){
				if(excluiVeic(&qtdeVeiculos,veic,"Excluir Veiculo") == -1){
					return 0;
				}
			}
		
		//Manutenção__________________________________________________________________________________________________________________________________________ 
		}else if(opMenu == 3){
			opMenu = menuOpcoes(2,menuManutencao,"Manutencao");
			//Cadastrar Manudenção
			if(opMenu == 1){
				if(cadastraManutencao(&qtdeManutencoes,qtdeVeiculos,qtdeProprietarios,prop,veic,manu,"Cadastrar Manutencao") == -1){
					return 0;
				}
			}else if(opMenu == 2){
				if(excluiManu(&qtdeManutencoes,manu,"Excluir Manutencao") == -1){
					return 0;
				}
			}
		
		//Relatorio____________________________________________________________________________________________________________________________________________
		}else if(opMenu == 4){
			opMenu = menuOpcoes(5,menuRelatorios,"Relatorios");
			//Apresenta todos os cadastros
			if(opMenu == 1){
				apresentaCadastros(qtdeProprietarios,qtdeVeiculos,qtdeManutencoes,prop,veic,manu,"Cadastros Existentes");
			}else if(opMenu ==2){
				pesquisaProprietario(qtdeProprietarios,qtdeVeiculos,qtdeManutencoes,prop,veic,manu,"Pesquisar Veiculos de um Proprietario");
			}else if(opMenu == 3){
				 pesquisaVeiculo(qtdeProprietarios,qtdeVeiculos,qtdeManutencoes,prop,veic,manu,"Pesquisar Veiculos");
			}else if(opMenu == 5){
				 pesquisaNome(qtdeProprietarios,qtdeVeiculos,qtdeManutencoes,prop,veic,manu,"Pesquisar Nome"); //R5
			}
		//Finalizacao do programa__________________________________________________________________________________________________________________________________
		}else{
			
			//Confirmacao de finalizacao do programa
			opMenu = menuOpcoes(2,opFinalizacao,"DESEJA FINALIZAR O PROGRAMA ?");
			if(opMenu == 1){
				opMenu = -1;
			}
		}	
	
	}while(opMenu != -1);
	
	//Finalizacao
	printf("\n");
	free(prop);
	free(veic);
	free(manu);
	system("pause");
	return 0;
}
