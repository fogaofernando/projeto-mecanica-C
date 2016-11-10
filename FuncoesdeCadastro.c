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
//					if(verificaStringRepetida(qtdeCadastros,prop,">>>ERRO: CPF Repetido")==0)
//					{
///					}	
				}while(flag==1);
				*/
				
				
				leValidaString("Insira a Descrição do Endereco: ",topo,prop[*qtdeCadastros].descricao, MIN_DESCRICAO,MAX_DESCRICAO,">>>ERRO: Endereco Invalido...");
				leValidaString("Insira o Estado : ",topo,prop[*qtdeCadastros].estado, MIN_ESTADO,MAX_ESTADO,">>>ERRO: Endereco Invalido...");
				leValidaString("Insira a Cidade: ",topo,prop[*qtdeCadastros].cidade, MIN_CIDADE,MAX_CIDADE,">>>ERRO: Endereco Invalido...");
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
	char menuAlterar[3][NOME_OPCOES],nomePesquisa[MAX_NOME],copiaNome [qtdeCadastros][NOME_OPCOES],novoNome[MAX_NOME],menuEndereco[3][NOME_OPCOES];
	
	//Desenvolvimento
	
	strcpy(menuAlterar[0],"1-Nome");
	strcpy(menuAlterar[1],"2-Endereco");
	strcpy(menuAlterar[2],"3-Telefone");
	strcpy(menuEndereco[0],"1-Descricao");
	strcpy(menuEndereco[1],"2-Estado");
	strcpy(menuEndereco[2],"3-Cidade");
	

	system("pause");
	
	//Opcao de pesquisa
	opMenu = menuOpcoes(3,menuAlterar,"Alterar");

	if(opMenu==1){
		//ALTERA NOME
		leValidaString("Informe o Nome para Pesquisa : ",topo,nomePesquisa,MIN_NOME,MAX_NOME,">>>ERRO: Insira um nome valido...");
		for(contador=0;contador<qtdeCadastros+1;contador++)
		{
			if(strstr(prop[contador].nome,nomePesquisa))
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

					leValidaString("Informe o novo nome : ",topo,novoNome,MIN_NOME,MAX_NOME,">>>ERRO: Insira um nome valido..."); // Novo nome para a opcao escolhida

					for(contador2=0;contador2<qtdeCadastros;contador2++)
					{
						if(strcmp(copiaNome[opMenu],prop[contador2].nome)==0)
						{
								strcpy(prop[contador2].nome,novoNome);  
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
	}else if(opMenu == 2)
	//ALTERA ENDERECO
	{
		opMenu == menuOpcoes(3,menuEndereco,"Alterar");
		if(opMenu==1) // ALTERA DESCRICAO
		{
			leValidaString("Informe a Descricao para Pesquisa : ",topo,nomePesquisa,MIN_DESCRICAO,MAX_DESCRICAO,">>>ERRO: Insira uma descricao valido...");
			for(contador=0;contador<qtdeCadastros+1;contador++)
			{
				if(strstr(prop[contador].descricao,nomePesquisa))
				{
					strcpy(copiaNome[qtdeEncontrada+1],prop[contador].descricao);
					qtdeEncontrada++;
				}
			}
			if(qtdeEncontrada==0) 
			{			
				printf(">>>Erro: Descricao não Encontrado...");
				getch();
			}		
			else
			{
				opMenu = menuOpcoes(qtdeEncontrada,copiaNome+1,"Descricoes encontrados");  //Menu de Nomes Encontrados
				for(contador=1;contador<qtdeEncontrada+1;contador++)
				{
					if(opMenu==contador)
					{
						leValidaString("Informe a nova Descricao : ",topo,novoNome,MIN_DESCRICAO,MAX_DESCRICAO,">>>ERRO: Insira um descricao valido..."); // Novo nome para a opcao escolhida
						for(contador2=0;contador2<qtdeCadastros;contador2++)
						{
							if(strcmp(copiaNome[opMenu],prop[contador2].descricao)==0)
							{
								strcpy(prop[contador2].descricao,novoNome);  
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
				//TESTE 
				for(contador=0;contador<qtdeCadastros;contador++)
				{
					printf("NOME %s \n",prop[contador].descricao);
				}
			}
			getch();
		}else if(opMenu == 2) //ALTERA ESTADO
		{
			leValidaString("Informe o Estado para Pesquisa : ",topo,nomePesquisa,MIN_ESTADO,MAX_ESTADO,">>>ERRO: Insira uma estado valido...");
			for(contador=0;contador<qtdeCadastros+1;contador++)
			{
				if(strstr(prop[contador].estado,nomePesquisa))
				{
					strcpy(copiaNome[qtdeEncontrada+1],prop[contador].estado);
					qtdeEncontrada++;
				}
			}
			if(qtdeEncontrada==0) 
			{			
				printf(">>>Erro: Estado não Encontrado...");
				getch();
			}		
			else
			{
				opMenu = menuOpcoes(qtdeEncontrada,copiaNome+1,"Estados encontrados");  //Menu de Nomes Encontrados
				for(contador=1;contador<qtdeEncontrada+1;contador++)
				{
					if(opMenu==contador)
					{
						leValidaString("Informe o novo Estado : ",topo,novoNome,MIN_ESTADO,MAX_ESTADO,">>>ERRO: Insira um estado valido..."); // Novo nome para a opcao escolhida
						for(contador2=0;contador2<qtdeCadastros;contador2++)
						{
							if(strcmp(copiaNome[opMenu],prop[contador2].estado)==0)
							{
								strcpy(prop[contador2].estado,novoNome);  
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
				//TESTE 
				for(contador=0;contador<qtdeCadastros;contador++)
				{
					printf("NOME %s \n",prop[contador].estado);
				}
			}
			getch();
		}else if(opMenu == 3)
		{
			
		}		
	}else if(opMenu == 3)
	//ALTERA TELEFONE
	{
		
	}
}
//Excluir Porprietario
//Entrada : referencia a quantidade de cadastros e a struct
//Retorno : NULO
void excluiProprietario(int qtdeCadastros,Proprietario *prop,char *topo)
{
	
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
