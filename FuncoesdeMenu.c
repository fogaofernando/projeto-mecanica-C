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
#define IMG_OP 16
#define BARRA_HORIZONTAL 205
#define BARRA_LATERAL 186
#define BARRA_DIG01 201
#define BARRA_DIG02 187
#define BARRA_DIG03 200
#define BARRA_DIG04 188
#define TAM_HORIZONTAL 60			//Tem que ser par
#define ESP_BRANCO   1		  		//Valor dado + os caracteres ja impressos

int tabelaMenu(int qtOp,char opcoes[][NOME_OPCOES],char *apresentaMenu);
void tabelaHorizontal(int op);
void addEspacoBarraLateral(char *texto, int espAnterior);
void espacosBranco(int qtEsp);
void imprimeTxtTabela(char *txt,int posicao);




//Imprime e informa opcoes escolhida de um menu 
//Recebe a quantidade de opcoes do menu, o enderecaamento de uma matriz com as opcoes armazenadas e endereco da string com o titulo do menu;
//Retorna a opcoes escolhida, 0 em caso de finalizacoes do programa pelo ESC;
int tabelaMenu(int qtOp,char opcoes[][NOME_OPCOES],char *apresentaMenu){
	//variaveis
	int tecla = -1,opAtual = 1,cont;	// a tecla vai receber a numeraÃ§Ã£o do botÃ£o clicado de acordo com a  tabela ASCII
	
	//desenvolvimento
	system("cls");
	do{
		// inicio do menu
		
		if(tecla == -1){
			
			//Imprimindo o menu
			tabelaHorizontal(1);
			imprimeTxtTabela(apresentaMenu,1);
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
			//Informar posiÃ§Ã£o atual do cursor
			if(opAtual > 1){
				opAtual--;
			}
			
			//Imprimindo o menu
			tabelaHorizontal(1);
			imprimeTxtTabela(apresentaMenu,1);
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
			//informar posiÃ§Ã£o atual do cursor
			if(opAtual < qtOp){
				opAtual++;
			}
			
			//Imprimindo o menu
			tabelaHorizontal(1);
			imprimeTxtTabela(apresentaMenu,1);
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

//Objetivo:Imprime uma string dentro da tabela;
//Entrada:Recebe a string com o nome, e a posicao desejada(0 =>esquerda, 1 => centralizado ) ;
//Retorno: Nulo;
void imprimeTxtTabela(char *txt,int posicao){
	//Variaveis
	int qtEspaco,cont;
	char espacos[TAM_HORIZONTAL];
	
	//Desenvolvimento
	qtEspaco = (TAM_HORIZONTAL- strlen(txt));
	
	//barra lateral esquerda
	printf("%c",BARRA_LATERAL);
	
	//Posoção
	if(posicao == 0){
		
		//A esquerda
			//Adicionando espaços no vetor
		for(cont = 0 ; cont< (qtEspaco-2); cont++){
				espacos[cont] = ' ';
		}
		espacos[cont] = '\0';
		
		//imprimindo espaços e string
		printf("%s%s",txt,espacos);
		
	}else{
		
		//Centralizado
			//Adicionando espaços no vetor
		for(cont = 0 ;cont< ((qtEspaco)/2)-1 ; cont++){
				espacos[cont] = ' ';
		}
		espacos[cont] = '\0';
		printf("%s%s%s",espacos,txt,espacos);
		
		//espaco extra para strng de tamanho impar e finalizando string de espaços
		if( strlen(txt)%2 != 0){
			printf(" ");
		}
	
	}
	
	
	
	//barra lateral direita
	printf(" %c\n",BARRA_LATERAL);
}


//Objetivo: Imprime os espacos laterais do menu apos a string e a barra lateral a direita
//Entrada:  Recebe uma string, e a quantidade de espacos anteriores a ela
//Retorno:  Nulo;
void addEspacoBarraLateral(char *texto,int espAnterior){
	//Variaveis
	int cont,qtEspaco = 0;
	char espacos[TAM_HORIZONTAL];
		
	//Desenvolvimento
		//recebendo a quantidade de espacos
	qtEspaco = strlen(texto);
	qtEspaco += espAnterior ;
	qtEspaco = TAM_HORIZONTAL - qtEspaco;
	
	//imprimindo espacos e barra lateral
	fflush(stdin);
	for(cont = 0 ;cont<qtEspaco;cont++){
			
		espacos[cont] = ' ';
	}
	espacos[cont] = '\0';
	printf("%s%c\n",espacos,BARRA_LATERAL);
	
}


//Objetivo: Imnprime os espacos em branco da tabela 
//Entrada: Recebe a quantidade de linhas que serão impressos
//Saída: NULL;
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

