#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>

//Teclados
#define ACIMA 72
#define ABAIXO 80
#define ESC 27
#define ENTER 13
#define MAX_OPCOES 10
#define NOME_OPCOES 100
#define IMG_OP 62
#define BARRA_HORIZONTAL 205
#define BARRA_LATERAL 186
#define BARRA_DIG01 201
#define BARRA_DIG02 187
#define BARRA_DIG03 200
#define BARRA_DIG04 188
#define TAM_HORIZONTAL 60			//Tem que ser par
#define TAM_VERTICAL   20  		//Valor dado + os caracteres já impressos

//Protótipo
int menu(int qtOp,char opcoes[][NOME_OPCOES],char *apresentaMenu);
void tabelaHorizontal(int op);
void imprimeApresentacaoMenu(char *apMenu);

//Principal
int main(){
	//setlocale(LC_ALL,"portuguese");
	//Variaveis
	char menuTeste[3][NOME_OPCOES];
	int opMenu;
	
	//Texto do menu
	strcpy(menuTeste[0],"1-Cadastrar cliente\n");
	strcpy(menuTeste[1],"2-Excluir cliente\n");
	strcpy(menuTeste[2],"3-Renomear cliente\n");
	
	//Desenvolvimento
	system("color b8");			//Cor de fundo e cor da letra  
	
	opMenu = menu(3,menuTeste,"Menu Principal");	
	printf("%d",opMenu);	

	//finalização
	printf("\n");
	system("pause");
	return 0;
}
//Funções



//Imprime e informa opção escolhida de um menu de opções
//Recebe a quantidade de opções do menu, o endereçamento de uma matriz com as opções armazenadas e endereçamento da string com o título do menu;
//Retorna a opção escolhida, 0 em caso de finalização do programa pelo ESC;
int menu(int qtOp,char opcoes[][NOME_OPCOES],char *apresentaMenu){
	//variaveis
	int tecla = -1,opAtual = 1,cont;	// a tecla vai receber a numeração do botão clicado de acordo com a  tabela ASCII
	
	//desenvolvimento
	do{
		//Impressão inicial do menu
		
		if(tecla == -1){
			
			//imprimir topo
			tabelaHorizontal(1);
			imprimeApresentacaoMenu(apresentaMenu);
			for(cont = 0;cont<qtOp;cont++){
				
				//imprimir opções
				if(opAtual == cont+1){
					printf("%c  %c %s",BARRA_LATERAL,IMG_OP,opcoes[cont]);
				}else{
					printf("%c    %s",BARRA_LATERAL,opcoes[cont]);
				}
				
			}	
			tabelaHorizontal(2);
		}
		
		//leitura do teclado
		fflush(stdin);
		tecla = getch();
		system("cls");
		
		//imprimindo menu
		if(tecla == ACIMA){
			//Informar posição atual do cursor
			if(opAtual > 1){
				opAtual--;
			}
			
			//Imprimindo o menu
			tabelaHorizontal(1);
			imprimeApresentacaoMenu(apresentaMenu);
			for(cont = 0;cont<qtOp;cont++){
				if(opAtual == cont+1){
					printf("%c  %c %s",BARRA_LATERAL,IMG_OP,opcoes[cont]);
				}else{
					printf("%c    %s",BARRA_LATERAL,opcoes[cont]);
				}
				
			}	
			
		}else if(tecla == ABAIXO){
			//informar posição atual do cursor
			if(opAtual < qtOp){
				opAtual++;
			}
			
			//Imprimindo o menu
			tabelaHorizontal(1);
			imprimeApresentacaoMenu(apresentaMenu);
			for(cont = 0;cont<qtOp;cont++){
				if(opAtual == cont+1){
					printf("%c  %c %s",BARRA_LATERAL,IMG_OP,opcoes[cont]);
				}else{
					printf("%c    %s",BARRA_LATERAL,opcoes[cont]);
				}
				
			}	
		
		}else if(tecla != ESC && tecla != ENTER){
			tecla = -1;
		}
		
		
		
	}while(tecla != ESC && tecla != ENTER);
	
	if(tecla == ESC){
		return 0;
	}
	
	return opAtual;
		
}

//Imprime o topo ou a base da tabela.
//Recebe a opção de impressao desejada: 1 para o topo e x != 1 para a base;
void tabelaHorizontal(int op){
	//Variaveis
	int cont;
	char *espaco;
		
	//Desenvolvimento
		
	if(op == 1){
		printf("%c",BARRA_DIG01);
		//strcat(espaco,"\xDA");
		//printf("%s",espaco);	
	}else{
		printf("%c",BARRA_DIG03);	
	}
	

	for(cont = 1 ; cont < TAM_HORIZONTAL ; cont++){
		printf("%c",BARRA_HORIZONTAL);
		
	}
	
	if(op == 1){
		printf("%c",BARRA_DIG02);	
	}else{
		printf("%c",BARRA_DIG04);	
	}
	
}

//Imprime o tópico do menu
//Recebe a string com o nome 
void imprimeApresentacaoMenu(char *apMenu){
	//Variaveis
	int qtEspaco,cont;
	
	//Desenvolvimento
	qtEspaco = (TAM_HORIZONTAL- strlen(apMenu) )/2;
	
	//barra lateral
	printf("\n%c",BARRA_LATERAL);
	
	//espaços anteriores
	for(cont = 0 ; cont< (qtEspaco-1) ; cont++){
			printf(" ");
	}
		//espaço extra para impar
	if( strlen(apMenu)%2 != 0){
		printf(" ");
	}
	
	//tópico
	printf("%s",apMenu);
	
	//espaços posteriores
	for(cont = 0 ; cont< qtEspaco ; cont++){
		printf(" ");
	}
	
	//barra lateral
	printf("%c\n%c",BARRA_LATERAL,BARRA_LATERAL);
	
	//espaços anteriores
	for(cont = 0 ; cont < TAM_HORIZONTAL-1 ; cont++){
			printf(" ");
	}
		//espaço extra para impar

	
	printf("%c\n",BARRA_LATERAL);
}
