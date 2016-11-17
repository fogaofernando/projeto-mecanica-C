#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include "structs.c"
#include "defines.c"

//Prototipos______________________________________________________________________________________________________
int excluiProp(int *qtdeProp,Proprietario *prop,char *topo);
int excluiVeic(int *qtdeVeic,Veiculo *veic,char *topo);

//Funcoes__________________________________________________________________________________________________________

//Objetivo:	Excluir o cadastro de um proprietario;
//Entrada:	Referencia a quantidade de proprietarios e a estrutura propetarios;
//Saida:	1 em caso de exclusao com sucesso;
int excluiProp(int *qtdeProp,Proprietario *prop,char *topo){
	//variaveis
	
	int opMenu,contador,contador2=0,qtdeEncontrada=0,cont,cont2,posPesquisadas[*qtdeProp],posFinal;  //AUXILIARES   /*pos = posicao da estrutura dos dados */
	char menuAlterar[3][NOME_OPCOES];  // Menu 
	char copiaNome [*qtdeProp][NOME_OPCOES],pesquisaNome[TAM_NOME]; // pesquisa por  NOME
	char copiaCPF [*qtdeProp][NOME_OPCOES],pesquisaCPF[TAM_CPF+1]; // pesquisa por CPF
	char opSimNao[*qtdeProp][NOME_OPCOES]; 
	char apresentaMenu[50];
	
	//Opcoes de menu
	strcpy(menuAlterar[0],"1-Nome");
	strcpy(menuAlterar[1],"2-CPF");
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
	opMenu = menuOpcoes(2,menuAlterar,topo);
	
	if(opMenu==1){
		//Pesquisa por NOME_______________________________________________________________________________________________________
		if( leValidaString(pesquisaNome,"Informe o Nome para Pesquisa: ",topo,MIN_PESQUISA,TAM_NOME,TIPO_LETRAS,SIM) == 1 ){
			
			//Pesquisa por nome/verificando pesquisa
			for(contador=0;contador<*qtdeProp;contador++)
			{  
				if(strstr(prop[contador].nome,pesquisaNome))
				{
					posPesquisadas[qtdeEncontrada] = contador;
					sprintf(copiaNome[qtdeEncontrada],"%s - %s",prop[contador].nome,prop[contador].cpf);
					qtdeEncontrada++;
				}
				
			}
			
			//verificando/manupulando dados encontrados
			if(qtdeEncontrada==0)
			{			
				printf(">>>Erro: Nome não Encontrado...");
				getch();
				return 0;
			}else{
				//Escolhendo entre opcoes pesquisadas
				printf("Nome Pesquisado : %s",pesquisaNome);
				opMenu = menuOpcoes(qtdeEncontrada,copiaNome,"Nome Pesquisado : %s");  //Menu de Nomes Encontrados
				
				if(opMenu != 0){
					
					//posicao da estrutura do proprietario escolhido
					posFinal = posPesquisadas[opMenu-1];
					
					//Confirmando exclusao
					if(prop[posFinal].servRealizado == NAO){
						
						sprintf(apresentaMenu,"%s %s %s","Voce deseja Excluir os dados do proprietario:",prop[posFinal].nome," ?");
						
						opMenu = menuOpcoes(2,opSimNao,apresentaMenu);
						
						//excluindo dados
						if(opMenu == 1){
							
							//Movendo os dados uma casa 
							for(cont = posFinal;cont < (*qtdeProp-1);cont++){
									cont2 = cont+1;
															
									strcpy(prop[cont].nome,prop[cont2].nome);
									strcpy(prop[cont].cpf,prop[cont2].cpf);
									strcpy(prop[cont].descricao,prop[cont2].descricao);
									strcpy(prop[cont].cidade,prop[cont2].cidade);
									strcpy(prop[cont].estado,prop[cont2].estado);
									strcpy(prop[cont].telefone,prop[cont2].telefone);
									prop[cont].servRealizado = prop[cont2].servRealizado;
							}
							*qtdeProp = *qtdeProp - 1;
							
							//apresentando dados
							for(contador=0;contador<*qtdeProp;contador++)
							{
								printf("NOME %s \n",prop[contador].nome);
							}
							
							//finalizacao com sucesso
							getch();
							return 1;
						
						}else{
							printf(">>>opcao cancelada...");
							getch();
							return 0;
						}
					}else{
						printf(">>>ERRO:O proprietario nao pode ser apagado pois ja realizou servico nessa oficina...");
						getch();
						return 0;
					}
					 
				}else{
					return 0;
				}
			}
		}else{
			printf(">>>abortado...");
			getch();
			return 0;
		}
		

	}else if(opMenu == 2){
		
		//Pesquisa por CPF_______________________________________________________________________________________________________
		if( leValidaString(pesquisaCPF,"Informe o CPF para Pesquisa: ",topo,MIN_PESQUISA,TAM_CPF,TIPO_INTEIRO,NAO) == 1 ){
			
			//Pesquisa por CPF/verificando pesquisa
			for(contador=0;contador<*qtdeProp;contador++)
			{  
				if(strstr(prop[contador].cpf,pesquisaCPF))
				{
					posPesquisadas[qtdeEncontrada] = contador;
					sprintf(copiaCPF[qtdeEncontrada],"%s - %s",prop[contador].cpf,prop[contador].nome);
					qtdeEncontrada++;
				}
				
			}
			
			//verificando/manupulando dados encontrados
			if(qtdeEncontrada==0)
			{			
				printf(">>>Erro: Nome não Encontrado...");
				getch();
			}else{
				//Escolhendo entre opcoes pesquisadas
				sprintf(apresentaMenu,"%s %s","CPF Pesquisado: ",pesquisaCPF);
				opMenu = menuOpcoes(qtdeEncontrada,copiaCPF,apresentaMenu);  //Menu de Nomes Encontrados
				
				if(opMenu != 0){
					
					//posicao da estrutura do proprietario escolhido
					posFinal = posPesquisadas[opMenu-1];
					
					//Confirmando exclusao
					if(prop[posFinal].servRealizado == NAO){
						
						sprintf(apresentaMenu,"%s%s%s","Voce deseja Excluir os dados do proprietario: ",prop[posFinal].nome," ?");
						
						opMenu = menuOpcoes(2,opSimNao,apresentaMenu);
						
						//excluindo dados
						if(opMenu == 1){
							
							//Movendo os dados uma casa 
							for(cont = posFinal;cont < (*qtdeProp-1);cont++){
									cont2 = cont+1;
															
									strcpy(prop[cont].nome,prop[cont2].nome);
									strcpy(prop[cont].cpf,prop[cont2].cpf);
									strcpy(prop[cont].descricao,prop[cont2].descricao);
									strcpy(prop[cont].cidade,prop[cont2].cidade);
									strcpy(prop[cont].estado,prop[cont2].estado);
									strcpy(prop[cont].telefone,prop[cont2].telefone);
									prop[cont].servRealizado = prop[cont2].servRealizado;
							}
							*qtdeProp = *qtdeProp - 1;
							
							//apresentando dados
							for(contador=0;contador<*qtdeProp;contador++){
								printf("NOME %s - CPF %s \n",prop[contador].nome,prop[contador].cpf);
							}
							
							//finalizacao com sucesso
							getch();
							return 1;
						
						}else{
							printf(">>>opcao cancelada...");
							getch();
							return 0;
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
			getch();
			return 0;
		}
		
			
	}
}



//Objetivo:	Excluir o cadastro de um veiculo;
//Entrada:	Referencia a quantidade de veiculos, estrutura veiculos e mensage do topo;
//Saida:	1 em caso de exclusao com sucesso;
int excluiVeic(int *qtdeVeic,Veiculo *veic,char *topo){
	//variaveis
	
	int opMenu,contador,contador2=0,qtdeEncontrada=0,cont,cont2,posPesquisadas[*qtdeVeic],posFinal;  //AUXILIARES   /*pos = posicao da estrutura dos dados */
	char menuAlterar[3][NOME_OPCOES];  // Menu 
	char copiaPlaca [*qtdeVeic][NOME_OPCOES],pesquisaPlaca[TAM_PLACA+1]; // pesquisa por  placa
	char copiaChassi [*qtdeVeic][NOME_OPCOES],pesquisaChassi[TAM_CHASSI+1]; // pesquisa por chassi
	char opSimNao[*qtdeVeic][NOME_OPCOES]; 
	char apresentaMenu[50];
	
	//Opcoes de menu
	strcpy(menuAlterar[0],"1-Placa");
	strcpy(menuAlterar[1],"2-Chassi");
	strcpy(opSimNao[0],"SIM");		
	strcpy(opSimNao[1],"NAO");		

	//Desenvolvimento______________________________________________________________________________________________
	
	//verificar quantidade de proprietarios
	if(*qtdeVeic == 0){
		printf(">>>Nao ha veiculos cadastrados...");
		getch();
		return 0;
	}	

	//Opcao de pesquisa
	opMenu = menuOpcoes(2,menuAlterar,topo);
	
	if(opMenu==1){
		//Pesquisa por Placa_______________________________________________________________________________________________________
		if( leValidaString(pesquisaPlaca,"Informe a placa para Pesquisa: ",topo,MIN_PESQUISA,TAM_PLACA,TIPO_LETRAS_NUMEROS,NAO) == 1 ){
			
			//transformando pesquisa em maiuscula
			for(contador =0;contador< strlen(pesquisaPlaca);contador++){
				pesquisaPlaca[contador] = toupper(pesquisaPlaca[contador]);
			}
			
			//Pesquisa por nome/verificando pesquisa
			for(contador=0;contador<*qtdeVeic;contador++)
			{  
				if(strstr(veic[contador].placa,pesquisaPlaca))
				{
					posPesquisadas[qtdeEncontrada] = contador;
					sprintf(copiaPlaca[qtdeEncontrada],"%s - %s",veic[contador].placa,veic[contador].modelo);
					qtdeEncontrada++;
				}
				
			}
			
			//verificando/manupulando dados encontrados
			if(qtdeEncontrada==0)
			{			
				printf(">>>Erro: Nome não Encontrado...");
				getch();
				return 0;
			}else{
				//Escolhendo entre opcoes pesquisadas
				printf("Nome Pesquisado : %s",pesquisaPlaca);
				opMenu = menuOpcoes(qtdeEncontrada,copiaPlaca,"Nome Pesquisado : %s");  //Menu de Nomes Encontrados
				
				if(opMenu != 0){
					
					//posicao da estrutura do proprietario escolhido
					posFinal = posPesquisadas[opMenu-1];
					
					//Confirmando exclusao
					if(veic[posFinal].manutRealizada == NAO){
						
						sprintf(apresentaMenu,"%s %s %s","Voce deseja Excluir os dados do veiculo:",veic[posFinal].placa," ?");
						
						opMenu = menuOpcoes(2,opSimNao,apresentaMenu);
						
						//excluindo dados
						if(opMenu == 1){
							
							//Movendo os dados uma casa 
							for(cont = posFinal;cont < (*qtdeVeic-1);cont++){
									cont2 = cont+1;
															
									strcpy(veic[cont].placa,veic[cont2].placa);
									strcpy(veic[cont].modelo,veic[cont2].modelo);
									strcpy(veic[cont].fabricante,veic[cont2].fabricante);
									strcpy(veic[cont].chassi,veic[cont2].chassi);
									veic[cont].ano = veic[cont2].ano;
									veic[cont].manutRealizada = veic[cont2].manutRealizada;
							}
							*qtdeVeic = *qtdeVeic - 1;
							
							//apresentando dados
							for(contador=0;contador<*qtdeVeic;contador++)
							{
								printf("placa: %s / modelo: %s/ chassi:  %s\n",veic[contador].placa,veic[contador].modelo,veic[contador].chassi);
							}
							
							//finalizacao com sucesso
							getch();
							return 1;
						
						}else{
							printf(">>>opcao cancelada...");
							getch();
							return 0;
						}
					}else{
						printf(">>>ERRO:O proprietario nao pode ser apagado pois ja realizou servico nessa oficina...");
						getch();
						return 0;
					}
					 
				}else{
					return 0;
				}
			}
		}else{
			printf(">>>abortado...");
			getch();
			return 0;
		}
		

	}else if(opMenu == 2){
		
		//Pesquisa por Chassi_______________________________________________________________________________________________________
		if( leValidaString(pesquisaChassi,"Informe o Chassi para Pesquisa: ",topo,MIN_PESQUISA,TAM_CHASSI,TIPO_LETRAS_NUMEROS,NAO) == 1 ){
			
			//transformando pesquisa em maiuscula
			for(contador =0;contador< strlen(pesquisaChassi);contador++){
				pesquisaChassi[contador] = toupper(pesquisaChassi[contador]);
			}
			
			//Pesquisa por chassi/verificando pesquisa
			for(contador=0;contador<*qtdeVeic;contador++)
			{  
				if(strstr(veic[contador].chassi,pesquisaChassi)){
					posPesquisadas[qtdeEncontrada] = contador;
					sprintf(copiaChassi[qtdeEncontrada],"%s - %s",veic[contador].chassi,veic[contador].modelo);
					qtdeEncontrada++;
				}
				
			}
			
			//verificando/manupulando dados encontrados
			if(qtdeEncontrada==0)
			{			
				printf(">>>Erro: chassi não Encontrado ...");
				getch();
			}else{
				//Escolhendo entre opcoes pesquisadas
				sprintf(apresentaMenu,"%s %s","Chassi Pesquisado: ",pesquisaChassi);
				opMenu = menuOpcoes(qtdeEncontrada,copiaChassi,apresentaMenu);  //Menu de Nomes Encontrados
				
				if(opMenu != 0){
					
					//posicao da estrutura do proprietario escolhido
					posFinal = posPesquisadas[opMenu-1];
					
					//Confirmando exclusao
					if(veic[posFinal].manutRealizada == NAO){
						
						sprintf(apresentaMenu,"%s%s%s","Voce deseja Excluir os dados do veiculo de chassi: ",veic[posFinal].chassi," ?");
						opMenu = menuOpcoes(2,opSimNao,apresentaMenu);
						
						//excluindo dados
						if(opMenu == 1){
							
							//Movendo os dados uma casa 
							for(cont = posFinal;cont < (*qtdeVeic-1);cont++){
									cont2 = cont+1;
															
									strcpy(veic[cont].placa,veic[cont2].placa);
									strcpy(veic[cont].modelo,veic[cont2].modelo);
									strcpy(veic[cont].fabricante,veic[cont2].fabricante);
									strcpy(veic[cont].chassi,veic[cont2].chassi);
									veic[cont].ano = veic[cont2].ano;
									veic[cont].manutRealizada = veic[cont2].manutRealizada;
							}
							*qtdeVeic = *qtdeVeic - 1;
							
							//apresentando dados
							for(contador=0;contador<*qtdeVeic;contador++)
							{
								printf("placa: %s / modelo: %s/ chassi:  %s\n",veic[contador].placa,veic[contador].modelo,veic[contador].chassi);
							}
							
							//finalizacao com sucesso
							getch();
							return 1;
						
						}else{
							printf(">>>opcao cancelada...");
							getch();
							return 0;
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
			getch();
			return 0;
		}
		
			
	}
}




//Objetivo:	Excluir os dados de manutencao ;
//Entrada:	Referencia a quantidade de manutencoes, estrutura manutencao e mensage do topo;
//Saida:	1 em caso de exclusao com sucesso;
int excluiManu(int *qtdeManu,Manutencao *manu,char *topo){
	//variaveis
	
	int opMenu,contador,contador2=0,qtdeEncontrada=0,cont,cont2,posPesquisadas[*qtdeManu],posFinal;  //AUXILIARES   pos = posicao da estrutura dos dados 
	char menuAlterar[3][NOME_OPCOES];  // Menu 
	char copiaPlaca [*qtdeManu][NOME_OPCOES],pesquisaPlaca[TAM_PLACA+1];	// pesquisa por placa
	char copiaCPF [*qtdeManu][NOME_OPCOES],pesquisaCPF[TAM_CPF+1]; 		// pesquisa por  cpf
	char opSimNao[*qtdeManu][NOME_OPCOES]; 
	char apresentaMenu[50];
	
	//Opcoes de menu
	strcpy(menuAlterar[0],"1-Placa");
	strcpy(menuAlterar[1],"2-Chassi");
	strcpy(opSimNao[0],"SIM");		
	strcpy(opSimNao[1],"NAO");		

	//Desenvolvimento______________________________________________________________________________________________
	
	//verificar quantidade de proprietarios
	if(*qtdeManu == 0){
		printf(">>>Nenhuma manutencao foi cadastrada...");
		getch();
		return 0;
	}	

	//pesquisa por chave do proprietario
	
	
	
	
	
	//Opcao de pesquisa
	if( leValidaString(pesquisaCPF,"Informe o CPF para Pesquisa: ",topo,MIN_PESQUISA,TAM_CPF,TIPO_INTEIRO,NAO) == 1 ){
			
			//Pesquisa por CPF/verificando pesquisa
			for(contador=0;contador<*qtdeManu;contador++)
			{  
				if(strstr(manu[contador].idProprietario,pesquisaCPF))
				{
					posPesquisadas[qtdeEncontrada] = contador;
					sprintf(copiaCPF[qtdeEncontrada],"CPF: %s - Placa: %s - Data: %s",manu[contador].idProprietario,manu[contador].idVeiculo,manu[contador].data);
					qtdeEncontrada++;
				}
				
			}
			
			//verificando/manupulando dados encontrados
			if(qtdeEncontrada==0)
			{			
				printf(">>>Erro: Nome não Encontrado...");
				getch();
			}else{
				//Escolhendo entre opcoes pesquisadas
				sprintf(apresentaMenu,"%s %s","Identificacao do proprietario Pesquisado: ",pesquisaCPF);
				opMenu = menuOpcoes(qtdeEncontrada,copiaCPF,apresentaMenu);  //Menu de Nomes Encontrados
				
				if(opMenu != 0){
					
					//posicao da estrutura do proprietario escolhido
					posFinal = posPesquisadas[opMenu-1];
					
					//Confirmando exclusao	
					sprintf(apresentaMenu,"%s%s%s","Voce deseja Excluir os dados da manutencao: ",manu[posFinal].idProprietario," ?");
					
					opMenu = menuOpcoes(2,opSimNao,apresentaMenu);
					
					//excluindo dados
					if(opMenu == 1){
						
						//Movendo os dados uma casa 
						for(cont = posFinal;cont < (*qtdeManu-1);cont++){
							cont2 = cont+1;
													
							strcpy(manu[cont].data,manu[cont2].data);
							strcpy(manu[cont].descricao,manu[cont2].descricao);
							strcpy(manu[cont].idProprietario,manu[cont2].idProprietario);
							strcpy(manu[cont].idVeiculo,manu[cont2].idVeiculo);
							
							manu[cont].maodeObra = manu[cont2].maodeObra;
							manu[cont].valorPecas = manu[cont2].valorPecas;
						}
						*qtdeManu = *qtdeManu - 1;
						
						//apresentando dados
						for(contador=0;contador<*qtdeManu;contador++){
							printf("CPF %s - Placa %s \n",manu[contador].idProprietario,manu[contador].idVeiculo);
						}
						
						//finalizacao com sucesso
						getch();
						return 1;
					
					}else{
						printf(">>>opcao cancelada...");
						getch();
						return 0;
					}
				}
			}
	}else{
		printf(">>>abortado...");
		getch();
		return 0;
	}
}

