#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include "structs.c"
#include "defines.c"
//Prototipos________________________________________________________________________________________________
void apresentaCadastros(int qtdeCadastros,int qtdeVeiculos,int qtdeManutencoes,Proprietario *prop2,Veiculo *veic,Manutencao *manu,char *topo);
int pesquisaProprietario(int qtdeCadastros,int qtdeVeiculos,int qtdeManutencoes,Proprietario *prop,Veiculo *veic,Manutencao *manu,char *topo);
int pesquisaVeiculo(int qtdeCadastros,int qtdeVeiculos,int qtdeManutencoes,Proprietario *prop,Veiculo *veic,Manutencao *manu,char *topo);
int pesquisaNome(int qtdeCadastros,int qtdeVeiculos,int qtdeManutencoes,Proprietario *prop,Veiculo *veic,Manutencao *manu,char *topo);
//Funcoes_____________________________________________________________________________________________________

//Objetivo: Apresentar todos os cadastros 
//Parametros: referencias a qtde de Proprietarios , veiculos e manutenções ,  referencias as strcuts Proprietario , Veiculo e Manutencao e ao topo 
//Retorno: Nenhum;
void apresentaCadastros(int qtdeCadastros,int qtdeVeiculos,int qtdeManutencoes,Proprietario *prop,Veiculo *veic,Manutencao *manu,char *topo){
	//variaveis
	int contador,coluna=3,linha=6,aux=1,opMenu,cont;
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
					coluna=42;
					linha=6;
				}
				
				gotoxy(coluna,linha);
				printf(">Nome: %s",prop[contador].nome);
				gotoxy(coluna,linha+1);
				printf(">CPF: %s",prop[contador].cpf);
				gotoxy(coluna,linha+2);
				printf(">Descricao:%s",prop[contador].descricao);
				gotoxy(coluna,linha+3);
				printf(">Cidade: %s",prop[contador].cidade);
				gotoxy(coluna,linha+4);
				printf(">Estado: %s",prop[contador].estado);
				gotoxy(coluna,linha+5);
				printf(">Telefone: %s",prop[contador].telefone);
				gotoxy(coluna,linha+6);
				if(prop[contador].servRealizado == 1){
					printf(">Servico ja realizado: Sim");
				}else{
					printf(">Servico ja realizado: Nao");
				}
				
				linha=linha+8;
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
				printf(">Ano : %i",veic[contador].ano);
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
			for(contador=0;contador<qtdeManutencoes;contador++)
			{
				if(aux==1)
				{
					menuOpcoes(0,"","Cadastros");
					gotoxy(3,5);
				}
				if(aux==3)
				{
					coluna=20;
					linha=6;
				}
				gotoxy(coluna,linha);
				printf(">Placa do Veiculo : %s",manu[contador].idVeiculo);
				gotoxy(coluna,linha+1);
				printf(">CPF do Proprietario: %s",manu[contador].idProprietario);
				gotoxy(coluna,linha+2);
				printf(">Descricao: %s",manu[contador].descricao);
				gotoxy(coluna,linha+3);
				printf(">Valor das Pecas: R$%.2f",manu[contador].valorPecas);
				gotoxy(coluna,linha+4);
				printf(">Valor da Mao de obra : R$%.2f",manu[contador].maodeObra);
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
//Parametros: referencias a qtde de Proprietarios , veiculos e manutenções ,  referencias as strcuts Proprietario , Veiculo e Manutencao e ao topo 
//Retorno: 0 para abortado e 1 para sucesso 
int pesquisaProprietario(int qtdeCadastros,int qtdeVeiculos,int qtdeManutencoes,Proprietario *prop,Veiculo *veic,Manutencao *manu,char *topo)
{
	//Variaveis
	char pesquisaCpf[TAM_CPF+1];		
	int flag,flag1,flag2,cont=0,coluna=3,linha=6,aux=1,cont2;
	
	//Desenvolvimento
	do{
		if(cont == 0){
			flag1=0;
			flag2=1;
			flag = leValidaString(pesquisaCpf,"Insira o CPF: ",topo,TAM_CPF,TAM_CPF,TIPO_INTEIRO,NAO);
			if(flag == 1){
				cont++;
			}else{
				printf("\n >>>Operacao abortada...");
				getch();
				return 0;	//leitura abortada
			}
			if(validaCPF(pesquisaCpf)==0){
				flag1=1;
				gotoxy(2,POS_Y_TOPO+3);
				printf(">>>ERRO: CPF INVALIDO....");
				getch();
			}									
			for(cont2=0;cont2<qtdeCadastros;cont2++)  //Verifica se o CPF esta Cadastrado
			{
				if(strcmp(prop[cont2].cpf,pesquisaCpf)==0)
				{
					flag2=0;
				}
			}
			if(flag2==1)
			{
				gotoxy(2,POS_Y_TOPO+3);
				printf(">>>ERRO: CPF Nao Cadastrado....");
				getch();
				return 0;
			}

	}
	}while(flag == 0 || flag1==1 || flag2==1);
	
	for(cont=0;cont<qtdeVeiculos;cont++)   //Verifica se o CPF fez manutenção
	{
		if(strcmp(veic[cont].idProprietario,pesquisaCpf)==0)
		{
			if(prop[cont].servRealizado==1)
			{
				flag=1;
				
			}
			if(flag==1)
			{											
				if(aux==1)
				{
					menuOpcoes(0,"","Veiculos que Sofreram Manutencao");
					gotoxy(3,5);
					getch();
				}
				if(aux==3)
				{
					coluna=20;
					linha=6;
				}
				gotoxy(coluna,linha);
				printf(">Placa do Veiculo : %s",manu[cont].idVeiculo);
				gotoxy(coluna,linha+1);
				printf(">Descricao: %s",manu[cont].descricao);
				gotoxy(coluna,linha+2);
				printf(">Valor das Pecas: R$%.2f",manu[cont].valorPecas);
				gotoxy(coluna,linha+3);
				printf(">Valor da Mao de obra :R$%.2f",manu[cont].maodeObra);
				linha=linha+5;
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
	getch();
	if(flag == 0)
	{
		gotoxy(3,5);
		printf(">>>Erro :Cliente  não fez nenhuma Manutencao");
		getch();
	}
}

//Objetivo: Apresentar todos os veiculos de um proprietario que ja tenha feito manutencao
//Parametros: referencias a qtde de Proprietarios , veiculos e manutenções ,  referencias as strcuts Proprietario , Veiculo e Manutencao e ao topo 
//Retorno: 0 para abortado e 1 para sucesso 
int pesquisaVeiculo(int qtdeCadastros,int qtdeVeiculos,int qtdeManutencoes,Proprietario *prop,Veiculo *veic,Manutencao *manu,char *topo)
{
	//Variaveis
	int flag,flag1,flag2=1,flag3=0,cont=0,cont2,cont3,cont4,aux=1,coluna=3,linha=6,flagAux[100],flagAux2[100],qtdeEncontrada=0,qtdePropEncontrados=0;
	char pesquisaPlaca[TAM_PLACA+1],pesquisaCpf[TAM_CPF+1];
	
	//Desenvolvimento
	do{
		/*
		if(qtdeVeiculos==0 && qtdeCadastros==0)
		{
			gotoxy(3,12);
			printf(">>>Erro : Nao existem Carros e Proprietarios Cadastrados");
			getch();
			return 0;	
		}
		if(qtdeVeiculos==0)
		{
			gotoxy(3,12);
			printf(">>>Erro : Nao existem Carros Cadastrados");
			getch();
			return 0;	
		}
		if(qtdeCadastros==0)
		{
			gotoxy(3.12);
			printf(">>>Erro :Nao existem Proprietarios Cadastrados");
			getch();
			return 0;
		}
		*/
		flag=1;
		flag1=0;
		if(cont == 0){
			flag = leituraPlaca(pesquisaPlaca,topo,qtdeVeiculos);
			if(flag == 1){
				cont++;
			}else{
				printf("\n >>>Operacao abortada...");
				getch();
				return 0;	//leitura abortada
			}
		}
		if( cont == 1)
		{
			for(cont2=0;cont2<qtdeManutencoes;cont2++)
			{
				if(strcmp(manu[cont2].idVeiculo,pesquisaPlaca)==0) // Verificar se existe placa
				{
					flagAux[cont2]=cont2;    //posições entronctradas
					flag1=1;   //Existe
					qtdeEncontrada++;
						
				}		
			}
			for(cont3=0;cont3<qtdeEncontrada;cont3++)
			{							
				for(cont2=0;cont2<qtdeCadastros;cont2++)
				{							
					if(strcmp(prop[cont2].cpf,manu[cont2].idProprietario)==0)
					{
						qtdePropEncontrados++;
						flagAux2[cont2]=cont2;
	//					for(cont3=0;cont3<qtdePropEncontrados;cont3++)
	//					{					
	//					if(strcmp(prop[cont2].cpf,prop[flagAux2[cont3]].cpf)==0)
	//						{	
	//						qtdePropEncontrados=qtdePropEncontrados-1;
	//						}
	//					}			
					}
				}				
			}
		for(cont2=0;cont2<qtdePropEncontrados;cont2++)
		{			
				
					menuOpcoes(0,"","Proprietario");
					gotoxy(3,5);
					getch();
					gotoxy(coluna,linha);
					printf(">Nome: %s",prop[flagAux2[cont2]].nome);
					gotoxy(coluna,linha+1);	
					printf(">CPF: %s",prop[flagAux2[cont2]].cpf);
					gotoxy(coluna,linha+2);
					printf(">Descricao: %s",prop[flagAux2[cont2]].descricao);
					gotoxy(coluna,linha+3);
					printf(">Cidade: %s",prop[flagAux2[cont2]].cidade);
					gotoxy(coluna,linha+4);
					printf(">Telefone: %s",prop[flagAux2[cont2]].telefone);
					getch();	
										
				for(cont3=0;cont3<qtdeManutencoes;cont3++)
				{						
					if(strcmp(manu[cont3].idProprietario,prop[flagAux2[cont2]].cpf)==0)
					{				
					menuOpcoes(0,"","Veiculos que Sofreram Manutencao");
					gotoxy(3,5);
					gotoxy(coluna,linha);
					printf(">Placa do Veiculo : %s",manu[cont3].idVeiculo);
					gotoxy(coluna,linha+1);
					printf(">Descricao: %s",manu[cont3].descricao);
					gotoxy(coluna,linha+2);
					printf(">Valor das Pecas: %.2f",manu[cont3].valorPecas);
					gotoxy(coluna,linha+3);
					printf(">Valor da Mao de obra : %.2f",manu[cont3].maodeObra);
	//				linha=linha+5;
					getch();
				}
			}
		}								
		}
	}while(flag == 0);
	if(flag1 == 0)
	{
		gotoxy(3,5);
		printf(">>>Erro :Nao existem Manutencoes nesse carro");
		getch();
	}
}
/*
//Objetivo: Apresentar todos os veiculos de um proprietario que ja tenha feito manutencao
//Parametros: referencias a qtde de Proprietarios , veiculos e manutenções ,  referencias as strcuts Proprietario , Veiculo e Manutencao e ao topo 
//Retorno: 0 para abortado e 1 para sucesso 
int pesquisaVeiculo(int qtdeCadastros,int qtdeVeiculos,int qtdeManutencoes,Proprietario *prop,Veiculo *veic,Manutencao *manu,char *topo)
{
	//Variaveis
	int flag,flag1,flag2=1,flag3=0,cont=0,cont2,cont3,cont4,aux=1,coluna=3,linha=6,flagAux[100],qtdeEncontrada=0;
	char pesquisaPlaca[TAM_PLACA+1],pesquisaCpf[TAM_CPF+1];
	
	//Desenvolvimento
	do{
		
		if(qtdeVeiculos==0 && qtdeCadastros==0)
		{
			gotoxy(3,12);
			printf(">>>Erro : Nao existem Carros e Proprietarios Cadastrados");
			getch();
			return 0;	
		}
		if(qtdeVeiculos==0)
		{
			gotoxy(3,12);
			printf(">>>Erro : Nao existem Carros Cadastrados");
			getch();
			return 0;	
		}
		if(qtdeCadastros==0)
		{
			gotoxy(3.12);
			printf(">>>Erro :Nao existem Proprietarios Cadastrados");
			getch();
			return 0;
		}
		
		flag=1;
		flag1=0;
		if(cont == 0){
			flag = leituraPlaca(pesquisaPlaca,topo,qtdeVeiculos);
			if(flag == 1){
				cont++;
			}else{
				printf("\n >>>Operacao abortada...");
				getch();
				return 0;	//leitura abortada
			}
		}
		if( cont == 1)
		{
			for(cont2=0;cont2<qtdeManutencoes;cont2++)
			{
				if(strcmp(manu[cont2].idVeiculo,pesquisaPlaca)==0) // Verificar se existe placa
				{
				
					flag1=1;   //Existe
					for(cont3=0;cont3<qtdeCadastros;cont3++)
					{
						if(strcmp(prop[cont3].cpf,manu[cont2].idProprietario)==0)
						{
							flagAux[cont2]=cont2;
								if(strcmp(prop[cont3].cpf,)==0)										
								menuOpcoes(0,"","Proprietario");
								gotoxy(3,5);
								getch();
								gotoxy(coluna,linha);
								printf(">Nome: %s",prop[cont3].nome);
								gotoxy(coluna,linha+1);
								printf(">CPF: %s",prop[cont3].cpf);
								gotoxy(coluna,linha+2);
								printf(">Descricao: %s",prop[cont3].descricao);
								gotoxy(coluna,linha+3);
								printf(">Cidade: %s",prop[cont3].cidade);
								gotoxy(coluna,linha+4);
								printf(">Telefone: %s",prop[cont3].telefone);
								getch();			
	//						prop[cont3].apresentado=1;
						
							for(cont4=0;cont4<qtdeManutencoes;cont4++)
							{
								if(strcmp(manu[cont4].idProprietario,prop[cont3].cpf)==0)
								{
									menuOpcoes(0,"","Veiculos que Sofreram Manutencao");
									gotoxy(3,5);
									gotoxy(coluna,linha);
									printf(">Placa do Veiculo : %s",manu[cont4].idVeiculo);
									gotoxy(coluna,linha+1);
									printf(">Descricao: %s",manu[cont4].descricao);
									gotoxy(coluna,linha+2);
									printf(">Valor das Pecas: %.2f",manu[cont4].valorPecas);
									gotoxy(coluna,linha+3);
									printf(">Valor da Mao de obra : %.2f",manu[cont4].maodeObra);
			//						linha=linha+5;
									getch();
								}
							}			
						}
					}		
				}
			}																	
		}
	}while(flag == 0);
	if(flag1 == 0)
	{
		gotoxy(3,5);
		printf(">>>Erro :Nao existem Manutencoes nesse carro");
		getch();
	}
}
*/
//Objetivo: Pesquisa dos dados de todos dos proprietários cadastrados pelo nome
//Parametros: referencias a qtde de Proprietarios , veiculos e manutenções ,  referencias as strcuts Proprietario , Veiculo e Manutencao e ao topo 
//Retorno: 0 para abortado e 1 para sucesso 
int pesquisaNome(int qtdeCadastros,int qtdeVeiculos,int qtdeManutencoes,Proprietario *prop,Veiculo *veic,Manutencao *manu,char *topo)
{
	int flag,qtdeEncontrada=0,cont=0,cont2,aux=1,coluna=3,linha=6;
	char pesquisaNome[TAM_NOME+1],copiaNome [qtdeCadastros][NOME_OPCOES];
	do{
		
		if(cont == 0){
			 flag = leValidaString(pesquisaNome,"Insira o nome para Pesquisa : ",topo,MIN_NOME,TAM_NOME,TIPO_LETRAS,SIM);
			 if(flag == 1){
			 	cont++;
			 }else{
			 	printf("\n>>>abortado....");
			 	getch();
			 	return 0;	//leitura de dados abortada
			 }			 
		}
		if(cont ==1)
		{						
			//Pesquisa por nome/verificando dados
			for(cont2=0;cont2<qtdeCadastros+1;cont2++)
			{  
				if(strstr(prop[cont2].nome,pesquisaNome))
				{
					qtdeEncontrada++;
		//			strcpy(copiaNome[qtdeEncontrada],prop[cont].nome);
					if(aux==1)
					{
						menuOpcoes(0,"","Proprietarios Encontrados ");
						gotoxy(3,5);
					}
					if(aux==3)
					{
					coluna=20;
					linha=6;
					}
					gotoxy(coluna,linha);
					printf(">Nome: %s",prop[cont2].nome);
					gotoxy(coluna,linha+1);
					printf(">CPF: %s",prop[cont2].cpf);
					gotoxy(coluna,linha+2);
					printf(">Descricao: %s",prop[cont2].descricao);
					gotoxy(coluna,linha+3);
					printf(">Cidade: %s",prop[cont2].cidade);
					gotoxy(coluna,linha+4);
					printf(">Telefone: %s",prop[cont2].telefone);
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
			if(qtdeEncontrada==0) 
			{			
				gotoxy(3,6);
				printf(">>>Erro: Nome não Encontrado...");
				getch();
			}
		}						
	}while(flag == 0);
	
	
	
}

