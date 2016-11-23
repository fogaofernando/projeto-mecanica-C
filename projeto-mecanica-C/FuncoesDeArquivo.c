#include <stdio.h>
#include <string.h>
#include "structs.c"
#include "defines.c"

//Prototipos_____________________________________________________________________________________________________________________________________
FILE * abreArquivo(char *nomeArq,char *modo,int apresMsg);
void apresentaMsgErro( char *msg, char * idFuncao);
int criaArq(char *nomeArq,char *tipoDado);
int leDadosProp(Proprietario *prop,int *qtProp);
int leDadosVeic(Veiculo *veic,int *qtVeic);
int leDadosManu(Manutencao *manu,int *qtManu);
int leituraInicialDados(Proprietario *prop,Veiculo *veic,Manutencao *manu,int *qtdProp,int *qtdVeic,int *qtdManu);
int gravarProp(int qtdeProprietarios,Proprietario *prop);
int gravarVeic(int qtdeVeic,Veiculo *veic);
int gravarManu(int qtdeManu,Manutencao *manu);


//Funcoes_________________________________________________________________________________________________________________________________________
// função - abre um arquivo qualquer
// parâmetros - endereço de memória onde localiza-se o nome do arquivo
//               endereço de memória onde localiza-se o modo de abertura do arquivo
//               indicador se deve ser apresentada mensagem no caso de erro
// retorno - endereço de memória onde localiza-se a estrutura FILE ou NULL no 
//            caso de erro
FILE * abreArquivo(char *nomeArq,char *modo,int apresMsg)
{
FILE *arq;
char msg[200];
   arq = fopen(nomeArq,modo);
   if(arq == NULL)
   {
      if(apresMsg == 1)
      {  
         sprintf(msg," Erro ao abrir arquivo (%s) no modo (%s)\n",nomeArq,modo);
         apresentaMsgErro(msg,"abreArquivo");
      }   
   }
   return arq;
}



void apresentaMsgErro( char *msg, char * idFuncao)
{

  gotoxy(6,23);
  fprintf(stdout,"(%s) %s",idFuncao,msg);
  getch();

}

//Objetivo: Leitura/inicializacao de todos os arquivos e joga-los na memoria ao iniciar o programa;
//Entrada:	Referencia as estruturas e as variaveis de quantidade: Proprietario, Veiculo e Manutencao;
//Retorno:	1 em caso de leitura com sucesso;
int leituraInicialDados(Proprietario *prop,Veiculo *veic,Manutencao *manu,int *qtdProp,int *qtdVeic,int *qtdManu){
	
	//Dados do proprietario
	if(leDadosProp(prop,qtdProp)!=1){
		if(criaArq(ARQ_PROP,"Proprietario") !=1 ){
			return 0;
		}
	}
	//dados do veiculo
	if(leDadosVeic(veic,qtdVeic)!=1){
		if(criaArq(ARQ_VEIC,"Veiculo")!=1){
			return 0;
		}
	}
	//dados de manutencao
	if(leDadosManu(manu,qtdManu)!=1){
		if(criaArq(ARQ_MANU,"Manutencao")!=1){
			return 0;
		}
	}
	return 1;
}


