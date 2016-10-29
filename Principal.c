//ALUNOS:		Wendell						Fernando Jorge Araújo da Silva 			
//MATRÍCULAS:	UC							UC15200459

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//#include <locale.h>
#include "structs.c"

#define NOME_OPCOES 100
#define MAX_PROPRIETARIOS 500

//Principal
int main(){
	//setlocale(LC_ALL,"portuguese");
	
	//Variaveis
	
	char testeC[20],menuPrincipal[4][NOME_OPCOES],menuProprietario[3][NOME_OPCOES];
	int opMenu, teste,qtdeCadastros=0;
	float testeF;
	Proprietario prop[MAX_PROPRIETARIOS];
	
	//Texto do menu
	strcpy(menuPrincipal[0],"1-Proprietario");
	strcpy(menuPrincipal[1],"2-Veiculo");
	strcpy(menuPrincipal[2],"3-Manutencao");
	strcpy(menuPrincipal[3],"4-Relatorios");
	strcpy(menuProprietario[0],"1-Cadastrar cliente");
	strcpy(menuProprietario[1],"2-Renomear");
	strcpy(menuProprietario[2],"3-Excluir ");

	//configuração inicial da tela
	configTela();
	
	do{	
		opMenu = menuOpcoes(4,menuPrincipal,"Menu Principal");
		
		if(opMenu==1){
			opMenu = menuOpcoes(3,menuProprietario,"Proprietario");
			
			if(opMenu == 1){
				//cadastro do cliente
				leValidaString("Insira o nome: ",menuProprietario[0],prop[qtdeCadastros].nome,2,MAX_NOME,">>>ERRO: Insira um nome válido...");
				
				//leValidaString("Insira o CPF",menuProprietario[0],prop[qtdeCadastros].cpf,TAM_CPF,TAM_CPF,">>>ERRO: Valor Invalido...");
				//(prop+qtdeCadastros)->cpf = formataCPF(prop[qtdeCadastros].cpf);
				
				
				qtdeCadastros++;
			}else if(opMenu == 2){

			
			}
			
		}else if(opMenu == 2){
			
			leValidaFloat("Informe o numero real:",menuProprietario[1],">>>ERRO: Valor Invalido...",0,10,&testeF);
			system("cls");
			printf("valor real: %f",testeF);
			system("pause");
		
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
