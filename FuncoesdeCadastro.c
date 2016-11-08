#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include "structs.c"

//macros importadas
#define POS_Y_TOPO 2
#define NOME_OPCOES 100

//Prototipos________________________________________________________________________________________________

void cadastraProprietario(int *qtdeCadastros,Proprietario *prop,char *topo);
void alteraProprietario(int qtdeCadastros,Proprietario *prop,char *topo);
void cadastraVeiculo(int *qtdeVeiculos,Veiculo *veic,char *topo);

//Funcoes_____________________________________________________________________________________________________

//Cadastra o proprietario
//Entrada : referencia a quantidade de cadastros e a struct
//Retorno : NULO
void cadastraProprietario(int *qtdeCadastros,Proprietario *prop,char *topo)
{
	//variaveis
	
	int flag;
	
	//Desenvolvimento
	
	leValidaString("Insira o nome: ",topo,prop[*qtdeCadastros].nome,MIN_NOME,MAX_NOME,">>>ERRO: Insira um nome valido...");

				do{
					flag=0;
					leValidaString("Insira o CPF: ",topo,prop[*qtdeCadastros].cpf,MIN_NOME,TAM_CPF,">>>ERRO: CPF Invalido...");
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
				
				leValidaString("Insira o Endereco: ",topo,prop[*qtdeCadastros].endereco,MIN_ENDERECO,MAX_ENDERECO,">>>ERRO: Endereco Invalido...");
				
				/*leValidaInt("Insira o telefone: ",menuProprietario[0],">>>ERRO: Endereco invalido...",2,MAX_TELEFONE,&prop[qtdeCadastros].tefefone);
				printf("%d",prop[qtdeCadastros].tefefone);
				system("pause");
				*/
				*qtdeCadastros=*qtdeCadastros+1;
}

//Altera um dado do Propeitario
//Entrada : referencia a quantidade de cadastros e a struct
//Retorno : NULO
void alteraProprietario(int qtdeCadastros,Proprietario *prop,char *topo)
{
	//variaveis
	
	int opMenu,contador,qtdeEncontrado=0,qtdeLetras,cont;    /*qtdeEncontrado = qtde de nomes encontrados pela pesquisa */
	char menuAlterar[3][NOME_OPCOES],nomePesquisa[MAX_NOME];
	char *aux,copy[100]; /* vetor auxiliar para comparar*/
	
	//Desenvolvimento
	
	strcpy(menuAlterar[0],"1-Nome");
	strcpy(menuAlterar[1],"2-Endereco");
	strcpy(menuAlterar[2],"3-Telefone");
	opMenu = menuOpcoes(3,menuAlterar,"Alterar");
	if(opMenu==1){
		leValidaString("Informe o Nome para Pesquisa : ",topo,nomePesquisa,MIN_NOME,MAX_NOME,">>>ERRO: Insira um nome valido...");
		qtdeLetras=strlen(nomePesquisa);
			for(contador=0;contador<qtdeLetras;contador++)
			{
				aux=strchr(prop[0].nome,nomePesquisa[contador]); /* obtem a primeira ocorrencia do primeiro caracter da string2 na string1 */
				copy[contador] = *aux;
			}
			copy[qtdeLetras] = '\0';
			if(!strcmp(copy,nomePesquisa)){ /* se o array copy for igual a string que queriamos encontrar entao devolvemos TRUE */
				printf("String encontrada = %s\n",copy);
				qtdeEncontrado++;
				getch();
			}
			else{ 
				printf("String nao encontrada \n");/* caso contrario retornamos FALSE */
				getch();
			}

	}
}

//Cadastra veiculos
//Entrada : referencia a quantidade de Veiculos e a struct
//Retorno : NULO
void cadastraVeiculo(int *qtdeVeiculos,Veiculo *veic,char *topo)
{
	//variaveis
	
	int flag;
	
	//Desenvolvimento
	
	do{
		flag=0;
		leValidaString("Informe a Placa do Veiculo: ",topo,veic[*qtdeVeiculos].placa,0,MAX_PLACA,">>>ERRO: Placa Invalida");
		if(validaPlaca(veic[*qtdeVeiculos].placa)==0){
			flag=0;
			gotoxy(2,POS_Y_TOPO+3);
			printf("Placa Invalida");
			getch();
		}else{
		flag = 1;
		}
	}while(flag==0);
	leValidaString("Insira o Modelo: ",topo,veic[*qtdeVeiculos].modelo,MIN_ENDERECO,MAX_ENDERECO,">>>ERRO: Modelo Invalido...");
	leValidaString("Insira o Fabricante: ",topo,veic[*qtdeVeiculos].fabricante,MIN_ENDERECO,MAX_ENDERECO,">>>ERRO: Fabricante I;nvalido...");
	leValidaInt("Insira o Ano de Fabricacao: ",topo,">>>ERRO: Ano Invalido",MIN_ANO,MAX_ANO,&veic[*qtdeVeiculos].ano);
	qtdeVeiculos++;
}
