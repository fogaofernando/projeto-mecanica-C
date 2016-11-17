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
int leituraIdProprietario(char *CPF,char *topo,int *qtdeCadastros,Manutencao *manu);
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
			 flag = leValidaString(prop[*qtdeCadastros].nome,"Insira o nome: ",topo,MIN_NOME,TAM_NOME,TIPO_LETRAS,SIM);
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
			flag = leituraCpf(prop[*qtdeCadastros].cpf,topo,qtdeCadastros,prop);			
			
			/*if(flag == 1){
				cont++;
			}else{
				cont--;
			}*/
			
			CALCULA_CONT
		}
		
		//descricao do endereco
		if(cont == 2){
			flag = leValidaString(prop[*qtdeCadastros].descricao,"Insira a Descricao do Endereco: ",topo,MIN_DESCRICAO_END,TAM_DESCRICAO_END,TIPO_LETRAS_ESPECIAIS_NUMEROS,SIM);
			CALCULA_CONT
		}
		
		//estado
		if(cont == 3){
			flag = leValidaString(prop[*qtdeCadastros].estado,"Insira o Estado : ",topo,MIN_ESTADO,TAM_ESTADO,TIPO_LETRAS_ESPECIAIS,SIM);
			CALCULA_CONT
		}
		
		//cidade
		if(cont == 4){
			flag = leValidaString(prop[*qtdeCadastros].cidade,"Insira a Cidade: ",topo,MIN_CIDADE,TAM_CIDADE,TIPO_LETRAS_ESPECIAIS,SIM);
			CALCULA_CONT
		}
		
		//telefone
		if(cont == 5){
			flag = leValidaString(prop[*qtdeCadastros].telefone,"Insira o Telefone: ",topo,MIN_TELEFONE,TAM_TELEFONE,TIPO_INTEIRO,NAO);
			CALCULA_CONT
		}
		
		//finalizacao
		if(cont == 6){
			prop[*qtdeCadastros].servRealizado=NAO;
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
//Objetivo:	Faz a leitura e validacao do CPF;
//Entrada: 	Referencia a string para o CPF;
//Saída:  	1 em caso de leitura com sucesso e 0 caso de retorno com ESC;	
int leituraIdProprietario(char *CPF,char *topo,int *qtdeCadastros,Manutencao *manu){
	
	//variaveis
	int flag;
	
	//Desenvolvimento
	do{
		flag=0;
		if(leValidaString(CPF,"Insira o CPF do Proprietario: ",topo,TAM_CPF,TAM_CPF,TIPO_INTEIRO,NAO) == 0){
			return 0;
		}
		
		if(validaCPF(CPF)==0){
			flag=1;
			gotoxy(2,POS_Y_TOPO+3);
			printf(">>>ERRO: CPF INVALIDO....");
			getch();
		}									
		/*
		if(verificaStringRepetida(qtdeCadastros,manu,">>>ERRO: CPF Repetido")==0){
			flag=1;
		}
		*/	
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
			flag = leValidaString(veic[*qtdeVeiculos].modelo,"Insira o Modelo: ",topo,MIN_MODELO,TAM_MODELO,TIPO_LETRAS_NUMEROS,SIM);
			CALCULA_CONT
		}
	
		//fabricante
		if(cont == 2){
			flag = leValidaString(veic[*qtdeVeiculos].fabricante,"Insira o Fabricante: ",topo,MIN_FABRICANTE,TAM_FABRICANTE,TIPO_LETRAS_NUMEROS,SIM);
			CALCULA_CONT
		}
		//chassi
		if(cont ==3){
			flag= leValidaString(veic[*qtdeVeiculos].chassi,"Insira o Chassi : ",topo,TAM_CHASSI,TAM_CHASSI,TIPO_LETRAS_NUMEROS,SIM);
			CALCULA_CONT
		}
		
		//ano de fabricacao
		if(cont == 4){
			leValidaInt(&veic[*qtdeVeiculos].ano,"Insira o Ano de Fabricacao: ",topo,MIN_ANO,TAM_ANO);
			sprintf(veic[*qtdeVeiculos].anoS,"%i",veic[*qtdeVeiculos].ano);
			CALCULA_CONT
		}
		
		//finalizacao
		if(cont == 5){
			*qtdeVeiculos = *qtdeVeiculos + 1;
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
	
	//Desenvolvimento
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
	
	int flag, cont=0,cont2,flag2,flag3,flag4;   
	char opcao;
	
	//Desenvolvimento
	do{
		//ID do Veiculo
		
		if(qtdeVeiculos==0 && qtdeCadastros==0)
		{
			gotoxy(3,10);
			printf(">>>Erro : Nao existem Carros e Proprietarios Cadastrados");
			return 0;	
		}
		if(qtdeVeiculos==0)
		{
			gotoxy(3,10);
			printf(">>>Erro : Nao existem Carros Cadastrados");
			return 0;	
		}
		if(qtdeCadastros==0)
		{
			gotoxy(3.10);
			printf(">>>Erro :Nao existem Proprietarios Cadastrados");
			return 0;
		}
			
		if(cont == 0){
			flag2=0;
			flag = leValidaString(manu[*qtdeManutencoes].idVeiculo,"Informe a placa do veiculo: ",topo,TAM_PLACA,TAM_PLACA,TIPO_LETRAS_NUMEROS,NAO);
			for(cont2=0;cont2<qtdeVeiculos;cont2++)
			{
				if(stricmp(manu[*qtdeManutencoes].idVeiculo,veic[cont2].placa)==0) // Verificar se a placa Existe
				{
					flag2=1;
					flag3=cont2;   // Posição da placa
				}
			}
			
			if(flag2 == 0) //Placa Não existe
			{
				gotoxy(3,10);
				printf(">>>Erro :Placa nao encontrada...");
				getch();
				return 0;
			}
			
			if(flag == 1){
				cont++;
			}else{
				printf("\n >>>Operacao abortada...");
				getch();
				return 0;	//leitura abortada
			}
		}
		
		//ID do propetario
		if(cont == 1){
			flag = leituraIdProprietario(manu[*qtdeManutencoes].idProprietario,topo,qtdeManutencoes,manu);
			
			for(cont2=0;cont2<qtdeCadastros;cont2++)
			{
					
				if(stricmp(manu[*qtdeManutencoes].idProprietario,prop[cont2].cpf)==0) // Verificar se o CPF Existe
				{
					flag2=1;
					flag4=cont2;      //posição do CPF
				}			
			}
			
			if(flag2 == 0) //CPF Não existe
			{
				gotoxy(3,10);
				printf(">>>Erro :CPF nao encontrado...");
				getch();
				return 0;
			}
			CALCULA_CONT
		}
		if(cont == 2){
			flag = leValidaString(manu[*qtdeManutencoes].descricao,"Informe a descricao do conserto: ",topo,MIN_DESCRICAO_MANUTENCAO,TAM_DESCRICAO_MANUTENCAO,TIPO_LETRAS_ESPECIAIS_NUMEROS,SIM);
			CALCULA_CONT
		}
		
		if(cont == 3){
			flag = leValidaFloat(&manu[*qtdeManutencoes].valorPecas,"Informe o valor das pecas: R$ ",topo,MIN_VALOR,TAM_VALOR);	
			CALCULA_CONT
		}
				
		if(cont == 4){
			flag = leValidaFloat(&manu[*qtdeManutencoes].maodeObra,"Informe o valor da mao de obra: R$ ",topo,MIN_MAODEOBRA,TAM_MAODEOBRA);
			CALCULA_CONT
		}
		//printf("\nValor = %f   - %d ",manu[0].valorPecas,*qtdeManutencoes);
	//	getch();	
		if(cont == 5){
			strcpy(manu[*qtdeManutencoes].data,"");
			strcat(manu[*qtdeManutencoes].data,__DATE__);
			strcpy(veic[*qtdeManutencoes].idProprietario,manu[*qtdeManutencoes].idProprietario);
			gotoxy(3,6);
			printf(">ID veiculo: %s",manu[*qtdeManutencoes].idVeiculo);
			gotoxy(3,7);
			printf(">ID propetario: %s",manu[*qtdeManutencoes].idProprietario);
			gotoxy(3,8);
			printf(">Descricao: %s",manu[*qtdeManutencoes].descricao);
			gotoxy(3,9);
			printf(">Valor pecas: %f",manu[*qtdeManutencoes].valorPecas);
			gotoxy(3,10);
			printf(">mao de obra %f",manu[*qtdeManutencoes].maodeObra);
			gotoxy(3,11);
			printf(">Data : %s",manu[*qtdeManutencoes].data);
			gotoxy(3,14);
			leValidaOpcao(&opcao,"Confirmar Manutencao ?S/N","SN");		
			switch(opcao)
			{
				case'S':
				{

					prop[flag4].servRealizado=1;
					veic[flag3].manutRealizada=1;
					*qtdeManutencoes=*qtdeManutencoes+1;
					gotoxy(3,20);
					printf(">>>Dados salvos com sucesso...");
					getch();
					return 1;	//finalizacao com sucesso
				
				}
				case'N':
				{
					printf("\n >>>Operacao abortada...");
					getch();
					return 0;	//leitura abortada
				}	


		}
	}
	}while(flag == 0);
}


/*
//Objetivo: Faz a leitura do ID do veiculo
//Entrada:	
//Saida:		
int leituraIdVeiculo(){
	//Vaiaveis
	int op;
	
	//Desenvolvimento
	op = menuOpcoes(2,)
	
}*/

