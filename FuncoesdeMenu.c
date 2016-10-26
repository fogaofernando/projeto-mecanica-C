#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//Menu Grafico
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
#define ESP_BRANCO   1		  		//Valor dado + os caracteres ja impressos

int menu(int qtOp,char opcoes[][NOME_OPCOES],char *apresentaMenu);
void tabelaHorizontal(int op);
void imprimeApresentacaoMenu(char *apMenu);
void addEspacoBarraLateral(char *texto, int espAnterior);

//Imprime e informa opcoes escolhida de um menu 
//Recebe a quantidade de opcoes do menu, o enderecaamento de uma matriz com as opcoes armazenadas e endereco da string com o titulo do menu;
//Retorna a opcoes escolhida, 0 em caso de finalizacoes do programa pelo ESC;
int menu(int qtOp,char opcoes[][NOME_OPCOES],char *apresentaMenu){
	//variaveis
	int tecla = -1,opAtual = 1,cont;	// a tecla vai receber a numeração do botão clicado de acordo com a  tabela ASCII
	
	//desenvolvimento
	system("cls");
	do{
		// inicio do menu
		
		if(tecla == -1){
			
			//Imprimindo o menu
			tabelaHorizontal(1);
			imprimeApresentacaoMenu(apresentaMenu);
			espacosBranco(1);
			for(cont = 0;cont<qtOp;cont++){
				
				//imprimir opcoes
				if(opAtual == cont+1){
					printf("%c  %c %s",BARRA_LATERAL,IMG_OP,opcoes[cont]);
					addEspacoBarraLateral(opcoes[cont],5);
					
				}else{
					printf("%c    %s",BARRA_LATERAL,opcoes[cont]);
					addEspacoBarraLateral(opcoes[cont],5);
				}
				
			}	
			espacosBranco(1);
			tabelaHorizontal(2);
		}
		
		//leitura do teclado
		//fflush(stdin);
		tecla = getch();
		fflush(stdin);
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
			espacosBranco(1);
			for(cont = 0;cont<qtOp;cont++){
				if(opAtual == cont+1){
					printf("%c  %c %s",BARRA_LATERAL,IMG_OP,opcoes[cont]);
					addEspacoBarraLateral(opcoes[cont],5);
				}else{
					printf("%c    %s",BARRA_LATERAL,opcoes[cont]);
					addEspacoBarraLateral(opcoes[cont],5);
				}
				
			}	
			espacosBranco(1);
			tabelaHorizontal(2);
		}else if(tecla == ABAIXO){
			//informar posição atual do cursor
			if(opAtual < qtOp){
				opAtual++;
			}
			
			//Imprimindo o menu
			tabelaHorizontal(1);
			imprimeApresentacaoMenu(apresentaMenu);
			espacosBranco(1);
			for(cont = 0;cont<qtOp;cont++){
				if(opAtual == cont+1){
					printf("%c  %c %s",BARRA_LATERAL,IMG_OP,opcoes[cont]);
					addEspacoBarraLateral(opcoes[cont],5);
				}else{
					printf("%c    %s",BARRA_LATERAL,opcoes[cont]);
					addEspacoBarraLateral(opcoes[cont],5);
				}
				
			}	
		espacosBranco(1);
		tabelaHorizontal(2);
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
//Recebe a opcao de impressao desejada: 1 para o topo e x != 1 para a base;
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
		printf("%c\n",BARRA_DIG02);	
	}else{
		printf("%c",BARRA_DIG04);	
	}
	
}

//Imprime o topico do menu
//Recebe a string com o nome 
void imprimeApresentacaoMenu(char *apMenu){
	//Variaveis
	int qtEspaco,cont;
	char espacos[TAM_HORIZONTAL];
	
	//Desenvolvimento
	qtEspaco = (TAM_HORIZONTAL- strlen(apMenu) )/2;
	
	//barra lateral
	printf("%c",BARRA_LATERAL);
	
	//espacos anteriores
	for(cont = 0 ; cont< (qtEspaco-1) ; cont++){
			espacos[cont] = ' ';
	}
	
	espacos[cont] = '\0';
	
	//topico
	printf("%s%s%s",espacos,apMenu,espacos);
	
	//espaco extra para impar
	if( strlen(apMenu)%2 != 0){
		printf(" ");
	}
	
	//barra lateral
	printf(" %c\n",BARRA_LATERAL);
}

//Imprime os espacos laterais do menu apos a string e a barra lateral
//Recebe uma string, e a quantidade de espacos anteriores a ela 
void addEspacoBarraLateral(char *texto, int espAnterior){
	//Variaveis
	int cont,qtEspaco = 0;
	char espacos[TAM_HORIZONTAL];
		
	//Desenvolvimento
		//recebendo a quantidade de espacos
	qtEspaco = strlen(texto);
	qtEspaco += espAnterior ;
	qtEspaco = TAM_HORIZONTAL - qtEspaco;
	
	//printf("%d",espaco);
	
	//imprimindo espacos e barra lateral
fflush(stdin);
	for(cont = 0 ;cont<qtEspaco;cont++){
			
		espacos[cont] = ' ';
	}
	espacos[cont] = '\0';
	printf("%s%c\n",espacos,BARRA_LATERAL);
	
}


//Imnprime os espacos em branco da tabela do menu
//Entrada: Recebe a quantidade de linhas que ser�o impressos
//Sa�da: NULL;
void espacosBranco(int qtEsp){
	//Variaveis
	int cont,i;
	char espacos[TAM_HORIZONTAL];
	
	//Desenvolvimento
	for(i=0;i<qtEsp;i++){
		
		fflush(stdin);
		printf("%c",BARRA_LATERAL);
		for(cont = 0;cont < (TAM_HORIZONTAL - 1);cont++){
			espacos[cont] = ' ';	
		}
		espacos[cont] = '\0';
		printf("%s%c\n",espacos,BARRA_LATERAL);
	}
}

