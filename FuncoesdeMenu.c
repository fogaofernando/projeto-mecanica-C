#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include<windows.h>


//Tamanho da tela
#define TELA_X 80	
#define TELA_Y 30

//Botoes menu
#define ACIMA 72
#define ABAIXO 80
#define ESC 27
#define ENTER 13

//Menu Simbolos
#define IMG_OP 62					// 16 ou 62
#define BARRA_HORIZONTAL 205		
#define BARRA_LATERAL 186
#define BARRA_DIG01 201
#define BARRA_DIG02 187
#define BARRA_DIG03 200
#define BARRA_DIG04 188

#define NOME_OPCOES 100		
		
//Posição do menu de opções 
#define POS_X_OPCOES (TELA_X/8)			
#define POS_Y_OPCOES (5)






//PROTOTIPOS__________________________________________________________________________________________________________
int menuOpcoes(int qtOp,char opcoes[][NOME_OPCOES],char *apresentaMenu);
void imprimeSeta(int opAtual,int totalOp);
void imprimeCentralizado(char *texto,int y);
void janelaMenu();
void configTela();
void gotoxy(int x, int y);


//FUNCOES__________________________________________________________________________________________________________

//Imprime e informa opcoes escolhida de um menu 
//Recebe a quantidade de opcoes do menu, o enderecaamento de uma matriz com as opcoes armazenadas e endereco da string com o titulo do menu;
//Retorna a opcoes escolhida, 0 em caso de finalizacoes do programa pelo ESC;
int menuOpcoes(int qtOp,char opcoes[][NOME_OPCOES],char *apresentaMenu){
	//variaveis
	int tecla = -1,opAtual = 1,cont;	// a tecla vai receber a numeraÃ§Ã£o do botÃ£o clicado de acordo com a  tabela ASCII
	
	//desenvolvimento
	system("cls");
	janelaMenu();
	
	// Imprimindo o topico e as opcoes
	imprimeCentralizado(apresentaMenu,2);
	
	for(cont = 0; cont<qtOp ;cont++){
		gotoxy(POS_X_OPCOES , cont+POS_Y_OPCOES);
		printf("%s",opcoes[cont]);
	}
	imprimeSeta(opAtual,qtOp);
	
	//Selecionando opcao
	do{		
		
		//leitura do teclado
		gotoxy(0,TELA_Y-1);
		fflush(stdin);
		tecla = getch();
		
		//opcoes
		if(tecla == ACIMA){
			//Informar posicao atual do cursor
			if(opAtual > 1){
				opAtual--;
				imprimeSeta(opAtual,qtOp);
			}
			
				
		}else if(tecla == ABAIXO){
			
			//informar posicao atual do cursor
			if(opAtual < qtOp){
				opAtual++;
				imprimeSeta(opAtual,qtOp);
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


//Objetivo: Imprimir setas de acordo com a opcao selecionada;	
//Entrada:	Opcao atual e total de opcoes possiveis;
//Saída:	NULO;		
void imprimeSeta(int opAtual,int totalOp){
	//variaveis
	int cont;
	
	//desenvolvimento
	for(cont = 0;cont < totalOp;cont++){
		if(opAtual == cont+1){
			gotoxy(POS_X_OPCOES-2, POS_Y_OPCOES+(cont));
			printf("%c",IMG_OP);
		}else{
			gotoxy(POS_X_OPCOES-2, POS_Y_OPCOES+(cont));
			printf(" ");
		}
	}
}


//Objetivo:Imprime uma string centralizada no texto de acordo com a posição desejada;
//Entrada: Recebe o endereco de uma string, posição 'Y';
//Retorno: Nulo;
void imprimeCentralizado(char *texto,int y){
	//Varivaies
	
	//Desenvolvimento
	gotoxy(((TELA_X)/2)-((strlen(texto)/2 )),y);
	printf("%s",texto);
}


//Objetivo:	Imprimir a janela grafica do menu;
//Entrada:	NULO;
//Saída		NULO;
void janelaMenu(){
	//Variaveis
	int cont;
	
	//Desenvolvimento
		
	//imprimindo topo
	printf("%c",BARRA_DIG01);
	gotoxy(1,0);
	for(cont = 1;cont < (TELA_X-1);cont++){
		printf("%c",BARRA_HORIZONTAL);
	}
	printf("%c",BARRA_DIG02);
	
	//imprindo barras laterais
	for(cont = 1;cont < (TELA_Y-2);cont++){
		//esquerda
		gotoxy(0,cont);
		printf("%c",BARRA_LATERAL);
		//direita
		gotoxy((TELA_X-1),cont);
		printf("%c",BARRA_LATERAL);
	}
	
	//imprimindo base
	printf("\n%c",BARRA_DIG03);
	for(cont = 1;cont < (TELA_X-1);cont++){
		printf("%c",BARRA_HORIZONTAL);
	}
	printf("%c",BARRA_DIG04);
	gotoxy(1,1);
	
	
}


//Objetivo:	Configurações basicas da tela de tamanho e cor
//Entrada:	NULO; 
//Saída: 	NULO;
void configTela()
{
	//Tamanho da tela
	COORD outbuff;												//estrutura que define as coordenadas de uma célula de caracteres em um buffer de tela do console(x e y)
	outbuff.X = TELA_X; 										// tem que ser 1 maior que o tamanho X
	outbuff.Y = TELA_Y; 										// tem que ser 1 maior que o tamanho Y
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);			//Estrutura identificadora para o buffer da tela do console
	SetConsoleScreenBufferSize(hConsole, outbuff); 				/*Objetivo: Altera o tamanho do buffer de TELA do console especificado
																Parâmetros Um identificador para o buffer de tela do console, estrutura que especifica o novo tamanho do buffer de tela do console*/
	
	Sleep(130);													//tempo que a tela fica congelada
	
	//Tamanho da Janela
	SMALL_RECT windowSize = {0, 0,(TELA_X - 1),(TELA_Y - 1)}; 	//Estrutura que passa as cordenadas de um retângulo(esquerda X,topo Y,direita X,inferior Y); 
	SetConsoleWindowInfo(hConsole, TRUE, &windowSize);  	  	/*Define o tamanho atual e posição da JANELA de um buffer de tela do console: 
															 	Parametro: Um identificador para o buffer de tela do console, coordenadas manuais(false) ou especificas(true), um ponteiro para estrutura SMALL_RECT */
	
	//Cor do fundo da tela e da letra
	system("color 8E");	
}


//Objetivo:	Posiciona o cursor de acordo com as coordenadas
//Entrada:	Posicao x e y; 
//Saída: 	NULO;
void gotoxy(int x, int y)
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

