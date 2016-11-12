#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include "structs.c"
#include "defines.c"


//Prototipos________________________________________________________________________________________________

void removeQuebraLinha(char *valString);
void leValidaInt(char *mens,char *topo,char *msgErro,int min, int max, int *valor);
void leValidaFloat(char *mens,char *topo,char *msgErro,int min, int max, float *valorF);
int leValidaString(char *valorS,char *titulo,char *topo,int tamanhoMin , int tamanhoMax,int tipoString, int aceitaEspaco);
void leValidaOpcao(char *opcao,char *titulo,char *opcoes);
int validaCPF (char *cpf);
char * formataCPF (char *cpf);
int validaPlaca(char *placa);
int verificaIntRepetido(int qtde,int *valor,char *msgErro);
int verificaStringRepetida(int *qtde,Proprietario *prop,char *msgErro);

//int leValidaInt(char *mens,char *topo,int valorMin, int valorMax, int *valorI);
int leituraDadosChar(char *valor,int tamMax,int posInicial,int opEntrada,int opEspaco);
void apagaCaracter(int posX, int posY);
int verificaCharEspecifico(int op,int espaco,char valorC);

//Funcoes_____________________________________________________________________________________________________


/// Objeitvo : Ler e validar uma string;
/* Paramentros : Referencia ao titulo ,a mensagem do topo, a string , tamanho minimo e tamanho maximo(sera considerado o tamanho da string, ignoranando caracteres superiores),
referencia a mensagem de erro, tipo de string que sera lidoe se vai aceitar espaco(1 sim e 0 nao);*/
// Retorno : 1 letura com sucesso(ENTER) e 0 leitura cancelada(ESC);
int leValidaString(char *valorS,char *titulo,char *topo,int tamanhoMin,int tamanhoMax,int tipoString,int aceitaEspaco){
	//variaveis
	int flag,cont,tecla,tamTxt;
	
	//desenvolvimento
	do{
		//Mensagem de leitura e tabela
		system("cls"); 
		janelaMenu();
		imprimeCentralizado(topo,POS_Y_TOPO);
		gotoxy(2,POS_Y_TOPO+2);
		printf("%s",titulo);
		
		
		//Leitura dos dados
		if(leituraDadosChar(valorS,tamanhoMax,strlen(titulo),tipoString,aceitaEspaco) == 0){
			//saindo pelo ESC
			return 0;
		}
		
		tamTxt = strlen(valorS);
		
		//verificando tamanho e validade de espacos do texto	
		if(tamTxt<tamanhoMin){
			flag = 0;
			
			if(tamanhoMax != tamanhoMin){
				printf("\n>>>ERRO DE LEITURA:O dado deve ter um tamanho entre %d e %d caracteres...",tamanhoMin,tamanhoMax);
				getch();
			}else{
				printf("\n>>>ERRO DE LEITURA:O dado deve ter um tamanho de %d caracteres...",tamanhoMax);
				getch();	
			}
			
		}else{
			for(cont = 0;cont < tamTxt;cont++){
				if(valorS[cont] == ' '){
					flag = 0;
				}else{
					flag = 1 ;
					break;
				}
			}
			
			//mensagem de erro em caso de invalidade
			if(flag == 0){
				printf("\n>>>ERRO DE LEITURA:O dado nao pode conter somente espacos em branco...");
				getch();
			}
		}
	
	}while(flag == 0);
	
	//finalizaÁ„o
	return 1;
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
//Parametros: Referencia a mensagem de leitura, ao tÛpico no topo e a mensagem de erro, valor inteiro minimo e maximo e referencia ao vetor de valor inteiro;
//Retorno: Nenhum;
void leValidaInt(char *mens,char *topo,char *msgErro,int min, int max, int *valor){
	//Variaveis
	int flag;
	
	//Desenvolvimento
	do{
		//Mensagem de leitura e tabela
		flag = 1;
		system("cls"); 
		janelaMenu();
		imprimeCentralizado(topo,POS_Y_TOPO);
		gotoxy(2,POS_Y_TOPO+2);
		printf("%s",mens);
		
		//leitura de dados
		fflush(stdin);
		flag = scanf("%d",valor);
		fflush(stdin);
		
		//Verificando dados
		if(*valor< min || *valor > max || flag == 0 ){
			gotoxy(2,POS_Y_TOPO+3);
			printf("%s",msgErro);
			getch();
			
			flag = 0;
		}
		
	}while(flag == 0);
}


//Objetivo: Ler e validar um numero real;
//Parametros: Referencia a mensagem de leitura,ao topo e a mensagem de erro, valor e minimo permitido e endereco de valor real;
//Retorno: Nenhum;
void leValidaFloat(char *mens,char *topo,char *msgErro,int min, int max, float *valorF){
	//Variaveis
	int flag;
	
	//Desenvolvimento
	do{
		//Mensagem de leitura e tabela
		system("cls"); 
		janelaMenu();
		imprimeCentralizado(topo,POS_Y_TOPO);
		gotoxy(2,POS_Y_TOPO+2);
		printf("%s",mens);
		
		//leitura de dados
		fflush(stdin);
		flag = scanf("%f",valorF);
		fflush(stdin);
		
		//Verificando dados
		if(*valorF< min || *valorF > max || flag == 0){
			gotoxy(2,POS_Y_TOPO+3);
			printf("%s",msgErro);
			getch();
			
			flag = 0;
		}
	}while(flag == 0);
}


/**************************************************************
*  Nome      : validaCPF                                      *  
*  Descricao : Valida um CPF                                  *
*  Par√¢metros: endere√ßo inicial da string cpf                 *
*  Retorno   : 1 - cpf v√°lido, 0 - cpf inv√°lido               * 
**************************************************************/ 
int validaCPF (char *cpf)
	{
       // cpfs invalidos      
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
          
         // transforma os caracteres do cpf em numeros  
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
*  Parametros: endere√ßo inicial da string cpf                 *
*  Retorno   : endere√ßo de memoria onde comeca a string       * 
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


//Remove o \n da string;
//Entrada: Referencia a string;
//Retorno: NULO;
void removeQuebraLinha(char *valString){
	
	if(valString[strlen(valString)-1]=='\n'){
		valString[strlen(valString)-1] = '\0';
	}
	
}


// Validar a Placa
//Entrada: referencia a placa
// Retorno: 1 - placa Valida 0- placa invalida
int validaPlaca(char *placa){
	//variaveis
	int cont;
	
	//Desenvolvimento
	//___verificar letras
	
	for(cont=0;cont<3;cont++){
		placa[cont] = toupper(placa[cont]);
		
		if (placa[cont] < 65 || placa[cont] > 90 ){
        	return 0;
		}
	}
	
	//Verifica numeros da placa
	for(cont = 3;cont < 6;cont++ ){
		if(placa[cont] < 48 || placa[cont] > 57){
			return 0;
		}
	}	
	
	
	//Finalizacao com sucesso
	return 1;
}


//Verificar se existe uma string  repetida
//Entrada: referencia a quantidade de itens e a string a ser analisada
//Retorno : 1 para repetido 0 - N„o repetido
int verificaStringRepetida(int *qtde,Proprietario *prop,char *msgErro)
{
	//variaveis
	
	int contador,contador2;
	
	//Desenvolvimento
	for(contador=0;contador<*qtde;contador++)
	{
		for(contador2=contador+1;contador2<*qtde+1;contador2++)
		{
			if(strcmp(prop[contador].cpf,prop[contador2].cpf)==0)
			{
				gotoxy(15,6);
				printf(msgErro);
				getch();
				return 0;
			}
		}
	}
	return 1;
}


//Verificar se existe um numero inteiro repetido
//Entrada: referencia a quuantidade de itens e ao valor a ser analisado
//Retorno : 1 para repetido 0 - N„o repetido
int verificaIntRepetido(int qtde,int *valor,char *msgErro)
{
	//variaveis
	
	int contador,contador2;
	
	//Desenvolvimento
	
	for(contador=0;contador<qtde;contador++)
	{
		for(contador2=contador+1;contador2<qtde+1;contador2++)
		{
			if(valor[contador]==valor[contador2])
			{
				gotoxy(15,6);
				printf(msgErro);
				getch();
				return 0;
			}
		}
	}
	return 1;
}


//Objetivo: Le os dados em tempo real de click;
/*Entrada: Enderecamento da string, tamanho maximo permitido da string, posicao inicial do cursor, o tipo de entrada que sera permitido => 
		   1(somente letras), 2(char com caracteres especiais), 3 (char e numeros) e aceitar espaco(1 sim e 0 nao); 	*/
//Saida: 0 caso de finalizacao por ESC e 1 por ENTER;
int leituraDadosChar(char *valor,int maxCaracteres,int posInicial,int opEntrada,int opEspaco){
	//variavies
	char charAtual;
	int cont = 0,tecla;
	
	//dsesenvolvimento
	do{
		//leitura da tecla
		fflush(stdin);
		tecla = getch();
		
		//apagar caracter
		if(tecla == BACKSPAECE && cont != 0){
			
			cont--;
			apagaCaracter( posInicial + (cont) ,POS_Y_OPCOES);
		
		}else if(cont < maxCaracteres){
		//tipos de dados que entram na string
			charAtual=tecla;
			
			if(verificaCharEspecifico(opEntrada,opEspaco,charAtual) == 1){
				printf("%c",tecla);
				fflush(stdin);
				valor[cont] = tecla;
				cont++;
			}
			
			/*if((tecla >= TAB_0 && tecla <= TAB_9  ) || (tecla >= TAB_a && tecla <= TAB_z  ) || (tecla >= TAB_A && tecla <= TAB_Z  ) || (tecla >= TAB_VIRGULA && tecla <= TAB_BARRA ) || (tecla ==  ESPACO)){
				printf("%c",tecla);
				fflush(stdin);
				valor[cont] = tecla;
				cont++;	
			}*/
		}
		
		
	}while(tecla != ESC && tecla != ENTER);
	
	
	//finalizaÁ„o
	if(tecla == ESC){
		
		valor[0] = '\0';
		return 0;
	
	}else{
		
		valor[cont] = '\0';
		return 1;
	
	}
}


//Objetivo:	Posiciona o cursor a um espaco atras e apaga o caracter apresentado
//Entrada:	Posicao atual do cursor em X e Y; 
//SaÌda: 	NULO;
void apagaCaracter(int posX, int posY){
	
	posX+=2;
	posY--;
	
	//desenvolvimento
	gotoxy(posX,posY);
	
	/*
  	coordDelete.X = posX+2;
  	coordDelete.Y = POS_Y_OPCOES-1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coordDelete);
  */
 	
	 printf("%c",' ');
	
	/*
	coordDelete.X = posX+2;
  	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coordDelete);
	*/
	gotoxy(posX,posY);
}


//objetivo: Verifica o tipo de dado;
//entrada: Tipo de verificacao =  1(somente letras), 2(char com caracteres especiais), 3(letra e numeros), 4(char e numero), 5(int), 6(float) e aceitar espaco(1 sim e 0 nao);
//Retorno: retorna 0 para invalido e 1 para valido;
int verificaCharEspecifico(int op,int espaco,char valorC){
	//variveis
	//desenvolvimento
	switch(op){
		//1-letras_________________________________________________________________________________________________________
		case TIPO_LETRAS:
			if((valorC >= TAB_a && valorC <= TAB_z ) || (valorC >= TAB_A && valorC <= TAB_Z)){
				return 1;
			}
		break;
		
		//2-Caracteres especiais e letras_________________________________________________________________________________________________________
		case TIPO_LETRAS_ESPECIAIS:
			if((valorC >= TAB_a && valorC <= TAB_z) || (valorC >= TAB_A && valorC <= TAB_Z) || (valorC >= TAB_INTERROGACAO && valorC <= TAB_BARRA)){
				return 1;
			}
		break;
		
		//3-Letras e numeros_________________________________________________________________________________________________________
		case TIPO_LETRAS_NUMEROS:
			if((valorC >= TAB_a && valorC <= TAB_z ) || (valorC >= TAB_A && valorC <= TAB_Z) || (valorC >= TAB_0 && valorC <= TAB_9)){
				return 1;
			}
		break;
		
		//4-letras, caracteres especiais e numeros_________________________________________________________________________________________________________
		case TIPO_LETRAS_ESPECIAIS_NUMEROS:
			if((valorC >= TAB_a && valorC <= TAB_z ) || (valorC >= TAB_A && valorC <= TAB_Z) || (valorC >= TAB_0 && valorC <= TAB_9) || (valorC >= TAB_INTERROGACAO && valorC <= TAB_BARRA)){
				return 1;
			}
		break;
		
		//5-Inteiro_________________________________________________________________________________________________________
		case TIPO_INTEIRO:
			if(valorC >= TAB_0 && valorC <= TAB_9 ){
				return 1;
			}
		break;
		
		//6-Real_________________________________________________________________________________________________________
		case TIPO_REAL:
			if( (valorC >= TAB_0 && valorC <= TAB_9) || valorC == TAB_PONTO){
				return 1;
			}
		break;
		
	}
		
	//espaco
	if(espaco == SIM){
		if(valorC == TAB_ESPACO){
			return 1;
		}
	}
	
	//caso de invalidade do caracter
	return 0;
	
}
