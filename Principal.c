#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//#include <locale.h>

#define NOME_OPCOES 100


//Principal
int main(){
	//setlocale(LC_ALL,"portuguese");
	
	//Variaveis
	char testeC[20],menuPrincipal[4][NOME_OPCOES],menuProprietario[3][NOME_OPCOES];
	int opMenu, teste;
	float testeF;
	
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
		opMenu = menu(4,menuPrincipal,"Menu Principal");
		
		if(opMenu==1){
			opMenu = menu(3,menuProprietario,"Proprietario");
			
			if(opMenu == 1){
				leValidaInt("Informe o numero inteiro:\n>",">>>ERRO: Valor Invalido...\n",0,10,&teste);
				printf("valor inteiro: %d",teste);
				system("pause");
			
			}else if(opMenu == 2){

				leValidaString("Informe uma string\n>",testeC,5,10);
				printf("String: %s",testeC);
				system("pause");
			
			}
			
		}else if(opMenu == 2){
			
			leValidaFloat("Informe o numero real:\n>",">>>ERRO: Valor Invalido...\n",0,10,&testeF);
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
