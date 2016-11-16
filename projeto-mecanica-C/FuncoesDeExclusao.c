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
	char opSimNao[*qtdeProp][NOME_OPCOES]; 
	char apresentaMenu[50];
	
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
			}else{
				//Escolhendo entre opcoes pesquisadas
				printf("Nome Pesquisado : %s",pesquisaNome);
				opMenu = menuOpcoes(qtdeEncontrada,copiaNome,"Nome Pesquisado : %s");  //Menu de Nomes Encontrados
				
				if(opMenu != 0){
					
					//posicao da estrutura do proprietario escolhido
					posFinal = posPesquisadas[opMenu-1];
					printf("nome %s",prop[0].nome);
					getch();
					
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
		
	}
}

