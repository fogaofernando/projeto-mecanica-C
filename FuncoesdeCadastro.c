#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include "structs.c"
#include "defines.c"


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

				/*do{
					flag=0;
					leValidaString("Insira o CPF: ",topo,prop[*qtdeCadastros].cpf,MIN_NOME,TAM_CPF,">>>ERRO: CPF Invalido...");
					if(validaCPF(prop[*qtdeCadastros].cpf)==0){
						flag=1;
						gotoxy(2,POS_Y_TOPO+3);
						printf(">>>ERRO: CPF INVALIDO....");
						getch();
					}									
//					if(verificaStringRepetida(qtdeCadastros,prop,">>>ERRO: CPF Repetido")==0)
//					{
///					}	
				}while(flag==1);
				*/
				
				
//				leValidaString("Insira o Endereco: ",topo,prop[*qtdeCadastros].endereco,MIN_ENDERECO,MAX_ENDERECO,">>>ERRO: Endereco Invalido...");
				
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
	
	int opMenu,contador,contador2=0,qtdeEncontrada=0,qtdeLetras,cont,aux[10];    /*qtdeEncontrado = qtde de nomes encontrados pela pesquisa */
	char menuAlterar[3][NOME_OPCOES],nomePesquisa[MAX_NOME],copiaNome [qtdeCadastros][NOME_OPCOES];
	
	//Desenvolvimento
	
	strcpy(menuAlterar[0],"1-Nome");
	strcpy(menuAlterar[1],"2-Endereco");
	strcpy(menuAlterar[2],"3-Telefone");
	

	system("pause");
	
	//Opcao de pesquisa
	opMenu = menuOpcoes(3,menuAlterar,"Alterar");
	if(opMenu==1){
		leValidaString("Informe o Nome para Pesquisa : ",topo,nomePesquisa,MIN_NOME,MAX_NOME,">>>ERRO: Insira um nome valido...");
		for(contador=0;contador<qtdeCadastros+1;contador++)
		{
			if(strstr(prop[contador].nome,nomePesquisa))
			{
				aux[contador]=contador;    //Posição dos nomes Encontrados
				strcpy(copiaNome[qtdeEncontrada],prop[contador].nome);
				qtdeEncontrada++;
			}
		}
		//printf("NOME AQUI %s",copiaNome[0]);
		//getch();
		if(qtdeEncontrada==0) 
		{			
			printf(">>>Erro: Nome não Encontrado...");
			getch();
		}		
		else
		{
			//opMenu = menuOpcoes2(qtdeEncontrada,prop->copiaNome,"Nomes encontrados");  //Menu de Nomes Encontrados
			opMenu = menuOpcoes(qtdeEncontrada,copiaNome,"Nomes encontrados");  //Menu de Nomes Encontrados
			for(contador=1;contador<qtdeEncontrada+1;contador++)
			{
				if(opMenu==contador)
				{
					leValidaString("Informe o novo nome : ",topo,copiaNome[contador],MIN_NOME,MAX_NOME,">>>ERRO: Insira um nome valido..."); // Novo nome para a opcao escolhida
					strcpy(prop[aux[contador-1]].nome,copiaNome[contador]);    
				}else{
					printf("erro");
				}
			}
		}
		printf("NOVO NOME : %s",prop[2].nome);
		getch();
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
	leValidaInt("Insira o Ano de Fabricacao: ",topo,">>>ERRO: Ano Invalido",MIN_ANO,MAX_ANO,&veic[*qtdeVeiculos].ano);
	*qtdeVeiculos = *qtdeVeiculos = 1;
}
