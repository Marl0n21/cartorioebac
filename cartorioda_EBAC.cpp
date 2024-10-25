#include <stdio.h> //biblioteca de comunica��ocom o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria 
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca responsav�l por cuidar das string

int registro() //fun��o responsavel por cadastrar os usuarios no sistema
{
	
	// inicio cria��o de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Fim da cria��o de variaveis/ string
	
	printf("digite o cpf a ser cadastrado:\n");//coletando informa��es do usuario
	scanf("%s", cpf);// percente %s refere-se a string
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das string

	FILE *file; //chamando uma fun��o/ cria o arquivo
	file = fopen(arquivo, "w"); // cria arquivo
	fprintf(file,cpf); //salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen (arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	printf("digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	printf("digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);

	system("pause");
	
}

int consultar()

{
    setlocale(LC_ALL,"Portuguese"); // definindo a linguagem
    
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: " );
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("N�o foi possivel abrir o arquivo,n�o localizado!\n");
	}
	while(fgets(conteudo,200,file) != NULL)
	{
		printf("\n Essas sao as informa�oes do usuario: ");
		printf("%s", conteudo);
		printf("\n\n");		
	}
	
	system("pause");
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digitar o CPF a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	
	{
		printf("O usuario nao encontrado no sistema:\n\n usuario ja foi removido:\n");
		system("pause");
		
	}	
}


int main()
    {
	int opcao=0; // definindo v�riaveis 
	int laco=1;
	for(laco=1;laco=1;)
	{
		
	    system("cls");
	   
        
	
        printf("### Cart�rio da EBAC ### \n\n"); //inicio do menu
        printf("Escolha a op��o desejada do menu:\n\n");
	    printf("\t1 - Registro de Nome\n");
	    printf("\t2 - Consulta de Nome\n");
	    printf("\t3 - Deletar Nome\n");
	    printf("op��o:");//fim do menu
	
	    scanf("%d", &opcao);// armazenando a escolha do usuario 
	
	    system("cls");// responsavel por limpar a tela 
	    
	    
	    switch(opcao) // inic�o da sele��o do menu 
	    {
	    	case 1:
	    	registro(); // chamada de fun��o
	    	break;
	    	
	    	case 2:
	    	consultar();
	    	break;
	    	
	    	case 3:
	    	deletar();
	    	break;
	    	
	    	
	    	default:
	    	printf("est� opcao nao esta disponivel");
	    	system("pause");
	    	break;
	    
	     }//fim da sele��o
	 
	}    
}

