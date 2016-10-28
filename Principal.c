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
	
	
	//Desenvolvimento
	system("color 8E");			//Cor de fundo e cor da letra  
	
	do{	
		opMenu = tabelaMenu(4,menuPrincipal,"Menu Principal");
		
		if(opMenu==1){
			opMenu = tabelaMenu(3,menuProprietario,"Proprietario");
			
			if(opMenu == 1){
				leValidaString("Informe o nome : ",menuProprietario[0],prop[qtdeCadastros].nome,0,10);
				printf("%s",prop[qtdeCadastros].nome);
				getch();
				leValidaInt("Informe o numero inteiro:",menuProprietario[0],">>>ERRO: Valor Invalido...",0,10,&teste);
				system("cls");
				printf("valor inteiro: %d",teste);
				system("pause");
				qtdeCadastros++;
			}else if(opMenu == 2){

				leValidaString("Informe uma string\n>",testeC,5,10);
				printf("String: %s",testeC);
				system("pause");
			
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
