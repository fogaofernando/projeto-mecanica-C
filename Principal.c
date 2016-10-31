//ALUNOS:		Wendell						Fernando Jorge Ara�jo da Silva 			
//MATR�CULAS:	UC							UC15200459

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//#include <locale.h>
#include "structs.c"

#define NOME_OPCOES 100
#define MAX_PROPRIETARIOS 500
#define MAX_VEICULOS 500

//Principal
int main(){
	//setlocale(LC_ALL,"portuguese");
	
	//Variaveis
	
	char testeC[20],menuPrincipal[4][NOME_OPCOES],menuProprietario[3][NOME_OPCOES],menuVeiculo[3][NOME_OPCOES];
	int opMenu, teste,qtdeCadastros=0,flag,qtdeVeiculos=0;
	float testeF;
	Proprietario prop[MAX_PROPRIETARIOS];
	Veiculo veic[MAX_VEICULOS];
	
	//Texto do menu
	
	strcpy(menuPrincipal[0],"1-Proprietario");
	strcpy(menuPrincipal[1],"2-Veiculo");
	strcpy(menuPrincipal[2],"3-Manutencao");
	strcpy(menuPrincipal[3],"4-Relatorios");
	strcpy(menuProprietario[0],"1-Cadastrar cliente");
	strcpy(menuProprietario[1],"2-Renomear");
	strcpy(menuProprietario[2],"3-Excluir ");
	strcpy(menuVeiculo[0],"1-Cadastrar veiculo");
	strcpy(menuVeiculo[1],"2-Renomear");
	strcpy(menuVeiculo[2],"3-Excluir ");
	//configura��o inicial da tela
	configTela();
	
	do{	
		opMenu = menuOpcoes(4,menuPrincipal,"Menu Principal");
		
		if(opMenu==1){
			opMenu = menuOpcoes(3,menuProprietario,"Proprietario");
			
			if(opMenu == 1){
				//cadastro do cliente
				leValidaString("Insira o nome: ",menuProprietario[0],prop[qtdeCadastros].nome,2,MAX_NOME,">>>ERRO: Insira um nome v�lido...");
				do
				{
					flag=0;
					leValidaString("Insira o CPF",menuProprietario[0],prop[qtdeCadastros].cpf,MIN_NOME,TAM_CPF,">>>ERRO: Valor Invalido...");
			//	(prop+qtdeCadastros)->cpf = formataCPF(prop[qtdeCadastros].cpf);
					if(validaCPF(prop[qtdeCadastros].cpf)==0){
						flag=1;
						gotoxy(15,6);
						printf("CPF INVALIDO !!!");
						getch();
					}										
    //   				prop[qtdeCadastros].cpf = formataCPF(prop[qtdeCadastros].cpf);
				}while(flag==1);
				
				leValidaString("Insira o Endereco:",menuProprietario[0],prop[qtdeCadastros].endereco,MIN_ENDERECO,MAX_ENDERECO,">>>ERRO: Endereco Invalido");
				qtdeCadastros++;
				
			}else if(opMenu == 2){
			
			}
			
		}else if(opMenu == 2){
			opMenu = menuOpcoes(3,menuVeiculo,"Veiculo");
			if(opMenu == 1){
				do{
					flag=0;
					leValidaString("Informe a Placa do Veiculo:",menuProprietario[0],veic[qtdeVeiculos].placa,0,MAX_PLACA,">>>ERRO: Placa Invalida");
					if(validaPlaca(veic[qtdeVeiculos].placa)==0){
						flag=1;
						gotoxy(15,6);
						printf("Placa Invalida");
						getch();
					}
				}while(flag==1);
				qtdeVeiculos++;
			}

		}else if(opMenu == 3){
			
		}else if(opMenu == 4){
			
		}else{
			//Para finalizacao do programa
			opMenu = -1;
		}	
	
	}while(opMenu != -1);
	
	
	//Finalizacao
	printf("\n");
	system("pause");
	return 0;
}
