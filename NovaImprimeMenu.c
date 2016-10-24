#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>

#define NOME_OPCOES 100


//Principal
int main(){
	//setlocale(LC_ALL,"portuguese");
	//Variaveis
	char menuPrincipal[3][NOME_OPCOES],menuProprietario[2][NOME_OPCOES];
	int opMenu;
	
	//Texto do menu
	strcpy(menuPrincipal[0],"1-Proprietario");
	strcpy(menuPrincipal[1],"2-Veiculo");
	strcpy(menuPrincipal[2],"3-Manutencao");
	strcpy(menuPrincipal[3],"4-Relatorios");
	strcpy(menuProprietario[0],"1-Cadastrar cliente");
	strcpy(menuProprietario[1],"2-Excluir cliente");
//	strcpy(menuProprietario[2],"3-Excluir ");
	//Desenvolvimento
	system("color b8");			//Cor de fundo e cor da letra  
	
	opMenu = menu(4,menuPrincipal,"Menu Principal");	
	printf("%d",opMenu);	
	if(opMenu==1)
	{
		opMenu = menu(3,menuProprietario,"Proprietario");

	}
	
	//finalização
	printf("\n");
	system("pause");
	return 0;
}
