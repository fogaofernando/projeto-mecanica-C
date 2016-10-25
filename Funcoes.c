#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

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
#define ESP_BRANCO   3		  		//Valor dado + os caracteres ja impressos

//Prototipos________________________________________________________________________________________________

void removeQuebraLinha(char *valString);
void leValidaInt(char *titulo,char *msgErro,int valorMin, int valorMax, int *valor);
void leValidaFloat(char *titulo,char *msgErro,int min, int max, float *valorF);
void leValidaString(char *titulo,char *texto,int tamanhoMin , int tamanhoMax);
void leValidaOpcao(char *opcao,char *titulo,char *opcoes);
int validaCPF (char *cpf);
char * formataCPF (char *cpf);
int menu(int qtOp,char opcoes[][NOME_OPCOES],char *apresentaMenu);
void tabelaHorizontal(int op);
void imprimeApresentacaoMenu(char *apMenu);
void addEspacoBarraLateral(char *texto, int espAnterior);
void espacosBranco();


//Funcoes_____________________________________________________________________________________________________


// Objeitvo : Ler e validar uma string
// Paramentros : Referencia ao titulo , a string , tamanho minimo e tamanho maximo(sera considerado o tamanho da string, ignoranando caracteres superiores)
// Retorno : Nenhum;
void leValidaString(char *titulo,char *texto,int tamanhoMin , int tamanhoMax){
	//variaveis
	int flag,cont,tamTxt;
	
	//desenvolvimento
	do{
		flag = 1;
		//leitura de dados
		system("cls");
		printf(titulo);
		fflush(stdin);
		fgets(texto,tamanhoMax,stdin);
		fflush(stdin);
		
		//tirando '\n'
		removeQuebraLinha(texto);	
		
		tamTxt = strlen(texto);
		
		//verificando tamanho e validade de espacos do texto	
		if(tamTxt<tamanhoMin){
			flag = 0;
			printf(">>> ERRO: O tamanho do texto esta em desacordo com o permitido...\n");
			system("pause");
		}else{
			for(cont = 0;cont < tamTxt;cont++){
				if(texto[cont] == ' '){
					//erro caso so haja espacamento
					if(cont == tamTxt-1){
						printf(">>> ERRO: O texto nao pode ser composto somente de espaco...\n");
						system("pause");
						flag = 0;
					}
				}else{
					flag = 1 ;
					break;
				}
			}
		}
		
		
	}while(flag == 0);
}


// Objetivo : ler e validar uma opcao
// Paramentros : referencia ao vetor das opcoes
// Retorno : opcvalidada;
void leValidaOpcao(char *opcao,char *titulo,char *opcoes){
	printf(titulo);
	do{
		*opcao=getch();
		*opcao=toupper(*opcao);
	}while(strchr(opcoes,*opcao)==NULL);
}

//Objetivo: Ler e validar um numero inteiro;
//Parametros: Referencia ao titulo e a mensagem de erro, valor e minimo permitido e endereco de valor;
//Retorno: Nenhum;
void leValidaInt(char *titulo,char *msgErro,int min, int max, int *valor){
	//Variaveis
	int flag;
	
	//Desenvolvimento
	do{
		//leitura de dados
		system("cls");
		printf(titulo);
		fflush(stdin);
		flag = scanf("%d",valor);
		fflush(stdin);
		
		//Verificando dados
		if(*valor< min || *valor > max || flag ==0){
			printf(msgErro);
			system("pause");
			flag = 0;
		}
	}while(flag == 0);
}


//Objetivo: Ler e validar um numero real;
//Parametros: Referencia ao titulo e a mensagem de erro, valor e minimo permitido e endereco de valor real;
//Retorno: Nenhum;
void leValidaFloat(char *titulo,char *msgErro,int min, int max, float *valorF){
	//Variaveis
	int flag;
	
	//Desenvolvimento
	do{
		//leitura de dados
		system("cls");
		printf(titulo);
		fflush(stdin);
		flag = scanf("%f",valorF);
		fflush(stdin);
		
		//Verificando dados
		if(*valorF< min || *valorF > max || flag == 0){
			printf(msgErro);
			system("pause");
			flag = 0;
		}
	}while(flag == 0);
}

