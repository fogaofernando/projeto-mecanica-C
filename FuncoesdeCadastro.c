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
int leituraCpf(char *CPF,char *topo,int *qtdeCadastros,Proprietario *prop);
int leituraPlaca(char *veic,char *topo,int *qtdeVeiculos);
int cadastraManutencao(int *qtdeManutencoes,int qtdeVeiculos,int qtdeProprietarios,Proprietario *prop,Veiculo *veic,Manutencao *Manu,char *topo);

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
//			flag = leValidaString(veic[*qtdeVeiculos].modelo,"Insira o Modelo: ",topo,MIN_MODELO,MAX_MODELO,TIPO_LETRAS_NUMEROS,SIM);
			CALCULA_CONT
		}
		
		//fabricante
		if(cont == 2){
//			flag = leValidaString(veic[*qtdeVeiculos].fabricante,"Insira o Fabricante: ",topo,MIN_FABRICANTE,MAX_FABRICANTE,TIPO_LETRAS_NUMEROS,SIM);
			CALCULA_CONT
		}
		//chassi
		if(cont ==3){
//			flag= leValidaString(veic[*qtdeVeiculos].chassi,"Insira o Chassi : ",topo,TAM_CHASSI,TAM_CHASSI,TIPO_LETRAS_NUMEROS,SIM);
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

//Cadastra Manutencoes
//Entrada : referencia a quantidade de Manutencoes,veiculos e proprietarios , as structs : Manutencao,Veiculos e Proprietario e ao topo
//Retorno : 1 em caso de sucesso e 0 caso de operacao abortada
int cadastraManutencao(int *qtdeManutencoes,int qtdeVeiculos,int qtdeCadastros,Proprietario *prop,Veiculo *veic,Manutencao *manu,char *topo){
	//variaveis
	
	int flag,flag1,cont = 0,contador;
	char pesquisaPlaca[TAM_PLACA];
	
	//Desenvolvimento
	
	do{
		flag=1;
		flag1=0;
		//ID do Veiculo
		if(cont == 0){
	//		 flag = leValidaString(prop[*qtdeCadastros].nome,"Insira o nome: ",topo,MIN_NOME,MAX_NOME,TIPO_LETRAS,SIM);
			flag = leituraPlaca(pesquisaPlaca,topo,&qtdeVeiculos);
			for(contador=0;contador<qtdeVeiculos+1;contador++)
				{
				if(stricmp(veic[contador].placa,pesquisaPlaca))
				{
					strcpy(manu[*qtdeManutencoes].idVeiculo,veic[contador].placa);
					flag1=1;
				}

			}
			if(flag1==0) 
			{			
				printf(">>>Erro: Placa não Encontrada...");
				getch();
			}		
		
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
			prop[qtdeCadastros].cadastrado=1;
			*qtdeManutencoes=*qtdeManutencoes+1;
			gotoxy(3,5);
			printf(">>>Dados salvos com sucesso...");
			getch();
			return 1;	//finalizacao com sucesso
		}
	
	}while(flag == 0);
}