//Objetivo: Apresenta mensagem de opcoes e cria arquivo;
//Entrada: referencia ao nome do arquivo que sera salvo e o tipo de arquivo que sera tratado(proprietario, veiculo ou manutencao);
//Retorno: 1 em caso de finalizacao com sucesso;
int criaArq(char *nomeArq,char *tipoDado){
	//variaveis/inicializacao
	FILE *arq;
	int op;
	char opSimNao[2][NOME_OPCOES];
	char apresentaMenu[NOME_OPCOES];
	
	strcpy(opSimNao[0],"Sim");
	strcpy(opSimNao[1],"Nao");
	
	//desenvolviemento
	system("cls");
	janelaMenu();
	gotoxy(3,3);
	printf("Nao foi possivel ler os dados ja salvos do arquivo \"%s\"...",nomeArq);
	gotoxy(3,4);
	system("pause");
	
	//Opcao do usuario
	sprintf(apresentaMenu,"Deseja criar um novo arquivo para salvar os dados do %s ?",tipoDado);
	op = menuOpcoes(2,opSimNao,apresentaMenu);
	if(op == 1){
		arq=abreArquivo(nomeArq,"wb",0);			
		
		//verifica abertura do arquivo
		if(arq == NULL){
			
			system("cls");
			janelaMenu();
			gotoxy(3,3);	
			printf(">>>ERRO: Nao foi possivel criar o arquivo \"%s\"...",nomeArq);
			gotoxy(3,4);
			system("pause");
			return 0;	
		
		}else{
			return 1;
		}
	}else{
		system("cls");
		janelaMenu();
		gotoxy(3,3);	
		printf(">>> O programa sera finalizado... ");
		gotoxy(3,4);
		system("pause");
		return 0;
	}
	
	
}




//Le os dados do proprietario armazenados no arquivo binario e calcula a quantidade de proprietarios;
//Entrada: Referencia ao vetor da estrutura proprietario e a quantidade de proprietarios;
//Retorno: 1 em caso de sucesso
int leDadosProp(Proprietario *prop,int *qtProp){
	
	//Variaveis
	FILE *arq;
	Proprietario propAux;
	*qtProp = 0;
	
	//Abrindo arquivo
	arq=abreArquivo(ARQ_PROP,"rb",0);
	
  	//Verificando abertura do arquivo
	if(arq != NULL)
	{
		//lendo dados do arquivo
    	while(!feof(arq))
      	{
			if(fread(&propAux,sizeof(Proprietario),1,arq) == 1){  
      			//transportando dados
      			strcpy(prop[*qtProp].nome,propAux.nome);	
	      		strcpy(prop[*qtProp].cpf,propAux.cpf);	
      			strcpy(prop[*qtProp].descricao,propAux.descricao);	
      			strcpy(prop[*qtProp].estado,propAux.estado);	
      			strcpy(prop[*qtProp].cidade,propAux.cidade);	
      			strcpy(prop[*qtProp].telefone,propAux.telefone);	
				prop[*qtProp].servRealizado = propAux.servRealizado;
					                                        
				*qtProp = *qtProp +1;
         
		 	}
        }     
      
      	//Fechando arquivo
	  	if(fclose(arq) != 0){
           	return 0;
    	}
    	
    	//finalizando com sucesso
		return 1;
   }else{
   		return 0;
   }
}


//Le os dados dos veiculos armazenados no arquivo binario e calcula a quantidade de veiculos cadastrados;
//Entrada: Referencia ao vetor da estrutura Veiculos e a quantidade de veiculos;
//Retorno: 1 em caso de sucesso
int leDadosVeic(Veiculo *veic,int *qtVeic){
	
	//Variaveis
	FILE *arq;
	Veiculo veicAux;
	*qtVeic = 0;
	
	//Abrindo arquivo
	arq=abreArquivo(ARQ_VEIC,"rb",0);
	
  	//Verificando abertura do arquivo
	if(arq != NULL)
	{
		//lendo dados do arquivo
    	while(!feof(arq))
      	{
			if(fread(&veicAux,sizeof(Veiculo),1,arq) == 1){  
      			//transportando dados
      			strcpy(veic[*qtVeic].placa,veicAux.placa);	
	      		strcpy(veic[*qtVeic].modelo,veicAux.modelo);	
      			strcpy(veic[*qtVeic].idProprietario,veicAux.idProprietario);	
      			strcpy(veic[*qtVeic].fabricante,veicAux.fabricante);	
      			strcpy(veic[*qtVeic].chassi,veicAux.chassi);	
      			strcpy(veic[*qtVeic].anoS,veicAux.anoS);	
				veic[*qtVeic].ano = veicAux.ano;
				veic[*qtVeic].manutRealizada = veicAux.manutRealizada;
					                                        
				*qtVeic = *qtVeic +1;
         
		 	}
        }     
      
      	//Fechando arquivo
	  	if(fclose(arq) != 0){
           	return 0;
    	}
    	
    	//finalizando com sucesso
		return 1;
   }else{
   		return 0;
   }
}


