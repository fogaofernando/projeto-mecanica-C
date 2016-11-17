//ALUNOS:		Wendell						Fernando Jorge Araújo da Silva 			
//MATRÍCULAS:	UC							UC15200459

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "structs.c" 
#include "defines.c"


//Principal
int main(){
	//configuração inicial da tela
	configTela();
	
	
	//Variaveis
	
	char testeC[20],menuPrincipal[4][NOME_OPCOES],menuProprietario[3][NOME_OPCOES],menuVeiculo[3][NOME_OPCOES],menuManutencao[2][NOME_OPCOES],menuRelatorios[5][NOME_OPCOES],opFinalizacao[2][NOME_OPCOES];
	int opMenu, teste,qtdeProprietarios=0,flag,qtdeVeiculos=0,qtdeManutencoes=0,cont;
	float testeF;

//	Proprietario prop[TAM_PROPRIETARIOS];

	//alocacao dinamica das estruturas
	Proprietario *prop = malloc(TAM_PROPRIETARIOS*sizeof(struct Proprietario));   
	Veiculo *veic = malloc(TAM_VEICULOS*sizeof(struct Veiculo));
	Manutencao *manu = malloc(TAM_MANUTENCAO*sizeof(struct Manutencao));
	
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
	strcpy(opFinalizacao[0],"Sim");
	strcpy(opFinalizacao[1],"Nao");
	
	
	//Leitura dos Arquivos 
//	leArquivo(&qtdeProprietarios,prop);
	
	//menu principal______________________________________________________________________________________________________________________________________
	do{	
		opMenu = menuOpcoes(4,menuPrincipal,"Menu Principal");
		
		//Propetario_______________________________________________________________________________________________________________________________________	
		if(opMenu==1){
			opMenu = menuOpcoes(3,menuProprietario,"Proprietario");
			
			//Cadastro do cliente
			if(opMenu == 1){
				if( cadastraProprietario(&qtdeProprietarios,prop,"Cadastrar Proprietario") == 1){
					printf("\n>Nome: %s\n>CPF: %s\n>Descricao: %s\n>Cidade: %s\n>Estado: %s\n>Telefone: %s",prop[qtdeProprietarios-1].nome,prop[qtdeProprietarios-1].cpf,prop[qtdeProprietarios-1].descricao,prop[qtdeProprietarios-1].cidade,prop[qtdeProprietarios-1].estado,prop[qtdeProprietarios-1].telefone);
//					gravaArquivo(qtdeProprietarios,prop);
					getch();
				}
			
			//Alteracao do cliente
			}else if(opMenu == 2){
				alteraProprietario(qtdeProprietarios,prop,"Alterar Proprietario");
			}else if(opMenu == 3){
				excluiProp(&qtdeProprietarios,prop,"Excluir Proprietario");
			}
			
		//Veiculo__________________________________________________________________________________________________________________________________________
		}else if(opMenu == 2){
			opMenu = menuOpcoes(3,menuVeiculo,"Veiculo");
			
			//Cadastrar veiculo
			if(opMenu == 1){
				if(cadastraVeiculo(&qtdeVeiculos,veic,"Cadastrar veiculo") == 1){
					for(cont =0;cont<qtdeVeiculos;cont++){
						printf("\n>Placa: %s\n>Modelo: %s\n>Fabricante: %s\n>Chassi: %s\n>Anon de fabricacao: %d\nQTcadastro: %d\n\n\n",veic[cont].placa,veic[cont].modelo,veic[cont].fabricante,veic[cont].chassi,veic[cont].ano,qtdeVeiculos);
					}
					getch();
				}
			
			//Alterar veiculo	
			}else if(opMenu ==2){
					alteraVeiculo(qtdeVeiculos,veic,"Alterar Veiculo");
			}else if(opMenu == 3){
				excluiVeic(&qtdeVeiculos,veic,"Excluir Veiculo");
			}
		//Manutenção__________________________________________________________________________________________________________________________________________ 
		}else if(opMenu == 3){
			opMenu = menuOpcoes(2,menuManutencao,"Manutencao");
			//Cadastrar Manudenção
			if(opMenu == 1){
				cadastraManutencao(&qtdeManutencoes,qtdeVeiculos,qtdeProprietarios,prop,veic,manu,"Cadastrar Manutencao");
			}
			
			for(cont =0;cont<qtdeManutencoes;cont++){
				printf("\n>ID veiculo: %s\n>ID propetario: %s\n>descricao: %s\n>valor pecas: %f\n>mao de obra %f\n >Data : %s\n\n",manu[cont].idVeiculo,manu[cont].idProprietario,manu[cont].descricao,manu[cont].valorPecas,manu[cont].maodeObra,manu[cont].data);
			}
			getch();
		
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
			}
		}else{
			
			//Para finalizacao do programa
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
