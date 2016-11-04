#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include "structs.c"

#define POS_Y_TOPO 2	//PosiÁ„o minima das mensagens (com execao do menu principal)

//Prototipos________________________________________________________________________________________________

void removeQuebraLinha(char *valString);
void leValidaInt(char *mens,char *topo,char *msgErro,int min, int max, int *valor);
void leValidaFloat(char *mens,char *topo,char *msgErro,int min, int max, float *valorF);
void leValidaString(char *titulo,char *topo,char *texto,int tamanhoMin , int tamanhoMax,char *msgErro);
void leValidaOpcao(char *opcao,char *titulo,char *opcoes);
int validaCPF (char *cpf);
char * formataCPF (char *cpf);
int validaPlaca(char *placa);
int verificaIntRepetido(int qtde,int *valor,char *msgErro);
int verificaStringRepetida(int *qtde,Proprietario *prop,char *msgErro);
void cadastraProprietario(int *qtdeCadastros,Proprietario *prop);
//Funcoes_____________________________________________________________________________________________________


// Objeitvo : Ler e validar uma string;
// Paramentros : Referencia ao titulo ,a mensagem do topo, a string , tamanho minimo e tamanho maximo(sera considerado o tamanho da string, ignoranando caracteres superiores) e referencia a mensagem de erro;
// Retorno : Nenhum;
void leValidaString(char *titulo,char *topo,char *texto,int tamanhoMin , int tamanhoMax,char *msgErro){
	//variaveis
	int flag,cont,tamTxt;
	
	//desenvolvimento
	do{
		//Mensagem de leitura e tabela
		system("cls"); 
		janelaMenu();
		imprimeCentralizado(topo,POS_Y_TOPO);
		gotoxy(2,POS_Y_TOPO+2);
		printf("%s",titulo);
		
		//gotoxy(19,4);
		fflush(stdin);
		fgets(texto,tamanhoMax,stdin);
		fflush(stdin);
		
		//tirando '\n'
		removeQuebraLinha(texto);	
		
		tamTxt = strlen(texto);
		
		//verificando tamanho e validade de espacos do texto	
		if(tamTxt<tamanhoMin){
			flag = 0;
		}else{
			for(cont = 0;cont < tamTxt;cont++){
				if(texto[cont] == ' '){
					//erro caso so haja espacamento
					if(cont == tamTxt-1){
						
						flag = 0;
					}
				}else{
					flag = 1 ;
					break;
				}
			}
		}
		
		if(flag == 0){
			gotoxy(2,POS_Y_TOPO+3);
			printf("%s",msgErro);
			getch();
			
			flag = 0;
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
//Cadastra o proprietario
//Entrada : referencia a quantidade de cadastros e a struct
//Retorno : NULO
void cadastraProprietario(int *qtdeCadastros,Proprietario *prop)
{
	//variaveis
	int flag;
	//Desenvolvimento
	leValidaString("Insira o nome: ","1-Cadastrar cliente",prop[*qtdeCadastros].nome,2,MAX_NOME,">>>ERRO: Insira um nome valido...");

				do{
					flag=0;
					leValidaString("Insira o CPF: ","1-Cadastrar cliente",prop[*qtdeCadastros].cpf,MIN_NOME,TAM_CPF,">>>ERRO: CPF Invalido...");
					if(validaCPF(prop[*qtdeCadastros].cpf)==0){
						flag=1;
						gotoxy(2,POS_Y_TOPO+3);
						printf(">>>ERRO: CPF INVALIDO....");
						getch();
					}									
					if(verificaStringRepetida(qtdeCadastros,prop,">>>ERRO: CPF Repetido")==0)
					{
						flag=1;
					}	
				}while(flag==1);
				
				leValidaString("Insira o Endereco: ","1-Cadastrar cliente",prop[*qtdeCadastros].endereco,MIN_ENDERECO,MAX_ENDERECO,">>>ERRO: Endereco Invalido...");
				
				/*leValidaInt("Insira o telefone: ",menuProprietario[0],">>>ERRO: Endereco invalido...",2,MAX_TELEFONE,&prop[qtdeCadastros].tefefone);
				printf("%d",prop[qtdeCadastros].tefefone);
				system("pause");
				*/
				*qtdeCadastros=*qtdeCadastros+1;
}
//Verificar se existe uma string  repetida
//Entrada: referencia a quantidade de itens e a string a ser analisada
//Retorno : 1 para repetido 0 - N„o repetido
int verificaStringRepetida(int *qtde,Proprietario *prop,char *msgErro)
{
	//variaveis
	
	int contador,contador2;
	
	//Desenvolvimento
	printf("%d",*qtde);
	getch();
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
	
	for(contador=0;contador<qtde-1;contador++)
	{
		for(contador2=contador+1;contador2<qtde;contador2++)
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