//Le os dados de manutencao armazenados no arquivo binario e calcula a quantidade de manutencao cadastrados;
//Entrada: Referencia ao vetor da estrutura Manutencao e a quantidade de manutencoes;
//Retorno: 1 em caso de sucesso
int leDadosManu(Manutencao *manu,int *qtManu){
	
	//Variaveis
	FILE *arq;
	Manutencao manuAux;
	*qtManu = 0;
	
	//Abrindo arquivo
	arq=abreArquivo(ARQ_MANU,"rb",0);
	
  	//Verificando abertura do arquivo
	if(arq != NULL)
	{
		//lendo dados do arquivo
    	while(!feof(arq))
      	{
			if(fread(&manuAux,sizeof(Manutencao),1,arq) == 1){  
      			//transportando dados
      			strcpy(manu[*qtManu].data,manuAux.data);	
				strcpy(manu[*qtManu].descricao,manuAux.descricao);	
                strcpy(manu[*qtManu].idProprietario,manuAux.idProprietario);	
                strcpy(manu[*qtManu].idVeiculo,manuAux.idVeiculo);	
                manu[*qtManu].maodeObra = manuAux.maodeObra;
                manu[*qtManu].valorPecas = manuAux.maodeObra;
                
				*qtManu = *qtManu +1;
         
		 	} 
        }     
      
      	//Fechando arquivo  
	  	if(fclose(arq) != 0){
           	return 0;
    	}
    	
    	//finalizando com sucesso
		return 1;
   }else{
   		return 0;
   }
}



//objetivo :  grava os dados do proprietaio em um arquivo Binario ;
//paramentro: qtde de Proprietarios e referencia a struct  Proprietario;
//retorno :   1 em caso de gravacao com sucesso;
int gravarProp(int qtdeProprietarios,Proprietario *prop)
{
	//Variaveis
	Proprietario propAux;
	FILE *arq;
	int cont;
	
	//desenvolvimento
	arq = abreArquivo(ARQ_PROP,"wb",1);
     	
		//Verificando abertura de arquivo
		if(arq != NULL){
			//salvando dados
			for(cont = 0;cont<qtdeProprietarios;cont++){
		    	//transportando dados
				strcpy(propAux.nome,prop[cont].nome);	
		  		strcpy(propAux.cpf,prop[cont].cpf);	
				strcpy(propAux.descricao,prop[cont].descricao);	
				strcpy(propAux.estado,prop[cont].estado);	
				strcpy(propAux.cidade,prop[cont].cidade);	
				strcpy(propAux.telefone,prop[cont].telefone);	
				propAux.servRealizado = prop[cont].servRealizado;
		    	
		    	//salvando dados
				if(fwrite(&propAux,sizeof(Proprietario),1,arq)!= 1){
		   			return 0;
				}
		 	}
			//verificando fechamento do arquivo
			if(fclose(arq) != 0){
				return 0;
			}
		}else{
			return 0;
		}	
		
		//finalizacao com sucesso
		return 1;
}


