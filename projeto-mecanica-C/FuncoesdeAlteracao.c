#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include "structs.c"
#include "defines.c"

//Prototipos________________________________________________________________________________________________

//Proprietario
int alteraVeiculo(int qtdeVeiculos,Veiculo *veic,char *topo);
int alteraProprietario(int qtdeCadastros,Proprietario *prop,char *topo);


//Altera um dado do Propeitario
//Entrada : referencia a quantidade de cadastros e a struct
//Retorno : NULO
int alteraProprietario(int qtdeCadastros,Proprietario *prop,char *topo)
{
	//variaveis
	
	int opMenu,contador,contador2=0,qtdeEncontrada=0,qtdeLetras,cont;  //AUXILIARES   /*qtdeEncontrado = qtde de nomes encontrados pela pesquisa */
	char menuAlterar[3][NOME_OPCOES],menuEndereco[3][NOME_OPCOES];  // Menu 
	char copiaNome [qtdeCadastros][NOME_OPCOES],novoNome[TAM_NOME],pesquisaNome[TAM_NOME]; // ALTERA NOME
	char copiaDescricao [qtdeCadastros][NOME_OPCOES],novaDescricao[TAM_NOME],pesquisaDescricao[TAM_DESCRICAO_END]; // ALTERA DESCRICAO
	char copiaEstado [qtdeCadastros][NOME_OPCOES],novoEstado[TAM_ESTADO],pesquisaEstado[TAM_ESTADO]; // ALTERA ESTADO
	char copiaCidade [qtdeCadastros][NOME_OPCOES],novaCidade[TAM_CIDADE],pesquisaCidade[TAM_CIDADE];
	char copiaTelefone [qtdeCadastros][NOME_OPCOES],novoTelefone[TAM_TELEFONE],pesquisaTelefone[TAM_TELEFONE]; // ALTERA CIDADE
	
	//Desenvolvimento
	
	strcpy(menuAlterar[0],"1-Nome");
	strcpy(menuAlterar[1],"2-Endereco");
	strcpy(menuAlterar[2],"3-Telefone");
	strcpy(menuEndereco[0],"1-Descricao");
	strcpy(menuEndereco[1],"2-Estado");
	strcpy(menuEndereco[2],"3-Cidade");
	

	
		if(qtdeCadastros == 0){
		printf(">>>Nenhuma Proprietario foi cadastrado...");
		getch();
		return 0;
	}	
	//Opcao de pesquisa
	
	opMenu = menuOpcoes(3,menuAlterar,"Alterar");

	if(opMenu==1){
		//ALTERA NOME
		if( leValidaString(pesquisaNome,"Informe o Nome para Pesquisa: ",topo,MIN_PESQUISA,TAM_NOME,TIPO_LETRAS,SIM) == 1 ){
			//Pesquisa por nome/verificando dados
			for(contador=0;contador<qtdeCadastros+1;contador++)
			{  
				if(strstr(prop[contador].nome,pesquisaNome))
				{
					qtdeEncontrada++;
					strcpy(copiaNome[qtdeEncontrada],prop[contador].nome);
				}
			}
			if(qtdeEncontrada==0) 
			{			
				printf(">>>Erro: Nome não Encontrado...");
				getch();
			}		
			else
			{
				printf("Nome Pesquisado : %s",pesquisaNome);
				opMenu = menuOpcoes(qtdeEncontrada,copiaNome+1,"Nome Pesquisado : %s");  //Menu de Nomes Encontrados
				for(contador=1;contador<qtdeEncontrada+1;contador++)
				{
					if(opMenu==contador)
					{
						// Novo nome para a opcao escolhida
						if( leValidaString(novoNome,"Informe o novo nome: ",topo,MIN_NOME,TAM_NOME,TIPO_LETRAS,SIM) == 1){
							for(contador2=0;contador2<qtdeCadastros;contador2++)
							{
								if(strcmp(copiaNome[opMenu],prop[contador2].nome)==0)
								{
									strcpy(prop[contador2].nome,novoNome);  
								}
							}
						}else{
							printf(">>>Abortado...");
							getch();
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
		}else{
			printf(">>>abortado...");
		}
		getch();
	}else if(opMenu == 2)
	
	//ALTERA ENDERECO
	{
		opMenu = menuOpcoes(3,menuEndereco,"Alterar");
		if(opMenu==1) // ALTERA DESCRICAO
		{
			//pesquisar por descricao
			if( leValidaString(pesquisaDescricao,"Informe a Descricao para Pesquisa: ",topo,MIN_PESQUISA,TAM_DESCRICAO_END,TIPO_LETRAS_ESPECIAIS_NUMEROS,SIM) ==1 ){
	
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
							
							//alteracao da descricao
							if(leValidaString(novaDescricao,"Informe a nova Descricao: ",topo,MIN_DESCRICAO_END,TAM_DESCRICAO_END,TIPO_LETRAS_ESPECIAIS_NUMEROS,SIM) == 1 ){
								for(contador2=0;contador2<qtdeCadastros;contador2++)
								{
									if(strcmp(copiaDescricao[opMenu],prop[contador2].descricao)==0)
									{						
										strcpy(prop[contador2].descricao,novaDescricao);  
									}
								}
							}else{
								printf("\n>>>Abortado...");
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
			}else{
				printf("\n>>>Abortado...");
			}
				getch();
			
		//ALTERA ESTADO
		}else if(opMenu == 2) 
		{
			if( leValidaString(pesquisaEstado,"Informe o Estado para Pesquisa: ",topo,MIN_ESTADO,TAM_ESTADO,TIPO_LETRAS,SIM) == 1){
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
							leValidaString(novoEstado,"Informe o novo Estado : ",topo,MIN_ESTADO,TAM_ESTADO,TIPO_LETRAS,SIM); // Novo nome para a opcao escolhida
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
			}else{
				printf("\n%c >>>Abortado...",BARRA_LATERAL);
			}
		// ALTERA CIDADE
		}else if(opMenu == 3)
		{
			//pesquisando por nome da cidade
			if(leValidaString(pesquisaCidade,"Informe a Cidade para Pesquisa: ",topo,MIN_PESQUISA,TAM_CIDADE,TIPO_LETRAS,SIM)==1){
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
					printf("\n%c >>>Erro: Cidade não Encontrada...",BARRA_LATERAL);
					getch();
				}		
				else
				{
					opMenu = menuOpcoes(qtdeEncontrada,copiaCidade+1,"Cidades encontrados");  //Menu de Nomes Encontrados
					for(contador=1;contador<qtdeEncontrada+1;contador++)
					{
						if(opMenu==contador)
						{	
							//Novo nome da cidade
							if( leValidaString(novaCidade,"Informe a nova Cidade : ",topo,MIN_CIDADE,TAM_CIDADE,TIPO_LETRAS,SIM) == 1){
								for(contador2=0;contador2<qtdeCadastros;contador2++)
								{
									if(strcmp(copiaCidade[opMenu],prop[contador2].cidade)==0)
									{
										strcpy(prop[contador2].cidade,novaCidade);  
									}
								}
							}else{
								printf("\n%c >>>Abortado...",BARRA_LATERAL);
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
			}else{
				printf("\n%c >>>Abortado...",BARRA_LATERAL);
			}
			getch();
		}		
	}else if(opMenu == 3) // ALTERA TELEFONE
	//ALTERA TELEFONE
	{
			if(leValidaString(pesquisaTelefone,"Informe o Telefone para Pesquisa: ",topo,MIN_PESQUISA,TAM_TELEFONE,TIPO_INTEIRO,NAO)==1){
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
					printf("\n%c>>>Erro: Telefone não Encontrado...",BARRA_LATERAL);
					getch();
				}		
				else
				{
					opMenu = menuOpcoes(qtdeEncontrada,copiaTelefone+1,"Telefones encontrados");  //Menu de Nomes Encontrados
					for(contador=1;contador<qtdeEncontrada+1;contador++)
					{
						if(opMenu==contador)
						{
							// Novo nome para a opcao escolhida
							if(leValidaString(novoTelefone,"Informe a novo Telefone : ",topo,MIN_PESQUISA,TAM_TELEFONE,TIPO_INTEIRO,NAO) == 1){
								for(contador2=0;contador2<qtdeCadastros;contador2++)
								{
									if(strcmp(copiaTelefone[opMenu],prop[contador2].telefone)==0)
									{
										strcpy(prop[contador2].telefone,novoTelefone);  
									}
								}
							}else{
								printf("\n%c >>>Abortado...",BARRA_LATERAL);
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
			}else{
				printf("\n%c >>>Abortado...",BARRA_LATERAL);
			}
			getch();
	}
}
//Altera um dado do Veiculo
//Entrada : referencia a quantidade de cadastros e a struct
//Retorno : NULO
int alteraVeiculo(int qtdeCadastros,Veiculo *veic,char *topo)
{
	//variaveis
	
	int opMenu,contador,contador2=0,qtdeEncontrada=0,qtdeLetras,cont;  //AUXILIARES   /*qtdeEncontrado = qtde de nomes encontrados pela pesquisa */
	char menuAlterar[5][NOME_OPCOES];  // Menu 
	char copiaPlaca [qtdeCadastros][NOME_OPCOES],novaPlaca[TAM_PLACA],pesquisaPlaca[TAM_PLACA]; // ALTERA Placa
	char copiaModelo [qtdeCadastros][NOME_OPCOES],novoModelo[TAM_MODELO],pesquisaModelo[TAM_MODELO]; // ALTERA Modelo
	char copiaFabricante [qtdeCadastros][NOME_OPCOES],novoFabricante[TAM_FABRICANTE],pesquisaFabricante[TAM_FABRICANTE]; // ALTERA Frabricante
	char copiaChassi [qtdeCadastros][NOME_OPCOES],novoChassi[TAM_CHASSI],pesquisaChassi[TAM_CHASSI];  // Altera Chassi
	char copiaAno [qtdeCadastros][NOME_OPCOES],novoAno[TAM_ANO],pesquisaAno[TAM_ANO]; // ALTERA Ano
	
	//Desenvolvimento
	
	strcpy(menuAlterar[0],"1-Placa");
	strcpy(menuAlterar[1],"2-Modelo");
	strcpy(menuAlterar[2],"3-Fabricante");
	strcpy(menuAlterar[3],"4-Chassi");
	strcpy(menuAlterar[4],"5-Ano");
	

	
		if(qtdeCadastros == 0){
		printf(">>>Nao ha veiculos cadastrados...");
		getch();
		return 0;
	}	
	//Opcao de pesquisa
	opMenu = menuOpcoes(5,menuAlterar,"Alterar");
	
	// ALTERA PLACA
	if(opMenu==1){ 
	
		//Pesquisa por placa
		if(leValidaString(pesquisaPlaca,"Informe a Placa para Pesquisa : ",topo,MIN_PESQUISA,TAM_PLACA,TIPO_LETRAS_NUMEROS,NAO) ==1 ){
			for(contador=0;contador<strlen(pesquisaPlaca);contador++)
			{
				pesquisaPlaca[contador]=toupper(pesquisaPlaca[contador]);
			}
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
				printf("\n%c >>>Erro: Placa não Encontrada...",BARRA_LATERAL);
				getch();
			}		
			else
			{
				opMenu = menuOpcoes(qtdeEncontrada,copiaPlaca+1,"Placas Encontradas ");  //Menu de Nomes Encontrados

				for(contador=1;contador<qtdeEncontrada+1;contador++)
				{
					if(opMenu==contador)
					{						
						// Novo placa para a opcao escolhida
						if(leValidaString(novaPlaca,"Informe a nova placa : ",topo,TAM_PLACA,TAM_PLACA,TIPO_LETRAS_NUMEROS,NAO) == 1){ 
							for(contador2=0;contador2<qtdeCadastros;contador2++)
							{
								if(strcmp(copiaPlaca[opMenu],veic[contador2].placa)==0)
								{
									strcpy(veic[contador2].placa,novaPlaca);  
								}
							}
						}else{
							printf("\n%c >>>Abortado...",IMG_OP);
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
					printf("PLACAS %s \n",veic[contador].placa);
				}
			}
		}else{
			printf("\n%c >>Abortado...",IMG_OP);
		}
		getch();
	}else if(opMenu == 2)
	{
			
		//Pesquisa por Modelo
		if(leValidaString(pesquisaModelo,"Informe a Modelo para Pesquisa : ",topo,MIN_PESQUISA,TAM_MODELO,TIPO_LETRAS_NUMEROS,NAO) ==1 ){
			for(contador=0;contador<strlen(pesquisaModelo);contador++)
			{
				pesquisaModelo[contador]=toupper(pesquisaModelo[contador]);
			}
			for(contador=0;contador<qtdeCadastros+1;contador++)
			{
				if(strstr(veic[contador].modelo,pesquisaModelo))
				{
					strcpy(copiaModelo[qtdeEncontrada+1],veic[contador].modelo);
					qtdeEncontrada++;
				}
			}
			if(qtdeEncontrada==0) 
			{			
				printf("\n%c >>>Erro: Modelo não Encontrada...",BARRA_LATERAL);
				getch();
			}		
			else
			{
				opMenu = menuOpcoes(qtdeEncontrada,copiaModelo+1,"Modelos Encontradas ");  //Menu de Nomes Encontrados

				for(contador=1;contador<qtdeEncontrada+1;contador++)
				{
					if(opMenu==contador)
					{						
						// Novo Modelo para a opcao escolhida
						if(leValidaString(novoModelo,"Informe a nova Modelo : ",topo,TAM_MODELO,TAM_MODELO,TIPO_LETRAS_NUMEROS,NAO) == 1){ 
							for(contador2=0;contador2<qtdeCadastros;contador2++)
							{
								if(strcmp(copiaModelo[opMenu],veic[contador2].modelo)==0)
								{
									strcpy(veic[contador2].modelo,novoModelo);  
								}
							}
						}else{
							printf("\n%c >>>Abortado...",IMG_OP);
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
					printf("Modelos %s \n",veic[contador].modelo);
				}
			}
		}else{
			printf("\n%c >>Abortado...",IMG_OP);
		}
		getch();
		
	}else if(opMenu == 3)
	{
					
		//Pesquisa por Fabricante
		if(leValidaString(pesquisaFabricante,"Informe a Fabricante para Pesquisa : ",topo,MIN_PESQUISA,TAM_FABRICANTE,TIPO_LETRAS_NUMEROS,NAO) ==1 ){
			for(contador=0;contador<strlen(pesquisaFabricante);contador++)
			{
				pesquisaFabricante[contador]=toupper(pesquisaFabricante[contador]);
			}
			for(contador=0;contador<qtdeCadastros+1;contador++)
			{
				if(strstr(veic[contador].fabricante,pesquisaFabricante))
				{
					strcpy(copiaFabricante[qtdeEncontrada+1],veic[contador].fabricante);
					qtdeEncontrada++;
				}
			}
			if(qtdeEncontrada==0) 
			{			
				printf("\n%c >>>Erro: Fabricantenão Encontrada...",BARRA_LATERAL);
				getch();
			}		
			else
			{
				opMenu = menuOpcoes(qtdeEncontrada,copiaFabricante+1,"Fabricantes Encontradas ");  //Menu de Nomes Encontrados

				for(contador=1;contador<qtdeEncontrada+1;contador++)
				{
					if(opMenu==contador)
					{						
						// Novo Fabricante para a opcao escolhida
						if(leValidaString(novoFabricante,"Informe a nova Fabricante : ",topo,TAM_FABRICANTE,TAM_FABRICANTE,TIPO_LETRAS_NUMEROS,NAO) == 1){ 
							for(contador2=0;contador2<qtdeCadastros;contador2++)
							{
								if(strcmp(copiaFabricante[opMenu],veic[contador2].fabricante)==0)
								{
									strcpy(veic[contador2].fabricante,novoFabricante);  
								}
							}
						}else{
							printf("\n%c >>>Abortado...",IMG_OP);
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
					printf("Fabricantes %s \n",veic[contador].fabricante);
				}
			}
		}else{
			printf("\n%c >>Abortado...",IMG_OP);
		}
		getch();
	}else if(opMenu == 4){
							
		//Pesquisa por Chassi
		if(leValidaString(pesquisaChassi,"Informe o Chassi para Pesquisa : ",topo,MIN_PESQUISA,TAM_CHASSI,TIPO_LETRAS_NUMEROS,NAO) ==1 ){
			for(contador=0;contador<strlen(pesquisaChassi);contador++)
			{
				pesquisaChassi[contador]=toupper(pesquisaChassi[contador]);
			}
			for(contador=0;contador<qtdeCadastros+1;contador++)
			{
				if(strstr(veic[contador].chassi,pesquisaChassi))
				{
					strcpy(copiaChassi[qtdeEncontrada+1],veic[contador].chassi);
					qtdeEncontrada++;
				}
			}
			if(qtdeEncontrada==0) 
			{			
				printf("\n%c >>>Erro: Chassi não Encontrada...",BARRA_LATERAL);
				getch();
			}		
			else
			{
				opMenu = menuOpcoes(qtdeEncontrada,copiaChassi+1,"Chassis Encontradas ");  //Menu de Nomes Encontrados

				for(contador=1;contador<qtdeEncontrada+1;contador++)
				{
					if(opMenu==contador)
					{						
						// Novo Chassi para a opcao escolhida
						if(leValidaString(novoChassi,"Informe o novo Chassi : ",topo,TAM_CHASSI,TAM_CHASSI,TIPO_LETRAS_NUMEROS,NAO) == 1){ 
							for(contador2=0;contador2<qtdeCadastros;contador2++)
							{
								if(strcmp(copiaChassi[opMenu],veic[contador2].chassi)==0)
								{
									strcpy(veic[contador2].chassi,novoChassi);  
								}
							}
						}else{
							printf("\n%c >>>Abortado...",IMG_OP);
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
					printf("Chassis %s \n",veic[contador].chassi);
				}
			}
		}else{
			printf("\n%c >>Abortado...",IMG_OP);
		}
		getch();
	}else if(opMenu ==5){
									
		//Pesquisa por Ano
		if(leValidaString(pesquisaAno,"Informe o Ano para Pesquisa : ",topo,MIN_PESQUISA,TAM_ANO,TIPO_LETRAS_NUMEROS,NAO) ==1 ){
			for(contador=0;contador<strlen(pesquisaAno);contador++)
			{
				pesquisaAno[contador]=toupper(pesquisaAno[contador]);
			}
			for(contador=0;contador<qtdeCadastros+1;contador++)
			{
				
				if(strstr(veic[contador].anoS,pesquisaAno))
				{
					strcpy(copiaAno[qtdeEncontrada+1],veic[contador].anoS);
					qtdeEncontrada++;
				}
			}
			if(qtdeEncontrada==0) 
			{			
				printf("\n%c >>>Erro: Ano nao Encontrada...",BARRA_LATERAL);
				getch();
			}		
			else
			{
				opMenu = menuOpcoes(qtdeEncontrada,copiaAno+1,"Anos Encontradas ");  //Menu de Nomes Encontrados

				for(contador=1;contador<qtdeEncontrada+1;contador++)
				{
					if(opMenu==contador)
					{						
						// Novo Ano para a opcao escolhida 
						if(leValidaString(novoAno,"Informe o novo Ano : ",topo,TAM_ANO_STRING,TAM_ANO_STRING,TIPO_LETRAS_NUMEROS,NAO) == 1){ 
							for(contador2=0;contador2<qtdeCadastros;contador2++)
							{
								if(strcmp(copiaAno[opMenu],veic[contador2].anoS)==0)
								{
									strcpy(veic[contador2].anoS,novoAno);  
								}
							}
						}else{
							printf("\n%c >>>Abortado...",IMG_OP);
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
					printf("Anos %s \n",veic[contador].anoS);
				}
			}
		}else{
			printf("\n%c >>Abortado...",IMG_OP);
		}
		getch();
	}
	
}
