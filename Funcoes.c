#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

#define SETA01 26
#define SETA02 175

//Prototipos________________________________________________________________________________________________

void removeQuebraLinha(char *valString);
void leValidaInt(char *mens,char *topo,char *msgErro,int min, int max, int *valor);
void leValidaFloat(char *mens,char *topo,char *msgErro,int min, int max, float *valorF);
void leValidaString(char *titulo,char *texto,int tamanhoMin , int tamanhoMax);
void leValidaOpcao(char *opcao,char *titulo,char *opcoes);
int validaCPF (char *cpf);
char * formataCPF (char *cpf);

void espacosBranco(int qtEsp);


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
//Parametros: Referencia a mensagem de leitura, ao t�pico no topo e a mensagem de erro, valor inteiro minimo e maximo e referencia ao vetor de valor inteiro;
//Retorno: Nenhum;
void leValidaInt(char *mens,char *topo,char *msgErro,int min, int max, int *valor){
	//Variaveis
	int flag;
	
	//Desenvolvimento
	do{
		//Mensagem de leitura e tabela
		system("cls"); 
		tabelaHorizontal(1);
		imprimeTxtTabela(topo,1);
		espacosBranco(2);
		imprimeTxtTabela(mens,0);
		tabelaHorizontal(2);
		printf("\n %c%c ",SETA01,SETA02);
		
		//leitura de dados
		fflush(stdin);
		flag = scanf("%d",valor);
		fflush(stdin);
		
		//Verificando dados
		if(*valor< min || *valor > max || flag ==0){
			system("cls"); 
			tabelaHorizontal(1);
			imprimeTxtTabela(topo,1);
			espacosBranco(2);
			imprimeTxtTabela(msgErro,0);
			tabelaHorizontal(2);
			printf("\n %c%c ",SETA01,SETA02);
		
			system("pause");
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
		tabelaHorizontal(1);
		imprimeTxtTabela(topo,1);
		espacosBranco(2);
		imprimeTxtTabela(mens,0);
		tabelaHorizontal(2);
		printf("\n %c%c ",SETA01,SETA02);
		
		//leitura de dados
		fflush(stdin);
		flag = scanf("%f",valorF);
		fflush(stdin);
		
		//Verificando dados
		if(*valorF< min || *valorF > max || flag == 0){
			system("cls"); 
			tabelaHorizontal(1);
			imprimeTxtTabela(topo,1);
			espacosBranco(2);
			imprimeTxtTabela(msgErro,0);
			tabelaHorizontal(2);
			printf("\n %c%c ",SETA01,SETA02);
		
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


//Remove o \n da string;
//Entrada: Referencia a string;
//Retorno: NULO;
void removeQuebraLinha(char *valString){
	
	if(valString[strlen(valString)-1]=='\n'){
		valString[strlen(valString)-1] = '\0';
	}
	
}




