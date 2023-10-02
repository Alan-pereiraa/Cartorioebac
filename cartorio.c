#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h>//biblioteca de aloca��o de textos por regi�o
#include <string.h>//biblioteca de string

int registro()//Fun��o respons�velpor cadasrar os usu�rios 
{
	//inicio Vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final vari�veis/string
	
	printf("Digite o CPF cadastrado: ");//coletando o CPF do usu�rio
	scanf("%s",cpf);//Armazena esse CPF/%s refere-se a string
	
	strcpy(arquivo, cpf);//Respons�vel por copiar os valores do cpf no arquivo
	
	FILE*file;//cria arquivo file
	file= fopen(arquivo,"w");//Instru��o para criar esse arquivo
	fprintf(file,"\n\n");//Quebra linha dentro do arquivo
	fprintf(file,"CPF: ");//Mostra o texto cpf 
	fprintf(file,cpf);//salva e armazena o valor da vari�vel (cpf) no arquivo file
	fclose(file);//fecha o arquivo
	
	file=fopen(arquivo,"a");//Copia o conte�do no arquivo
	fprintf(file,"\nNOME: ");//Mostra o texto
	fclose(file);//Fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: ");//Pede o nome a ser cadastrado
	scanf("%s",nome);//Armazena a informa��o coletada
	
	file=fopen(arquivo,"a");//Copia o conte�do no arquivo
	fprintf(file,nome);//Salva o valor da vari�vel
	fclose(file);//Fecha o arquivo
	
	file=fopen(arquivo,"a");//Coia o conte�do no arquivo
	fprintf(file,"\nSOBRENOME: ");//Mostra o texto ao usu�rio
	fclose(file);
	
	printf("Digite seu sobrenome a ser cadastrado: ");//texto sobrenome
	scanf("%s",sobrenome);//armazena o valor digitado
	
	file=fopen(arquivo,"a");//escreve dentro do arquivo
	fprintf(file, sobrenome);//armazena a informa��o recolhida no cadastro
	fclose(file);//fecha arquivo
	
	file=fopen(arquivo,"a");//escreve dentro do arquivo
	fprintf(file,"\nCARGO: ");//aparece o texto cargo na tela
	fclose(file);//fecha o arquivo
	
	printf("Digite seu cargo a ser cadastrado: ");//texto cargo
	scanf("%s",cargo);//armazena o valor da string
	
	file=fopen(arquivo,"a");//abre e escreve esse valor no arquivo
	fprintf(file, cargo);//armazena no arquivo
	fprintf(file,"\n\n");//pula linha dentro do aquivo
	fclose(file);//fecha arquivo
	
	system("pause");//pausa para o usu�rio ver o sistema
	
	
	
}
	
int consultar()//P�gina consulta
{
	setlocale(LC_ALL, "Portuguese");//Define a linguagem 
	
	char cpf[40];//Vvari�vel que guarda o CPF
	char conteudo[200];//Vari�vel que guarda as informa��es do usu�rio
	
	printf("Digite o CPF a ser consultado: ");//Pede o CPF do usu�rio
	scanf("%s",cpf);//Armazena o valor do CPF como uma string
	
	FILE*file;//chama o arquivo file com as informa��es o usu�rio
	file=fopen(cpf,"r");//L� as informa��es coletadas do usu�rio
	
	//se file igual a NUll retorno um printf
	if(file==NULL)//Verifica se o CPF digitado existe dentro do arquivo
	{
		printf("Arquivo n�o localizado!");
	}
	
	    //retorno da resposta ao usu�rio no caso das informa��es estarem no banco de dados
	    //n�o est� dentro do while para n�o se repetir a cada item(cpf,nome,sobrenome,cargo)
		printf("\n Essas s�o as informa��es do usu�rio: ");
		
	//se file diferente de Null recebe arquivo conteudo com at� 200 vari�veis	
	while(fgets(conteudo,200,file)!=NULL)
	{
		printf("%s",conteudo);
    }
    
    fclose(file);//Fecha o arquivo
    
    system("pause");//Tempo para o usu�rio ver as informa��es
}
	
int deletar()//P�gina deletar usu�rio
{
	char cpf[40];//Vari�vel que armazena o CPF
	
	printf("Digite o CPF a ser deletado: ");//Pergunta o CPF a ser deletado ao usu�rio
    scanf("%s",cpf);//Armazena o valor do cpf em forma de string
    
    remove(cpf);//Remove as informa��es contidas nesse CPF dentro do banco de dados
    
    
    FILE*file;//Chama o arquivo com as informa��es do usu�rio
    file=fopen(cpf,"r");//L� as informa��es dentro do arquivo
    
    
	//if=se / else= se n�o
	if(file==NULL)//Validando se o CPF existe dentro do arquivo
	{
	    printf("O usu�rio n�o se encontra no sistema!\n");//retorno ao usu�rio
		system("pause");//pausa
	}
	
	else{
		
		printf("Esse usu�rio acaba de ser deletado!\n");//retorno ao usu�rio
		system("pause");//pausa
	}
	
	fclose(file);//Fecha o arquivo
	
}
	
int main()
{
	int opcao=0;//colocando valor a vari�vel
	int laco=1;
	
	
	for(laco=1;laco=1;)//estrutura de repeti��o
	{
	    system("cls");//responsavel por limpar a tela
	
	    setlocale(LC_ALL,"portuguese");//definindo a linguagem
	
	    printf("#####Cart�rio da EBAC#####\n\n");//�nicio do menu de sele��o
	    printf("Escolha a op��o desejada do menu:\n\n");
	    printf("\t1-Registrar nomes \n");
	    printf("\t2-consultar nomes \n");
	    printf("\t3-Deletar nomes \n\n");
	    printf("\t4-Sair do sistema!\n\n");
	    printf("op��o:");//fim do menu de sele��o
	
	    scanf("%d",&opcao);//armazenamento da escolha do �suario
	    system("cls");
	    
	    
	    switch(opcao)//Valida a op��o que o usu�rio que no sistema(registro,consulta,deleta)
	    {
	    	case 1://caso 1
	        	registro();//chamada da fun��o 1
    	    break;//fecha a codi��o
    	    
    	    case 2://caso 2
    	        consultar();//chamada da fu��o 2
		    break;//fecha a condi��o
		    
		    case 3://caso3
		        deletar();//chamada da fun��o 3
		    break;//fecha a condi��o
		    
		    case 4:
                 printf("Obrigado por utilizar o sistema!\n");
                 return 0;
            break;
            		    
		    default://escolha de alguma fun��o que n�o est� disponivel no sistema
		        printf("Essa op��o n�o est� dispon�vel!\n");//string que ser� mostrada ao usu�rio
		        system("pause");//pausa no sistema para exibir o c�digo 
		    break;//fechamento da condi��o
	    }
	}
	
		
}
		
    	
    


