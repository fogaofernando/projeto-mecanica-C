#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include "structs.c"
#include "defines.c"

//Prototipos______________________________________________________________________________________________________
int excluiProp(int *qtdeProp,Proprietario *prop,char *topo);



//Funcoes__________________________________________________________________________________________________________

//Objetivo:	Excluir o cadastro de um proprietario;
//Entrada:	Referencia a quantidade de proprietarios e a estrutura propetarios;
//Saida:	1 em caso de exclusao com sucesso;
int excluiProp(int *qtdeProp,Proprietario *prop,char *topo){
	//variaveis
	
	int opMenu,contador,contador2=0,qtdeEncontrada=0,qtdeLetras,cont,cont2,posPesquisadas[*qtdeProp],posFinal;  //AUXILIARES   /*pos = posicao da estrutura dos dados */
	char menuAlterar[3][NOME_OPCOES],menuEndereco[3][NOME_OPCOES];  // Menu 
	char copiaNome [*qtdeProp][NOME_OPCOES],novoNome[TAM_NOME],pesquisaNome[TAM_NOME]; // ALTERA NOME
	char copiaDescricao [*qtdeProp][NOME_OPCOES],novaDescricao[TAM_NOME],pesquisaDescricao[TAM_DESCRICAO_END]; // ALTERA DESCRICAO
	char copiaEstado [*qtdeProp][NOME_OPCOES],novoEstado[TAM_ESTADO],pesquisaEstado[TAM_ESTADO]; // ALTERA ESTADO
	char copiaCidade [*qtdeProp][NOME_OPCOES],novaCidade[TAM_CIDADE],pesquisaCidade[TAM_CIDADE];
	char copiaTelefone [*qtdeProp][NOME_OPCOES],novoTelefone[TAM_TELEFONE],pesquisaTelefone[TAM_TELEFONE]; // ALTERA CIDADE
	char opSimNao[2][NOME_OPCOES]; 
	
	//Opcoes de menu
	strcpy(menuAlterar[0],"1-Nome");
	strcpy(menuAlterar[1],"2-Endereco");
	strcpy(menuAlterar[2],"3-Telefone");
	strcpy(menuEndereco[0],"1-Descricao");
	strcpy(menuEndereco[1],"2-Estado");
	strcpy(menuEndereco[2],"3-Cidade");
	strcpy(opSimNao[0],"SIM");		
	strcpy(opSimNao[1],"NAO");		

	//Desenvolvimento______________________________________________________________________________________________
	
	//verificar quantidade de proprietarios
	if(*qtdeProp == 0){
		printf(">>>Nao ha proprietarios cadastrados...");
		getch();
		return 0;
	}	

	//Opcao de pesquisa
	opMenu = menuOpcoes(3,menuAlterar,"Alterar");
	if(opMenu==1){
		//Pesquisa por NOME
		if( leValidaString(pesquisaNome,"Informe o Nome para Pesquisa: ",topo,MIN_PESQUISA,TAM_NOME,TIPO_LETRAS,SIM) == 1 ){
			
			//Pesquisa por nome/verificando pesquisa
			for(contador=0;contador<*qtdeProp;contador++)
			{  
				if(strstr(prop[contador].nome,pesquisaNome))
				{
					posPesquisadas[qtdeEncontrada] = contador;
					strcpy(copiaNome[qtdeEncontrada],prop[contador].nome);
					qtdeEncontrada++;
				}
				
			}
			
			//verificando/manupulando dados encontrados
			if(qtdeEncontrada==0)
			{			
				printf(">>>Erro: Nome não Encontrado...");
				getch();
			}		
			else
			{
				//Escolhendo entre opcoes pesquisadas
				printf("Nome Pesquisado : %s",pesquisaNome);
				opMenu = menuOpcoes(qtdeEncontrada,copiaNome,"Nome Pesquisado : %s");  //Menu de Nomes Encontrados
				
				if(opMenu != 0){
					
					//posicao da estrutura do proprietario escolhido
					posPesquisadas[opMenu-1] = posFinal;
					printf("nome %s",prop[0].nome);
					getch();
					//Confirmando exclusao
					if(prop[posFinal].servRealizado == NAO){
						char apresentaMenu[50];
						sprintf(apresentaMenu,"%s%s%s","Voce deseja Excluir os dados do proprietario: ",prop[posFinal].nome," ?");
						
						opMenu = menuOpcoes(2,opSimNao,apresentaMenu);
						
						//excluindo dados
						if(opMenu == 1){
							
							for(cont = posFinal;cont<qtdeEncontrada;cont++){
								for(cont2 = cont+1;cont2<qtdeEncontrada;cont2++){
									strcpy(prop[cont].nome,prop[cont2].nome);
									strcpy(prop[cont].cpf,prop[cont2].cpf);
									strcpy(prop[cont].descricao,prop[cont2].descricao);
									strcpy(prop[cont].cidade,prop[cont2].cidade);
									strcpy(prop[cont].estado,prop[cont2].estado);
									strcpy(prop[cont].telefone,prop[cont2].telefone);
									prop[cont].servRealizado = prop[cont2].servRealizado;
								}
							}
							*qtdeProp = *qtdeProp -1;
							
							
							//apresentando dados
							for(contador=0;contador<*qtdeProp;contador++)
							{
								printf("NOME %s \n",prop[contador].nome);
							}
							getch();
						}else{
							printf(">>>opcao cancelada...");
							getch();
						}
					}else{
						printf(">>>ERRO:O proprietario nao pode ser apagado pois ja realizou servico nessa oficina...");
						getch();
						return 0;
					}
					
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
	
				for(contador=0;contador<*qtdeProp+1;contador++)
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
								for(contador2=0;contador2<*qtdeProp;contador2++)
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
					for(contador=0;contador<*qtdeProp;contador++)
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
				for(contador=0;contador<*qtdeProp+1;contador++)
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
							for(contador2=0;contador2<*qtdeProp;contador2++)
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
					for(contador=0;contador<*qtdeProp;contador++)
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
				for(contador=0;contador<*qtdeProp+1;contador++)
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
								for(contador2=0;contador2<*qtdeProp;contador2++)
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
					for(contador=0;contador<*qtdeProp;contador++)
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
				for(contador=0;contador<*qtdeProp+1;contador++)
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
								for(contador2=0;contador2<*qtdeProp;contador2++)
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
					for(contador=0;contador<*qtdeProp;contador++)
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

