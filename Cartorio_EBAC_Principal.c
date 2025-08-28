#include <stdio.h> //Biblioteca de comunica��o com usu�rio
#include <stdlib.h> //Bilbioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //Biblioteca de aloca��o de texto por regi�o
#include <string.h> //Biblioteca respons�vel por cuidar das string


int registro () //fun��o responsavel pelo registro de usuario
{
	//inicio cria��o de vari�veis/string
    char arquivo[40];
    char cpf[40];
    char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	
	printf("\n\n Digitar CPF cadrastado:  \n\n");//coletando informa��o do usu�rio
	scanf("%s" , cpf );//%s refere-se a string
	
	strcpy(arquivo, cpf); //responsavel por copiar valores das string
	
	FILE *file; //cria arquivo
	file = fopen(arquivo, "w"); //criar arquivo e o 'w' significa escrever
	fprintf(file,cpf); //salvar valor variavel
	fclose(file); //fechar arquivo
	
	file = fopen(arquivo, "a");// "a" abre um arquivo no modo de inclus�o
	fprintf(file,"\n");
	fclose(file);
	
	printf("\n\n Digite o nome:  \n\n");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, "\n");
	fclose(file);
	
	printf("\n\n Digite o sobrenome: \n\n");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,"\n");
	fclose(file);
	
	printf("\n\n Digite o Cargo a ser cadrastado:  \n\n");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");// para a opera��o do sistema 
	
	
	
	
	
}

int consulta()//fun��o de busca de usu�rio
{
	setlocale(LC_ALL,"Portuguese");//definindo linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("\n\n Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file== NULL)//caso o usu�rio n�o for encontrado
	{
		printf("\n\n N�o foi possivel abrir o arquivo, nao foi localizado!.\n\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)//caso o usu�rio seja encontrtado 
	{
		printf("\n Essas s�o as informa��es do usu�rio:  ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");// parar o sistema
	fclose(file);//fechar o arquivo consultado 
	
}

int deletar()//Fun��o para excluir um usu�rio existente 
{
	char cpf[40];
	
	printf("Digite o cpf a ser deletado:  ");
	scanf("%s",cpf);
		
	FILE *file; 
	file = fopen(cpf,"r");
	fclose(file);
	
	if(file == NULL)// se o usu�rio n�o for encontrado 
	{
		printf("O usuario n�o se encontra no sistema!.\n");
		system("pause");
	}
	else// Se o usu�rio for encontrado 
	{
		fclose(file);
		remove(cpf);//remove o arquivo do usu�rio 
		printf("O usuario foi excluido!.\n");
		system("pause");
	}
 
 	

	
}

int main()
{
	int opcao=0;//definindo variavel
	int laco=1;
	char senhadigitada []="a";
	int comparacao;
	
	printf("### Cart�rio da EBAC ###\n\n");
	printf("Digite a sua senha de adminstrador!!\n\n Digite a sua senha:");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0)//Se a senha for admin o sistema rodara
	{	
		system ("cls");
		for(laco=1;laco=1;)
		{
		
			  system("cls");
	
    		  setlocale(LC_ALL,"Portuguese");//definindo linguagem
 	
      	 	printf("### Cart�rio da EBAC ###\n\n");//inicio menu
    		printf("Escolha a op��o do menu:\n\n");
    		printf("\t1 -Registrar Nomes\n");
    		printf("\t2 -Consultar Nomes\n");
    		printf("\t3 -Deletar Nomes\n");
    		printf("\t4 -Sair do sofwere \n");
    		printf("\n\n  OP��O: ");//fIM DO MENU
 	
    		scanf("%d", &opcao);//armazenando escolha do usuario
	
    		system("cls");
    		switch(opcao)//inicio da sele��o
    		{
    		
    			case 1:
    			registro();
    			break;
    		
    			case 2:
    			consulta();
				break;
			
				case 3:
				deletar();
				break;
			
				case 4:
				printf("\n\n obrigado por utilizar o SRNAF (Sistema de Registro de Nomes de Alunos e Funcionarios)\n\n");
				return 0;
				break;	
		
			
				default:
				printf("\n\n essa op��o n�o esta disponivel!\n\n");
    			system("pause");
				break;
				
       	 	 }
		}
	}
	
	else
		printf("\nsenha incorreta!!\n");
}
