#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include "structs.c"
#include "defines.c"


//Prototipos________________________________________________________________________________________________

//Proprietario
void cadastraProprietario(int *qtdeCadastros,Proprietario *prop,char *topo);
void cadastraVeiculo(int *qtdeVeiculos,Veiculo *veic,char *topo);
void excluiProprietario(int qtdeCadastros,Proprietario *prop,char *topo);


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

/*do{
		flag=0;
		leValidaString("Insira o CPF: ",topo,prop[*qtdeCadastros].cpf,MIN_NOME,TAM_CPF,">>>ERRO: CPF Invalido...");
		if(validaCPF(prop[*qtdeCadastros].cpf)==0){
		flag=1;
		gotoxy(2,POS_Y_TOPO+3);
		printf(">>>ERRO: CPF INVALIDO....");
		getch();
	}									
//	if(verificaStringRepetida(qtdeCadastros,prop,">>>ERRO: CPF Repetido")==0)
//	{
///	}	
	}while(flag==1);
	*/
				
				
//	leValidaString("Insira a Descricao do Endereco: ",topo,prop[*qtdeCadastros].descricao, MIN_DESCRICAO,MAX_DESCRICAO,">>>ERRO: Descricao Invalido...");
//	leValidaString("Insira o Estado : ",topo,prop[*qtdeCadastros].estado,MIN_ESTADO,MAX_ESTADO,">>>ERRO: Estado Invalido...");
//	leValidaString("Insira a Cidade: ",topo,prop[*qtdeCadastros].cidade, MIN_CIDADE,MAX_CIDADE,">>>ERRO: Cidade Invalida...");
//	leValidaString("Insira o Telefone: ",topo,prop[*qtdeCadastros].telefone, MIN_TELEFONE,MAX_TELEFONE,">>>ERRO: Telefone Invalido...");
	prop[*qtdeCadastros].cadastrado=1;
	*qtdeCadastros=*qtdeCadastros+1;
}


//Excluir Porprietario
//Entrada : referencia a quantidade de cadastros e a struct
//Retorno : NULO
void excluiProprietario(int qtdeCadastros,Proprietario *prop,char *topo)
{
	//variaveis
	
	int opMenu,contador,contador2=0,qtdeEncontrada=0,qtdeLetras,cont;  //AUXILIARES   /*qtdeEncontrado = qtde de nomes encontrados pela pesquisa */
	char menuAlterar[3][NOME_OPCOES],menuEndereco[3][NOME_OPCOES];  // Menu 
	char copiaNome [qtdeCadastros][NOME_OPCOES],novoNome[MAX_NOME],pesquisaNome[MAX_NOME]; // ALTERA NOME
	char copiaDescricao [qtdeCadastros][NOME_OPCOES],novaDescricao[MAX_NOME],pesquisaDescricao[MAX_DESCRICAO]; // ALTERA DESCRICAO
	char copiaEstado [qtdeCadastros][NOME_OPCOES],novoEstado[MAX_ESTADO],pesquisaEstado[MAX_ESTADO]; // ALTERA ESTADO
	char copiaCidade [qtdeCadastros][NOME_OPCOES],novaCidade[MAX_CIDADE],pesquisaCidade[MAX_CIDADE];
	char copiaTelefone [qtdeCadastros][NOME_OPCOES],novoTelefone[MAX_TELEFONE],pesquisaTelefone[MAX_TELEFONE]; // ALTERA CIDADE
	
	//Desenvolvimento
	
	strcpy(menuAlterar[0],"1-Nome");
	strcpy(menuAlterar[1],"2-Endereco");
	strcpy(menuAlterar[2],"3-Telefone");
	strcpy(menuEndereco[0],"1-Descricao");
	strcpy(menuEndereco[1],"2-Estado");
	strcpy(menuEndereco[2],"3-Cidade");
	
	
	//EXCLUI NOME
	leValidaString("Informe o Nome para Exclusao : ",topo,pesquisaNome,MIN_NOME,MAX_NOME,">>>ERRO: Insira um nome valido...");
	for(contador=0;contador<qtdeCadastros+1;contador++)
	{
		if(strstr(prop[contador].nome,pesquisaNome))
		{
				strcpy(copiaNome[qtdeEncontrada+1],prop[contador].nome);
				qtdeEncontrada++;
			}
		}
		if(qtdeEncontrada==0) 
		{			
			printf(">>>Erro: Nome não Encontrado...");
			getch();
		}		
		else
		{
			opMenu = menuOpcoes(qtdeEncontrada,copiaNome+1,"Nomes encontrados");  //Menu de Nomes Encontrados
			for(contador=1;contador<qtdeEncontrada+1;contador++)
			{
				if(opMenu==contador)
				{

				

					for(contador2=0;contador2<qtdeCadastros;contador2++)
					{
						if(strcmp(copiaNome[opMenu],prop[contador2].nome)==0)
						{
								strcpy(prop[contador2].nome,"\0");  
								printf("Nome Excluido ");	 
								getch();
						}
					}
					/*				
				}else{
					printf("erro");
					getch();
				}
				*/
				}
			}
			for(contador=0;contador<qtdeCadastros;contador++)
			{
				printf("NOME %s \n",prop[contador].nome);
			}
		}
		getch();
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
		leValidaString("Informe a Placa do Veiculo: ",topo,veic[*qtdeVeiculos].placa,TAM_PLACA,TAM_PLACA,">>>ERRO: Placa Invalida");
		if(validaPlaca(veic[*qtdeVeiculos].placa)==0){
			flag=0;
			gotoxy(2,POS_Y_TOPO+3);
			printf("Placa Invalida");
			getch();
		}else{
		flag = 1;
		}
	}while(flag==0);
//	leValidaString("Insira o Modelo: ",topo,veic[*qtdeVeiculos].modelo,MIN_ENDERECO,MAX_ENDERECO,">>>ERRO: Modelo Invalido...");
//	leValidaString("Insira o Fabricante: ",topo,veic[*qtdeVeiculos].fabricante,MIN_ENDERECO,MAX_ENDERECO,">>>ERRO: Fabricante I;nvalido...");
//	leValidaInt("Insira o Ano de Fabricacao: ",topo,">>>ERRO: Ano Invalido",MIN_ANO,MAX_ANO,&veic[*qtdeVeiculos].ano);
	*qtdeVeiculos = *qtdeVeiculos = 1;
}

