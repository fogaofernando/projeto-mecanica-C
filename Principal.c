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
	
	char testeC[20],menuPrincipal[4][NOME_OPCOES],menuProprietario[3][NOME_OPCOES],menuVeiculo[3][NOME_OPCOES],menuManutencao[2][NOME_OPCOES],menuRelatorios[5][NOME_OPCOES];
	int opMenu, teste,qtdePropetario=0,flag,qtdeVeiculos=0,qtdeManutencoes=0,cont;
	float testeF;

//	Proprietario prop[MAX_PROPRIETARIOS];

	//alocacao dinamica das estruturas
	Proprietario *prop = malloc(MAX_PROPRIETARIOS*sizeof(struct Proprietario));   
	Veiculo *veic = malloc(MAX_VEICULOS*sizeof(struct Veiculo));
	Manutencao *manu = malloc(MAX_MANUTENCAO*sizeof(struct Manutencao));
	
	//Texto do menu_________________________________________________________________________________________________________________________
	
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
				if( cadastraProprietario(&qtdePropetario,prop,"Cadastrar Proprietario") == 1){
					printf("\n>Nome: %s\n>CPF: %s\n>Descricao: %s\n>Cidade: %s\n>Estado: %s\n>Telefone: %s",prop[qtdePropetario-1].nome,prop[qtdePropetario-1].cpf,prop[qtdePropetario-1].descricao,prop[qtdePropetario-1].cidade,prop[qtdePropetario-1].estado,prop[qtdePropetario-1].telefone);
					getch();
				}
			
			//Alteracao do cliente
			}else if(opMenu == 2){
				alteraProprietario(qtdePropetario,prop,"Alterar Proprietario");
			}else if(opMenu == 3){
				
			}
			
		//Veiculo__________________________________________________________________________________________________________________________________________
		}else if(opMenu == 2){
			opMenu = menuOpcoes(3,menuVeiculo,"Veiculo");
			
			//Cadastrar veiculo
			if(opMenu == 1){
				if(cadastraVeiculo(&qtdeVeiculos,veic,"Cadastrar veiculo") == 1){
					for(cont =0;cont<qtdeVeiculos;cont++){
						printf("\n>Placa: %s\n>Modelo: %s\n>Fabricante: %s\n>Chassi: %s\n>Anon de fabricacao: %d\n\n\n",veic[cont].placa,veic[cont].modelo,veic[cont].fabricante,veic[cont].chassi,veic[cont].ano);
					}
					getch();
				}
			
			//Alterar veiculo	
			}else if(opMenu ==2){
					alteraVeiculo(qtdeVeiculos,veic,"Alterar Veiculo");
			}else{
				
			}
		//Manutenção__________________________________________________________________________________________________________________________________________
		}else if(opMenu == 3){
			opMenu = menuOpcoes(2,menuManutencao,"Manutencao");
			//Cadastrar Manudenção
			if(opMenu == 1){
				cadastraManutencao(&qtdeManutencoes,qtdeVeiculos,qtdePropetario,prop,veic,manu,"Cadastrar Manutencao");
			}
		
		//Relatorio____________________________________________________________________________________________________________________________________________
		}else if(opMenu == 4){
			opMenu = menuOpcoes(5,menuRelatorios,"Relatorios");
			//Apresenta todos os cadastros
			if(opMenu == 1){
				apresentaCadastros(qtdePropetario,qtdeVeiculos,prop,veic,manu,"Cadastros Existentes");
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
