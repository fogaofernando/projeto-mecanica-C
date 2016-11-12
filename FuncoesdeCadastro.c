#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include "structs.c"
#include "defines.c"

//Calcular o valor do "cont" de acordo com o valor da "flag"
#define CALCULA_CONT flag == 1 ? cont++ : cont--;

//Prototipos________________________________________________________________________________________________

//Proprietario
int cadastraProprietario(int *qtdeCadastros,Proprietario *prop,char *topo);
int cadastraVeiculo(int *qtdeVeiculos,Veiculo *veic,char *topo);
void excluiProprietario(int qtdeCadastros,Proprietario *prop,char *topo);
int leituraCpf(char *CPF,char *topo,int *qtdeCadastros,Proprietario *prop);
int leituraPlaca(char *veic,char *topo,int *qtdeVeiculos);


//Funcoes_____________________________________________________________________________________________________

//Cadastra o proprietario;
//Entrada : referencia a quantidade de cadastros, a struct propetario e a mensagem do topo;
//Retorno : 1 em caso de sucesso na leitura e 0 caso abortado a operacao;
int cadastraProprietario(int *qtdeCadastros,Proprietario *prop,char *topo)
{
	//variaveis
	
	int flag,cont = 0;


	
	//Desenvolvimento
	
	do{
		flag=1;
		
		//nome
		if(cont == 0){
			 flag = leValidaString(prop[*qtdeCadastros].nome,"Insira o nome: ",topo,MIN_NOME,MAX_NOME,TIPO_LETRAS,SIM);
			 if(flag == 1){
			 	cont++;
			 }else{
			 	printf("\n>>>abortado....");
			 	getch();
			 	return 0;	//leitura de dados abortada
			 }
		}
		
		//CPF
		if(cont == 1){
//			flag = leituraCpf(prop[*qtdeCadastros].cpf,topo,qtdeCadastros,prop);			
			
			/*if(flag == 1){
				cont++;
			}else{
				cont--;
			}*/
			
			CALCULA_CONT
		}
		
		//descricao do endereco
		if(cont == 2){
	//		flag = leValidaString(prop[*qtdeCadastros].descricao,"Insira a Descricao do Endereco: ",topo,MIN_DESCRICAO,MAX_DESCRICAO,TIPO_LETRAS_ESPECIAIS_NUMEROS,SIM);
			CALCULA_CONT
		}
		
		//estado
		if(cont == 3){
//			flag = leValidaString(prop[*qtdeCadastros].estado,"Insira o Estado : ",topo,MIN_ESTADO,MAX_ESTADO,TIPO_LETRAS_ESPECIAIS,SIM);
			CALCULA_CONT
		}
		
		//cidade
		if(cont == 4){
	//		flag = leValidaString(prop[*qtdeCadastros].cidade,"Insira a Cidade: ",topo,MIN_CIDADE,MAX_CIDADE,TIPO_LETRAS_ESPECIAIS,SIM);
			CALCULA_CONT
		}
		
		//telefone
		if(cont == 5){
	//		flag = leValidaString(prop[*qtdeCadastros].telefone,"Insira o Telefone: ",topo,MIN_TELEFONE,MAX_TELEFONE,TIPO_INTEIRO,NAO);
			CALCULA_CONT
		}
		
		//finalizacao
		if(cont == 6){
			prop[*qtdeCadastros].cadastrado=1;
			*qtdeCadastros=*qtdeCadastros+1;
			gotoxy(3,5);
			printf(">>>Dados salvos com sucesso...");
			getch();
			return 1;	//finalizacao com sucesso
		}
	
	}while(flag == 0);
}


//Objetivo:	Faz a leitura e validacao do CPF;
//Entrada: 	Referencia a string para o CPF;
//Saída:  	1 em caso de leitura com sucesso e 0 caso de retorno com ESC;	
int leituraCpf(char *CPF,char *topo,int *qtdeCadastros,Proprietario *prop){
	//variaveis
	int flag;
	
	//desenvolvimento
	do{
		flag=0;
		if(leValidaString(CPF,"Insira o CPF: ",topo,TAM_CPF,TAM_CPF,TIPO_INTEIRO,NAO) == 0){
			return 0;
		}
		
		if(validaCPF(CPF)==0){
			flag=1;
			gotoxy(2,POS_Y_TOPO+3);
			printf(">>>ERRO: CPF INVALIDO....");
			getch();
		}									
		
		if(verificaStringRepetida(qtdeCadastros,prop,">>>ERRO: CPF Repetido")==0){
			flag=1;
		}	
	}while(flag==1);
	
	return 1;
	
}




