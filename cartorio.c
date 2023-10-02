#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h>//biblioteca de alocação de textos por região
#include <string.h>//biblioteca de string

int registro()//Função responsávelpor cadasrar os usuários 
{
	//inicio Variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final variáveis/string
	
	printf("Digite o CPF cadastrado: ");//coletando o CPF do usuário
	scanf("%s",cpf);//Armazena esse CPF/%s refere-se a string
	
	strcpy(arquivo, cpf);//Responsável por copiar os valores do cpf no arquivo
	
	FILE*file;//cria arquivo file
	file= fopen(arquivo,"w");//Instrução para criar esse arquivo
	fprintf(file,"\n\n");//Quebra linha dentro do arquivo
	fprintf(file,"CPF: ");//Mostra o texto cpf 
	fprintf(file,cpf);//salva e armazena o valor da variável (cpf) no arquivo file
	fclose(file);//fecha o arquivo
	
	file=fopen(arquivo,"a");//Copia o conteúdo no arquivo
	fprintf(file,"\nNOME: ");//Mostra o texto
	fclose(file);//Fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: ");//Pede o nome a ser cadastrado
	scanf("%s",nome);//Armazena a informação coletada
	
	file=fopen(arquivo,"a");//Copia o conteúdo no arquivo
	fprintf(file,nome);//Salva o valor da variável
	fclose(file);//Fecha o arquivo
	
	file=fopen(arquivo,"a");//Coia o conteúdo no arquivo
	fprintf(file,"\nSOBRENOME: ");//Mostra o texto ao usuário
	fclose(file);
	
	printf("Digite seu sobrenome a ser cadastrado: ");//texto sobrenome
	scanf("%s",sobrenome);//armazena o valor digitado
	
	file=fopen(arquivo,"a");//escreve dentro do arquivo
	fprintf(file, sobrenome);//armazena a informação recolhida no cadastro
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
	
	system("pause");//pausa para o usuário ver o sistema
	
	
	
}
	
int consultar()//Página consulta
{
	setlocale(LC_ALL, "Portuguese");//Define a linguagem 
	
	char cpf[40];//Vvariável que guarda o CPF
	char conteudo[200];//Variável que guarda as informações do usuário
	
	printf("Digite o CPF a ser consultado: ");//Pede o CPF do usuário
	scanf("%s",cpf);//Armazena o valor do CPF como uma string
	
	FILE*file;//chama o arquivo file com as informações o usuário
	file=fopen(cpf,"r");//Lê as informações coletadas do usuário
	
	//se file igual a NUll retorno um printf
	if(file==NULL)//Verifica se o CPF digitado existe dentro do arquivo
	{
		printf("Arquivo não localizado!");
	}
	
	    //retorno da resposta ao usuário no caso das informações estarem no banco de dados
	    //não está dentro do while para não se repetir a cada item(cpf,nome,sobrenome,cargo)
		printf("\n Essas são as informações do usuário: ");
		
	//se file diferente de Null recebe arquivo conteudo com até 200 variáveis	
	while(fgets(conteudo,200,file)!=NULL)
	{
		printf("%s",conteudo);
    }
    
    fclose(file);//Fecha o arquivo
    
    system("pause");//Tempo para o usuário ver as informações
}
	
int deletar()//Página deletar usuário
{
	char cpf[40];//Variável que armazena o CPF
	
	printf("Digite o CPF a ser deletado: ");//Pergunta o CPF a ser deletado ao usuário
    scanf("%s",cpf);//Armazena o valor do cpf em forma de string
    
    remove(cpf);//Remove as informações contidas nesse CPF dentro do banco de dados
    
    
    FILE*file;//Chama o arquivo com as informações do usuário
    file=fopen(cpf,"r");//Lê as informações dentro do arquivo
    
    
	//if=se / else= se não
	if(file==NULL)//Validando se o CPF existe dentro do arquivo
	{
	    printf("O usuário não se encontra no sistema!\n");//retorno ao usuário
		system("pause");//pausa
	}
	
	else{
		
		printf("Esse usuário acaba de ser deletado!\n");//retorno ao usuário
		system("pause");//pausa
	}
	
	fclose(file);//Fecha o arquivo
	
}
	
int main()
{
	int opcao=0;//colocando valor a variável
	int laco=1;
	
	
	for(laco=1;laco=1;)//estrutura de repetição
	{
	    system("cls");//responsavel por limpar a tela
	
	    setlocale(LC_ALL,"portuguese");//definindo a linguagem
	
	    printf("#####Cartório da EBAC#####\n\n");//ínicio do menu de seleção
	    printf("Escolha a opção desejada do menu:\n\n");
	    printf("\t1-Registrar nomes \n");
	    printf("\t2-consultar nomes \n");
	    printf("\t3-Deletar nomes \n\n");
	    printf("\t4-Sair do sistema!\n\n");
	    printf("opção:");//fim do menu de seleção
	
	    scanf("%d",&opcao);//armazenamento da escolha do úsuario
	    system("cls");
	    
	    
	    switch(opcao)//Valida a opção que o usuário que no sistema(registro,consulta,deleta)
	    {
	    	case 1://caso 1
	        	registro();//chamada da função 1
    	    break;//fecha a codição
    	    
    	    case 2://caso 2
    	        consultar();//chamada da fução 2
		    break;//fecha a condição
		    
		    case 3://caso3
		        deletar();//chamada da função 3
		    break;//fecha a condição
		    
		    case 4:
                 printf("Obrigado por utilizar o sistema!\n");
                 return 0;
            break;
            		    
		    default://escolha de alguma função que não está disponivel no sistema
		        printf("Essa opção não está disponível!\n");//string que será mostrada ao usuário
		        system("pause");//pausa no sistema para exibir o código 
		    break;//fechamento da condição
	    }
	}
	
		
}
		
    	
    


