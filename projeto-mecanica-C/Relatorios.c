#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include "structs.c"
#include "defines.c"
//Prototipos________________________________________________________________________________________________
void apresentaCadastros(int qtdeCadastros,int qtdeVeiculos,int qtdeManutencoes,Proprietario *prop,Veiculo *veic,Manutencao *manu,char *topo);
void pesquisaProprietario(int qtdeCadastros,int qtdeVeiculos,int qtdeManutencoes,Proprietario *prop,Veiculo *veic,Manutencao *manu,char *topo);

//Funcoes_____________________________________________________________________________________________________

//Objetivo: Apresentar todos os cadastros 
//Parametros: referencias as structs prop
//Retorno: Nenhum;
void apresentaCadastros(int qtdeCadastros,int qtdeVeiculos,int qtdeManutencoes,Proprietario *prop,Veiculo *veic,Manutencao *manu,char *topo)
{
	//variaveis

	int contador,coluna=3,linha=6,aux=1,opMenu;
	char menuCadastros[3][NOME_OPCOES];
		
	//Desenvolvimento

	strcpy(menuCadastros[0],"1-Proprietarios");
	strcpy(menuCadastros[1],"2-Veiculos");
	strcpy(menuCadastros[2],"3-Manutencoes");
	
	opMenu=menuOpcoes(3,menuCadastros,"Apresentar Cadastros");
	if(opMenu == 1) 
		//Apresenta Proprietarios
	{
		if(qtdeCadastros==0)
		{
			gotoxy(coluna,10);
			printf(">>>Erro: Nao existem Proprietarios Cadastros...");
		}
		else
		{		
			for(contador=0;contador<qtdeCadastros;contador++)
			{
				if(aux==1)
				{
					menuOpcoes(0,"","Cadastros");
					gotoxy(3,5);
				}
				if(aux==3)
				{
					coluna=30;
					linha=6;
				}
				gotoxy(coluna,linha);
				printf(">Nome: %s",prop[contador].nome);
				gotoxy(coluna,linha+1);
				printf(">CPF: %s",prop[contador].cpf);
				gotoxy(coluna,linha+2);
				printf(">Descricao: %s",prop[contador].descricao);
				gotoxy(coluna,linha+3);
				printf(">Cidade: %s",prop[contador].cidade);
				gotoxy(coluna,linha+4);
				printf(">Telefone: %s",prop[contador].telefone);
				linha=linha+6;
				aux++;
				if(aux==5){
					aux=1;
					coluna=3;
					linha=6;
					getch();
				}
			}
		}
		getch();
	}else if(opMenu == 2)
	//Apresenta Veiculos
	{
		if(qtdeVeiculos==0)
		{
			gotoxy(coluna,10);
			printf(">>>Erro: Nao existem Veiculos Cadastrados...");
		}
		else
		{		
			for(contador=0;contador<qtdeVeiculos;contador++)
			{
				if(aux==1)
				{
					menuOpcoes(0,"","Cadastros");
					gotoxy(3,5);
				}
				if(aux==3)
				{
					coluna=30;
					linha=6;
				}
				gotoxy(coluna,linha);
				printf(">Placa: %s",veic[contador].placa);
				gotoxy(coluna,linha+1);
				printf(">Modelo: %s",veic[contador].modelo);
				gotoxy(coluna,linha+2);
				printf(">Fabricante: %s",veic[contador].fabricante);
				gotoxy(coluna,linha+3);
				printf(">Chassi : %s",veic[contador].chassi);
				gotoxy(coluna,linha+4);
				printf(">Ano : %s",veic[contador].ano);
				linha=linha+6;
				aux++;
				if(aux==5){
					aux=1;
					coluna=3;
					linha=6;
					getch();
				}
			}
		}
		getch();
	}else if(opMenu == 3)
	// Apresenta Manutenções
	{
				if(qtdeManutencoes==0)
		{
			gotoxy(coluna,10);
			printf(">>>Erro: Nao existem Manutencoes Cadastradas...");
		}
		else
		{		
			for(contador=0;contador<qtdeVeiculos;contador++)
			{
				if(aux==1)
				{
					menuOpcoes(0,"","Cadastros");
					gotoxy(3,5);
				}
				if(aux==3)
				{
					coluna=30;
					linha=6;
				}
				gotoxy(coluna,linha);
				printf(">Placa do Veiculo : %s",manu[contador].idVeiculo);
				gotoxy(coluna,linha+1);
				printf(">CPF do Proprietario: %s",manu[contador].idPropietario);
				gotoxy(coluna,linha+2);
				printf(">Descricao: %s",manu[contador].descricao);
				gotoxy(coluna,linha+3);
				printf(">Valor das Pecas: %f",manu[contador].valorPecas);
				gotoxy(coluna,linha+4);
				printf(">Valor da Mao de obra : %f",manu[contador].maodeObra);
				linha=linha+6;
				aux++;
				if(aux==5){
					aux=1;
					coluna=3;
					linha=6;
					getch();
				}
			}
		}
		getch();
	}
}

//Objetivo: Apresentar todos os veiculos de um proprietario que ja tenha feito manutencao
//Parametros: referencias as structs prop
//Retorno: Nenhum;
void pesquisaProprietario(int qtdeCadastros,int qtdeVeiculos,int qtdeManutencoes,Proprietario *prop,Veiculo *veic,Manutencao *manu,char *topo)
{
	//variaveis
	char pesquisaCpf[TAM_CPF+1];		
	int flag,cont,coluna=3,linha=6,aux=1;
	
	//desenvolvimento
	do{
		flag=0;
		leValidaString(pesquisaCpf,"Insira o CPF: ",topo,TAM_CPF,TAM_CPF,TIPO_INTEIRO,NAO);
		if(validaCPF(pesquisaCpf)==0){
			flag=1;
			gotoxy(2,POS_Y_TOPO+3);
			printf(">>>ERRO: CPF INVALIDO....");
			getch();
		}									
	}while(flag==1);
	for(cont=0;cont<qtdeCadastros;cont++)
	{
		if(strcmp(veic[cont].idProprietario,pesquisaCpf)==0)
		{
			if(prop[cont].servRealizado==0)
			{
				printf(">>>Erro :Cliente  não fez nenhuma Manutencao");
			}
			else 
			{
				if(aux==1)
				{
					menuOpcoes(0,"","Veiculos que Sofreram Manutencao");
					gotoxy(3,5);
				}
				if(aux==3)
				{
					coluna=30;
					linha=6;
				}
				gotoxy(coluna,linha);
				printf(">Placa do Veiculo : %s",manu[cont].idVeiculo);
				gotoxy(coluna,linha+1);
				printf(">CPF do Proprietario: %s",manu[cont].idPropietario);
				gotoxy(coluna,linha+2);
				printf(">Descricao: %s",manu[cont].descricao);
				gotoxy(coluna,linha+3);
				printf(">Valor das Pecas: %f",manu[cont].valorPecas);
				gotoxy(coluna,linha+4);
				printf(">Valor da Mao de obra : %f",manu[cont].maodeObra);
				linha=linha+6;
				aux++;
				if(aux==5){
					aux=1;
					coluna=3;
					linha=6;
					getch();
				}
				
			}
		}
	}
}