/**************************************************************
*  Nome      : validaCPF                                      *  
*  Descricao : Valida um CPF                                  *
*  Parâmetros: endereço inicial da string cpf                 *
*  Retorno   : 1 - cpf válido, 0 - cpf inválido               * 
**************************************************************/ 
int validaCPF (char *cpf)
	{
       // cpfs inválidos        
       char *cpfInval[] = {"11111111111",
                         "22222222222",
                         "33333333333",
                         "44444444444",
                         "55555555555",
                         "66666666666",
                         "77777777777",
                         "88888888888",
                         "99999999999"}; 
		
		int cont,retorno =1,aux2,dig[11],soma=0,digVeri[2];
		
		if(strlen(cpf) != 11)
		   return 0;
		 
         // verifica se cpf so contem nros iguais  
	     for(cont=0;cont<9;cont++)
         {
               if(strcmp(cpfInval[cont],cpf)==0)
               {
                  retorno =0;
                  break;
               }
         } 
         
         if(retorno ==0)
            return retorno;
          
         // transforma os caracteres do cpf em números     
         for(cont=0;cont<strlen(cpf);cont++)
         {
                dig[cont] = cpf[cont] - '0';
         }
         
         // obtem o primeiro digito verificador
         aux2=10;
         for(cont=0;cont<9;cont++,aux2--)
         {
            soma+= dig[cont] * aux2;
         }
         digVeri[0]=soma % 11;
         digVeri[0]= digVeri[0]<2 ? 0 : 11-digVeri[0];
         
         // obtem o segundo digito verificador
         soma=0;
         aux2=11;
         for(cont=0;cont<10;cont++,aux2--)
         {
               if(cont==9)
                  soma+= digVeri[0] * aux2;
               else
                  soma+= dig[cont] * aux2;
         }
         digVeri[1]=soma % 11;
         digVeri[1]= digVeri[1]<2 ? 0 : 11-digVeri[1];
         if(digVeri[0]!=dig[9] || digVeri[1]!=dig[10])
         {
               retorno =0;               
         }
         return retorno;
}
/**************************************************************
*  Nome      : formataCPF                                     *  
*  Descricao : Formata um CPF                                 *
*  Parâmetros: endereço inicial da string cpf                 *
*  Retorno   : endereço de memória onde comeca a string       * 
*               com CPF formatado ou NULL                     *
**************************************************************/ 
char * formataCPF (char *cpf)
{
static char cpfFormatado[15];
   if(validaCPF(cpf) == 0)
      return NULL;
   else
   {
        sprintf(cpfFormatado,"%3.3s.%3.3s.%3.3s-%2.2s",
            cpf,cpf+3,cpf+6,cpf+9);
        return cpfFormatado;    
   }   
    
}

//objetivo: cadastrar um cliente
//Parâmetros: referencia a struct
//retorno : nenhum
//void cadastro(Proprietario *prop)
//{//
//	printf()
//}


//Imprime e informa opcoes escolhida de um menu 
//Recebe a quantidade de opcoes do menu, o enderecaamento de uma matriz com as opcoes armazenadas e endereco da string com o titulo do menu;
//Retorna a opcoes escolhida, 0 em caso de finalizacoes do programa pelo ESC;
int menu(int qtOp,char opcoes[][NOME_OPCOES],char *apresentaMenu){
	//variaveis
	int tecla = -1,opAtual = 1,cont;	// a tecla vai receber a numeração do botão clicado de acordo com a  tabela ASCII
	
	//desenvolvimento
	system("cls");
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
					addEspacoBarraLateral(opcoes[cont],5);
					
				}else{
					printf("%c    %s",BARRA_LATERAL,opcoes[cont]);
					addEspacoBarraLateral(opcoes[cont],5);
				}
				
			}	
			espacosBranco();
			tabelaHorizontal(2);
		}
		
		//leitura do teclado
		fflush(stdin);
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
			for(cont = 0;cont<qtOp;cont++){
				if(opAtual == cont+1){
					printf("%c  %c %s",BARRA_LATERAL,IMG_OP,opcoes[cont]);
					addEspacoBarraLateral(opcoes[cont],5);
				}else{
					printf("%c    %s",BARRA_LATERAL,opcoes[cont]);
					addEspacoBarraLateral(opcoes[cont],5);
				}
				
			}	
			espacosBranco();
			tabelaHorizontal(2);
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
					addEspacoBarraLateral(opcoes[cont],5);
				}else{
					printf("%c    %s",BARRA_LATERAL,opcoes[cont]);
					addEspacoBarraLateral(opcoes[cont],5);
				}
				
			}	
		espacosBranco();
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
		printf("%c",BARRA_DIG02);	
	}else{
		printf("%c",BARRA_DIG04);	
	}
	
}

//Imprime o topico do menu
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

//Imprime os espacos laterais do menu apos a string e a barra lateral
//Recebe uma string, e a quantidade de espacos anteriores a ela 
void addEspacoBarraLateral(char *texto, int espAnterior){
	//Variaveis
	int cont,espaco = 0;
		
	//Desenvolvimento
		//recebendo os espaços
	espaco = strlen(texto);
	espaco += espAnterior ;
	espaco = TAM_HORIZONTAL - espaco;
	
	//printf("%d",espaco);
	
	//imprimindo espacos e barra lateral
	for(cont = 0 ;cont<espaco;cont++){
		printf(" ");
	}
	printf("%c\n",BARRA_LATERAL);
	
}


//Imnprime os espacos em branco da tabela do menu
void espacosBranco(){
	//Variaveis
	int cont,i;
	
	//Desenvolvimento
	for(i=0;i<ESP_BRANCO;i++){
		
		printf("%c",BARRA_LATERAL);
		for(cont = 0;cont < (TAM_HORIZONTAL - 1);cont++){
			printf(" ");
		}
		printf("%c\n",BARRA_LATERAL);
	}
}


//Remove o \n da string;
//Entrada: Referencia a string;
//Retorno: NULO;
void removeQuebraLinha(char *valString){
	
	if(valString[strlen(valString)-1]=='\n'){
		valString[strlen(valString)-1] = '\0';
	}
	
}