//Excluir Porprietario
//Entrada : referencia a quantidade de cadastros e a struct
//Retorno : NULO
void excluiProprietario(int qtdeCadastros,Proprietario *prop,char *topo)
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
	
	
	//EXCLUI NOME
	leValidaString(pesquisaNome,"Informe o Nome para Exclusao: ",topo,MIN_NOME,MAX_NOME,TIPO_LETRAS,SIM);
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

				

					for(contador2=0;contador2<qtdeCadastros;contador2++)
					{
						if(strcmp(copiaNome[opMenu],prop[contador2].nome)==0)
						{
								strcpy(prop[contador2].nome,"\0");  
								printf("Nome Excluido ");	 
								getch();
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
}

//Cadastra veiculos
//Entrada : referencia a quantidade de Veiculos e a struct
//Retorno : 1 em caso de sucesso e 0 caso de operacao abortada
int cadastraVeiculo(int *qtdeVeiculos,Veiculo *veic,char *topo){
	//variaveis
	int flag,cont = 0;
	
	//Desenvolvimento
	do{	
		//Placa
		if(cont == 0){
			flag = leituraPlaca(veic[*qtdeVeiculos].placa,topo,qtdeVeiculos);
			if(flag == 1){
				cont++;
			}else{
				printf("\n >>>Operacao abortada...");
				getch();
				return 0;	//leitura abortada
			}
		}
		
		//modelo
		if(cont == 1){
			flag = leValidaString(veic[*qtdeVeiculos].modelo,"Insira o Modelo: ",topo,MIN_MODELO,MAX_MODELO,TIPO_LETRAS_NUMEROS,SIM);
			CALCULA_CONT
		}
		
		//fabricante
		if(cont == 2){
			flag = leValidaString(veic[*qtdeVeiculos].fabricante,"Insira o Fabricante: ",topo,MIN_FABRICANTE,MAX_FABRICANTE,TIPO_LETRAS_NUMEROS,SIM);
			CALCULA_CONT
		}
		//chassi
		if(cont ==3){
			flag= leValidaString(veic[*qtdeVeiculos].chassi,"Insira o Chassi : ",topo,TAM_CHASSI,TAM_CHASSI,TIPO_LETRAS_NUMEROS,SIM);
			CALCULA_CONT
		}
		
		//leValidaInt("Insira o Ano de Fabricacao: ",topo,">>>ERRO: Ano Invalido",MIN_ANO,MAX_ANO,&veic[*qtdeVeiculos].ano);
		
		//finalizacao
		if(cont == 3){
			*qtdeVeiculos = *qtdeVeiculos = 1;
			printf("\n >>>leitura de dados feita com sucesso..");
			getch();
			return 1;
		}
		
	}while(flag == 0);
	
}


//Objetivo:	Faz a leitura da placa;
//Entrada:	Referencia ao veiculo, a mensagem do topo e quantidade de veiculo;
//Saida:	1 em caso de leitura com sucesso e 0 caso de retorno com ESC;		
int leituraPlaca(char *veic,char *topo,int *qtdeVeiculos){
	//variaveis
	int flag;
	
	//desenvolvimento
	do{
		flag=0;
		
		if(leValidaString(veic,"Informe a Placa do Veiculo: ",topo,TAM_PLACA,TAM_PLACA,TIPO_LETRAS_NUMEROS,NAO) == 0 ){
			return 0;		//retorno por ESC
		}
		
		if(validaPlaca(veic)==0){
			flag=0;
			gotoxy(2,POS_Y_TOPO+3);
			printf(">>>Placa Invalida");
			getch();
		}else{
			flag = 1;
		}
		
	}while(flag==0);
	
	return 1; //retorno com sucesso	
}
