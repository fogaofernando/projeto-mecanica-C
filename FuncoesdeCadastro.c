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
	
//	leValidaString("Insira o nome: ",topo,prop[*qtdeCadastros].nome,MIN_NOME,MAX_NOME,">>>ERRO: Insira um nome valido...");

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
	leValidaString("Insira o Telefone: ",topo,prop[*qtdeCadastros].telefone, MIN_TELEFONE,MAX_TELEFONE,">>>ERRO: Telefone Invalido...");

	*qtdeCadastros=*qtdeCadastros+1;
}

//Altera um dado do Propeitario
//Entrada : referencia a quantidade de cadastros e a struct
//Retorno : NULO
void alteraProprietario(int qtdeCadastros,Proprietario *prop,char *topo)
{
	//variaveis
	
	int opMenu,contador,contador2=0,qtdeEncontrada=0,qtdeLetras,cont,aux[10];  //AUXILIARES   /*qtdeEncontrado = qtde de nomes encontrados pela pesquisa */
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
	

	system("pause");
	
	//Opcao de pesquisa
	opMenu = menuOpcoes(3,menuAlterar,"Alterar");

	if(opMenu==1){
		//ALTERA NOME
		leValidaString("Informe o Nome para Pesquisa : ",topo,pesquisaNome,MIN_NOME,MAX_NOME,">>>ERRO: Insira um nome valido...");
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
		opMenu = menuOpcoes(3,menuEndereco,"Alterar");
		if(opMenu==1) // ALTERA DESCRICAO
		{
			leValidaString("Informe a Descricao para Pesquisa : ",topo,pesquisaDescricao,MIN_DESCRICAO,MAX_DESCRICAO,">>>ERRO: Insira uma descricao valido...");
			for(contador=0;contador<qtdeCadastros+1;contador++)
			{
				if(strstr(prop[contador].descricao,pesquisaDescricao))
				{
					strcpy(copiaDescricao[qtdeEncontrada+1],prop[contador].descricao);
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
				opMenu = menuOpcoes(qtdeEncontrada,copiaDescricao+1,"Descricoes encontrados");  //Menu de Nomes Encontrados
				for(contador=1;contador<qtdeEncontrada+1;contador++)
				{
					if(opMenu==contador)
					{
						leValidaString("Informe a nova Descricao : ",topo,novaDescricao,MIN_DESCRICAO,MAX_DESCRICAO,">>>ERRO: Insira um descricao valido..."); // Novo nome para a opcao escolhida
						for(contador2=0;contador2<qtdeCadastros;contador2++)
						{
							if(strcmp(copiaDescricao[opMenu],prop[contador2].descricao)==0)
							{
								strcpy(prop[contador2].descricao,novaDescricao);  
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
					printf("Descricoes Cadastradas %s \n",prop[contador].descricao);
				}
			}
			getch();
		}else if(opMenu == 2) //ALTERA ESTADO
		{
			leValidaString("Informe o Estado para Pesquisa : ",topo,pesquisaEstado,MIN_ESTADO,MAX_ESTADO,">>>ERRO: Insira uma Estado valido...");
			for(contador=0;contador<qtdeCadastros+1;contador++)
			{
				if(strstr(prop[contador].estado,pesquisaEstado))
				{
					strcpy(copiaEstado[qtdeEncontrada+1],prop[contador].estado);
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
				opMenu = menuOpcoes(qtdeEncontrada,copiaEstado+1,"Estados encontrados");  //Menu de Nomes Encontrados
				for(contador=1;contador<qtdeEncontrada+1;contador++)
				{
					if(opMenu==contador)
					{
						leValidaString("Informe o novo Estado : ",topo,novoEstado,MIN_ESTADO,MAX_ESTADO,">>>ERRO: Insira um Estado valido..."); // Novo nome para a opcao escolhida
						for(contador2=0;contador2<qtdeCadastros;contador2++)
						{
							if(strcmp(copiaEstado[opMenu],prop[contador2].estado)==0)
							{
								strcpy(prop[contador2].estado,novoEstado);  
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
					printf("Estados %s \n",prop[contador].estado);
				}
			}
			getch();
		}else if(opMenu == 3) // ALTERA CIDADE
		{
			leValidaString("Informe a Cidade para Pesquisa : ",topo,pesquisaCidade,MIN_CIDADE,MAX_CIDADE,">>>ERRO: Insira uma cidade valida...");
			for(contador=0;contador<qtdeCadastros+1;contador++)
			{
				if(strstr(prop[contador].cidade,pesquisaCidade))
				{
					strcpy(copiaCidade[qtdeEncontrada+1],prop[contador].cidade);
					qtdeEncontrada++;
				}
			}
			if(qtdeEncontrada==0) 
			{			
				printf(">>>Erro: Cidade não Encontrada...");
				getch();
			}		
			else
			{
				opMenu = menuOpcoes(qtdeEncontrada,copiaCidade+1,"Cidades encontrados");  //Menu de Nomes Encontrados
				for(contador=1;contador<qtdeEncontrada+1;contador++)
				{
					if(opMenu==contador)
					{
						leValidaString("Informe a nova Cidade : ",topo,novaCidade,MIN_CIDADE,MAX_CIDADE,">>>ERRO: Insira uma Cidade valida..."); // Novo nome para a opcao escolhida
						for(contador2=0;contador2<qtdeCadastros;contador2++)
						{
							if(strcmp(copiaCidade[opMenu],prop[contador2].cidade)==0)
							{
								strcpy(prop[contador2].cidade,novaCidade);  
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
					printf("Cidades Cadastradas %s \n",prop[contador].cidade);
				}
			}
			getch();
		}		
	}else if(opMenu == 3) // ALTERA TELEFONE
	//ALTERA TELEFONE
	{
			leValidaString("Informe o Telefone para Pesquisa : ",topo,pesquisaTelefone,MIN_TELEFONE,MAX_TELEFONE,">>>ERRO: Insira um Telefone valido...");
			for(contador=0;contador<qtdeCadastros+1;contador++)
			{
				if(strstr(prop[contador].telefone,pesquisaTelefone))
				{
					strcpy(copiaTelefone[qtdeEncontrada+1],prop[contador].telefone);
					qtdeEncontrada++;
				}
			}
			if(qtdeEncontrada==0) 
			{			
				printf(">>>Erro: Telefone não Encontrado...");
				getch();
			}		
			else
			{
				opMenu = menuOpcoes(qtdeEncontrada,copiaTelefone+1,"Telefones encontrados");  //Menu de Nomes Encontrados
				for(contador=1;contador<qtdeEncontrada+1;contador++)
				{
					if(opMenu==contador)
					{
						leValidaString("Informe a novo Telefone : ",topo,novoTelefone,MIN_TELEFONE,MAX_TELEFONE,">>>ERRO: Insira um Telefone valido..."); // Novo nome para a opcao escolhida
						for(contador2=0;contador2<qtdeCadastros;contador2++)
						{
							if(strcmp(copiaTelefone[opMenu],prop[contador2].telefone)==0)
							{
								strcpy(prop[contador2].telefone,novoTelefone);  
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
					printf("Telefones Cadastrados %s \n",prop[contador].telefone);
				}
			}
			getch();
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