//objetivo :  grava os dados do veiculo em um arquivo Binario ;
//paramentro: qtde de veiculos e referencia a struct  Veiculo;
//retorno :   1 em caso de gravacao com sucesso;
int gravarVeic(int qtdeVeic,Veiculo *veic){
	//Variaveis
	Veiculo veicAux;
	FILE *arq;
	int cont;
	
	//desenvolvimento
	arq = abreArquivo(ARQ_VEIC,"wb",1);
     	
	//Verificando abertura de arquivo
	if(arq != NULL){
		//salvando dados
		for(cont = 0;cont<qtdeVeic;cont++){
	    	//transportando dados
			strcpy(veicAux.anoS,veic[cont].anoS);	
	  		strcpy(veicAux.chassi,veic[cont].chassi);	
			strcpy(veicAux.fabricante,veic[cont].fabricante);	
			strcpy(veicAux.idProprietario,veic[cont].idProprietario);	
			strcpy(veicAux.modelo,veic[cont].modelo);	
			strcpy(veicAux.placa,veic[cont].placa);	
			veicAux.ano = veic[cont].ano;
	    	veicAux.manutRealizada =veic[cont].manutRealizada;
	    	
	    	//salvando dados
			if(fwrite(&veicAux,sizeof(Veiculo),1,arq)!= 1){
	   			return 0;	
			}
		}
		
		//verificando fechamento do arquivo
		if(fclose(arq) != 0){
			return 0;
		}
	}else{
		return 0;
	}	
	
	//finalizacao com sucesso
	return 1;
}


//objetivo :  grava os dados da manutencao em um arquivo Binario ;
//paramentro: qtde de manutencoes e referencia a struct  Manutencao;
//retorno :   1 em caso de gravacao com sucesso;
int gravarManu(int qtdeManu,Manutencao *manu){
	//Variaveis
	Manutencao manuAux;
	FILE *arq;
	int cont;
	
	//desenvolvimento
	arq = abreArquivo(ARQ_MANU,"wb",1);
     	
	//Verificando abertura de arquivo
	if(arq != NULL){
		//salvando dados
		for(cont = 0;cont<qtdeManu;cont++){
	    	//transportando dados
			strcpy(manuAux.data,manu[cont].data);	
	  		strcpy(manuAux.descricao,manu[cont].descricao);	
			strcpy(manuAux.idProprietario,manu[cont].idProprietario);	
			strcpy(manuAux.idVeiculo,manu[cont].idVeiculo);		
			manuAux.maodeObra = manu[cont].maodeObra;
	    	manuAux.valorPecas =manu[cont].valorPecas;
	    	
	    	//salvando dados
			if(fwrite(&manuAux,sizeof(Manutencao),1,arq)!= 1){
	   			return 0;
			}
		}
		
		//verificando fechamento do arquivo
		if(fclose(arq) != 0){
			return 0;
		}
	}else{
		return 0;
	}	
	
	//finalizacao com sucesso
	return 1;
}






/*
// função - apresenta os dados de todos os alunos cadastrados
// parâmetros - nenhum
// retorno - 1
int apresentaAlunos(void)
{
FILE *arq;
Proprietario prop;
int linha,cont=0;
   limpaJanela(1,1,25,80,BRANCO); 
   desenhaMoldura(1,1,20,80,BRANCO,PRETO);
   gotoxy(2,2);
   fprintf(stdout," Dados dos Alunos"); 
   linha = 3;
   arq = abreArquivo("alunos.txt","rb",0);
   if(arq != NULL)
   {
      while(!feof(arq))
      {
         if(fread(&aluno,sizeof(Aluno),1,arq) == 1)
         {
             if(linha >= 18)
             {
                gotoxy(2,linha);
                fprintf(stdout," Tecle qq tecla para continuar\n");
                getch();
                limpaJanela(3,2,19,79,BRANCO);
                retornaCor(BRANCO,PRETO);
                linha =3;
             }  
             gotoxy(2,linha);
             linha++; 
             cont=1;                                                    
             fprintf(stdout,"%6d - %-40.40s - %5.1f\n",aluno.matricula,aluno.nome,aluno.nota);
         }
      }     
      if(fclose(arq) != 0)
           apresentaMsgErro("Erro ao fechar arquivo","apresentaAlunos");
   } 
   if(cont==0)
   {
      gotoxy( 10,10);
      fprintf(stdout," Nao existem alunos cadastrados");
   }   
   getch();
   return 1;
}*/
