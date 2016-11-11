#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include "structs.c"
#include "defines.c"

//Prototipos________________________________________________________________________________________________

//Proprietario
void alteraVeiculo(int qtdeVeiculos,Veiculo *veic,char *topo);
void alteraProprietario(int qtdeCadastros,Proprietario *prop,char *topo);
void AlteraDado(int qtdeCadastros,char *titulo,char *titulo2,char *titulo3,char valor[qtdeCadastros][NOME_OPCOES],char *topo,char *msgErro,char *msgErro2,int MIN_TAM,int MAX_TAM);
//Altera um dado do Propeitario
//Entrada : referencia a quantidade de cadastros e a struct
//Retorno : NULO
void alteraProprietario(int qtdeCadastros,Proprietario *prop,char *topo)
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
	

	system("pause");
	
	//Opcao de pesquisa
	opMenu = menuOpcoes(3,menuAlterar,"Alterar");

	if(opMenu==1){
		//ALTERA NOME
		leValidaString(pesquisaNome,"Informe o Nome para Pesquisa: ",topo,MIN_NOME,MAX_NOME,TIPO_LETRAS,SIM);
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
			printf(">>>Erro: Nome n�o Encontrado...");
			getch();
		}		
		else
		{
			opMenu = menuOpcoes(qtdeEncontrada,copiaNome+1,"Nomes encontrados");  //Menu de Nomes Encontrados
			for(contador=1;contador<qtdeEncontrada+1;contador++)
			{
				if(opMenu==contador)
				{
					leValidaString(novoNome,"Informe o novo nome: ",topo,MIN_NOME,MAX_NOME,TIPO_LETRAS,SIM); // Novo nome para a opcao escolhida
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
			leValidaString(pesquisaDescricao,"Informe a Descricao para Pesquisa: ",topo,MIN_DESCRICAO,MAX_DESCRICAO,TIPO_LETRAS_ESPECIAIS_NUMEROS,SIM);
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
				printf(">>>Erro: Descricao n�o Encontrado...");
				getch();
			}		
			else
			{
				opMenu = menuOpcoes(qtdeEncontrada,copiaDescricao+1,"Descricoes encontrados");  //Menu de Nomes Encontrados
				for(contador=1;contador<qtdeEncontrada+1;contador++)
				{
					if(opMenu==contador)
					{
						leValidaString(novaDescricao,"Informe a nova Descricao: ",topo,MIN_DESCRICAO,MAX_DESCRICAO,TIPO_LETRAS_ESPECIAIS_NUMEROS,SIM); // Novo nome para a opcao escolhida
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
			leValidaString(pesquisaEstado,"Informe o Estado para Pesquisa: ",topo,MIN_ESTADO,MAX_ESTADO,TIPO_LETRAS,SIM);
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
				printf(">>>Erro: Estado n�o Encontrado...");
				getch();
			}		
			else
			{
				opMenu = menuOpcoes(qtdeEncontrada,copiaEstado+1,"Estados encontrados");  //Menu de Nomes Encontrados
				for(contador=1;contador<qtdeEncontrada+1;contador++)
				{
					if(opMenu==contador)
					{
						leValidaString(novoEstado,"Informe o novo Estado : ",topo,MIN_ESTADO,MAX_ESTADO,TIPO_LETRAS,SIM); // Novo nome para a opcao escolhida
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
			leValidaString(pesquisaCidade,"Informe a Cidade para Pesquisa: ",topo,MIN_CIDADE,MAX_CIDADE,TIPO_LETRAS,SIM);
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
				printf(">>>Erro: Cidade n�o Encontrada...");
				getch();
			}		
			else
			{
				opMenu = menuOpcoes(qtdeEncontrada,copiaCidade+1,"Cidades encontrados");  //Menu de Nomes Encontrados
				for(contador=1;contador<qtdeEncontrada+1;contador++)
				{
					if(opMenu==contador)
					{
						leValidaString(novaCidade,"Informe a nova Cidade : ",topo,MIN_CIDADE,MAX_CIDADE,TIPO_LETRAS,SIM); // Novo nome para a opcao escolhida
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
			leValidaString(pesquisaTelefone,"Informe o Telefone para Pesquisa: ",topo,MIN_TELEFONE,MAX_TELEFONE,TIPO_INTEIRO,NAO);
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
				printf(">>>Erro: Telefone n�o Encontrado...");
				getch();
			}		
			else
			{
				opMenu = menuOpcoes(qtdeEncontrada,copiaTelefone+1,"Telefones encontrados");  //Menu de Nomes Encontrados
				for(contador=1;contador<qtdeEncontrada+1;contador++)
				{
					if(opMenu==contador)
					{
						leValidaString(novoTelefone,"Informe a novo Telefone : ",topo,MIN_TELEFONE,MAX_TELEFONE,TIPO_INTEIRO,NAO); // Novo nome para a opcao escolhida
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
//Altera um dado do Veiculo
//Entrada : referencia a quantidade de cadastros e a struct
//Retorno : NULO
void alteraVeiculo(int qtdeCadastros,Veiculo *veic,char *topo)
{
	//variaveis
	
	int opMenu,contador,contador2=0,qtdeEncontrada=0,qtdeLetras,cont;  //AUXILIARES   /*qtdeEncontrado = qtde de nomes encontrados pela pesquisa */
	char menuAlterar[3][NOME_OPCOES],menuEndereco[3][NOME_OPCOES];  // Menu 
	char copiaPlaca [qtdeCadastros][NOME_OPCOES],novaPlaca[TAM_PLACA],pesquisaPlaca[TAM_PLACA]; // ALTERA NOME
	char copiaDescricao [qtdeCadastros][NOME_OPCOES],novaDescricao[MAX_NOME],pesquisaDescricao[MAX_DESCRICAO]; // ALTERA DESCRICAO
	char copiaEstado [qtdeCadastros][NOME_OPCOES],novoEstado[MAX_ESTADO],pesquisaEstado[MAX_ESTADO]; // ALTERA ESTADO
	char copiaCidade [qtdeCadastros][NOME_OPCOES],novaCidade[MAX_CIDADE],pesquisaCidade[MAX_CIDADE];
	char copiaTelefone [qtdeCadastros][NOME_OPCOES],novoTelefone[MAX_TELEFONE],pesquisaTelefone[MAX_TELEFONE]; // ALTERA CIDADE
	
	//Desenvolvimento
	
	strcpy(menuAlterar[0],"1-Placa");
	strcpy(menuAlterar[1],"2-Endereco");
	strcpy(menuAlterar[2],"3-Telefone");
	strcpy(menuEndereco[0],"1-Descricao");
	strcpy(menuEndereco[1],"2-Estado");
	strcpy(menuEndereco[2],"3-Cidade");
	

	system("pause");
	
	//Opcao de pesquisa
	opMenu = menuOpcoes(3,menuAlterar,"Alterar");

	if(opMenu==1){
		// AlteraDado(qtdeCadastros,"Informe a Placa para Pesquisa : ","Placas encontradas","Informe a nova placa : ",veic->placa,"Alterar",">>>Erro: Placa n�o Encontrada...",">>>ERRO: Insira uma placa valida...",TAM_PLACA,TAM_PLACA);
		/*
			leValidaString("Informe a Placa para Pesquisa : ",topo,pesquisaPlaca,MIN_PLACA,TAM_PLACA,">>>ERRO: Insira uma placa valida...");
		for(contador=0;contador<qtdeCadastros+1;contador++)
		{
			if(strstr(veic[contador].placa,pesquisaPlaca))
			{
				strcpy(copiaPlaca[qtdeEncontrada+1],veic[contador].placa);
				qtdeEncontrada++;
			}
		}
		if(qtdeEncontrada==0) 
		{			
			printf(">>>Erro: Placa n�o Encontrada...");
			getch();
		}		
		else
		{
			opMenu = menuOpcoes(qtdeEncontrada,copiaPlaca+1,);  //Menu de Nomes Encontrados
			for(contador=1;contador<qtdeEncontrada+1;contador++)
			{
				if(opMenu==contador)
				{
					leValidaString("Informe a nova placa : ",topo,novaPlaca,TAM_PLACA,TAM_PLACA,">>>ERRO: Insira uma placa valida..."); // Novo placa para a opcao escolhida
					for(contador2=0;contador2<qtdeCadastros;contador2++)
					{
						if(strcmp(copiaPlaca[opMenu],veic[contador2].placa)==0)
						{
							strcpy(veic[contador2].placa,novaPlaca);  
						}
					}
					/*				
				}else{
					printf("erro");
					getch();
				}
				
				}
			}
			for(contador=0;contador<qtdeCadastros;contador++)
			{
				printf("PLACAS %s \n",veic[contador].placa);
			}
		}
		getch();
	*/}
}





/*
void AlteraDado(int qtdeCadastros,char *titulo,char *titulo2,char *titulo3,char valor[qtdeCadastros][NOME_OPCOES],char *topo,char *msgErro,char *msgErro2,int MIN_TAM,int MAX_TAM)
{
		int opMenu,contador,contador2=0,qtdeEncontrada=0,qtdeLetras,cont;  //AUXILIARES   /*qtdeEncontrado = qtde de nomes encontrados pela pesquisa */
		//ALTERA PLACA
	/*	char copiaPlaca [qtdeCadastros][NOME_OPCOES],novaPlaca[MIN_TAM],pesquisaPlaca[MAX_TAM]; 
		
		
		leValidaString(pesquisaPlaca,titulo,topo,MIN_TAM,MAX_TAM,TIPO_LETRAS_NUMEROS,NAO);
		for(contador=0;contador<qtdeCadastros+1;contador++)
		{
			if(strstr(veic[contador].placa,pesquisaPlaca))
			{
				strcpy(copiaPlaca[qtdeEncontrada+1],valor[contador]);
				qtdeEncontrada++;
			}
		}
		if(qtdeEncontrada==0) 
		{			
			printf(msgErro);
			getch();
		}	
		/*
		else
		{
			opMenu = menuOpcoes(qtdeEncontrada,copiaPlaca+1,titulo3);  //Menu de Nomes Encontrados
			for(contador=1;contador<qtdeEncontrada+1;contador++)
			{
				if(opMenu==contador)
				{
					leValidaString(titulo2,topo,novaPlaca,MIN_TAM,MAX_TAM,msgErro2); // Novo placa para a opcao escolhida
					for(contador2=0;contador2<qtdeCadastros;contador2++)
					{
						if(strcmp(copiaPlaca[opMenu],veic[contador2].placa)==0)
						{
							strcpy(veic[contador2].placa,novaPlaca);  
						}
					}
					/*				
				}else{
					printf("erro");
					getch();
				}
				
				}
			}
			
			for(contador=0;contador<qtdeCadastros;contador++)
			{
				printf("PLACAS %s \n",veic[contador].placa);
			}
	//	}
		getch();
}*/
