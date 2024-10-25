#include <stdio.h> //biblioteca de comunicaçãocom o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória 
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsavél por cuidar das string

int registro() //função responsavel por cadastrar os usuarios no sistema
{
	
	// inicio criação de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Fim da criação de variaveis/ string
	
	printf("digite o cpf a ser cadastrado:\n");//coletando informações do usuario
	scanf("%s", cpf);// percente %s refere-se a string
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das string

	FILE *file; //chamando uma função/ cria o arquivo
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
		printf("Não foi possivel abrir o arquivo,não localizado!\n");
	}
	while(fgets(conteudo,200,file) != NULL)
	{
		printf("\n Essas sao as informaçoes do usuario: ");
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
	int opcao=0; // definindo váriaveis 
	int laco=1;
	for(laco=1;laco=1;)
	{
		
	    system("cls");
	   
        
	
        printf("### Cartório da EBAC ### \n\n"); //inicio do menu
        printf("Escolha a opção desejada do menu:\n\n");
	    printf("\t1 - Registro de Nome\n");
	    printf("\t2 - Consulta de Nome\n");
	    printf("\t3 - Deletar Nome\n");
	    printf("opção:");//fim do menu
	
	    scanf("%d", &opcao);// armazenando a escolha do usuario 
	
	    system("cls");// responsavel por limpar a tela 
	    
	    
	    switch(opcao) // inicío da seleção do menu 
	    {
	    	case 1:
	    	registro(); // chamada de função
	    	break;
	    	
	    	case 2:
	    	consultar();
	    	break;
	    	
	    	case 3:
	    	deletar();
	    	break;
	    	
	    	
	    	default:
	    	printf("está opcao nao esta disponivel");
	    	system("pause");
	    	break;
	    
	     }//fim da seleção
	 
	}    
}

