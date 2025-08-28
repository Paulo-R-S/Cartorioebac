#include <stdio.h> //Biblioteca de comunicação com usuário
#include <stdlib.h> //Bilbioteca de alocação de espaço em memória
#include <locale.h> //Biblioteca de alocação de texto por região
#include <string.h> //Biblioteca responsável por cuidar das string


int registro () //função responsavel pelo registro de usuario
{
	//inicio criação de variáveis/string
    char arquivo[40];
    char cpf[40];
    char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	
	printf("\n\n Digitar CPF cadrastado:  \n\n");//coletando informação do usuário
	scanf("%s" , cpf );//%s refere-se a string
	
	strcpy(arquivo, cpf); //responsavel por copiar valores das string
	
	FILE *file; //cria arquivo
	file = fopen(arquivo, "w"); //criar arquivo e o 'w' significa escrever
	fprintf(file,cpf); //salvar valor variavel
	fclose(file); //fechar arquivo
	
	file = fopen(arquivo, "a");// "a" abre um arquivo no modo de inclusão
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
	
	system("pause");// para a operação do sistema 
	
	
	
	
	
}

int consulta()//função de busca de usuário
{
	setlocale(LC_ALL,"Portuguese");//definindo linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("\n\n Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file== NULL)//caso o usuário não for encontrado
	{
		printf("\n\n Não foi possivel abrir o arquivo, nao foi localizado!.\n\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)//caso o usuário seja encontrtado 
	{
		printf("\n Essas são as informações do usuário:  ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");// parar o sistema
	fclose(file);//fechar o arquivo consultado 
	
}

int deletar()//Função para excluir um usuário existente 
{
	char cpf[40];
	
	printf("Digite o cpf a ser deletado:  ");
	scanf("%s",cpf);
		
	FILE *file; 
	file = fopen(cpf,"r");
	fclose(file);
	
	if(file == NULL)// se o usuário não for encontrado 
	{
		printf("O usuario não se encontra no sistema!.\n");
		system("pause");
	}
	else// Se o usuário for encontrado 
	{
		fclose(file);
		remove(cpf);//remove o arquivo do usuário 
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
	
	printf("### Cartório da EBAC ###\n\n");
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
 	
      	 	printf("### Cartório da EBAC ###\n\n");//inicio menu
    		printf("Escolha a opção do menu:\n\n");
    		printf("\t1 -Registrar Nomes\n");
    		printf("\t2 -Consultar Nomes\n");
    		printf("\t3 -Deletar Nomes\n");
    		printf("\t4 -Sair do sofwere \n");
    		printf("\n\n  OPÇÃO: ");//fIM DO MENU
 	
    		scanf("%d", &opcao);//armazenando escolha do usuario
	
    		system("cls");
    		switch(opcao)//inicio da seleção
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
				printf("\n\n essa opção não esta disponivel!\n\n");
    			system("pause");
				break;
				
       	 	 }
		}
	}
	
	else
		printf("\nsenha incorreta!!\n");
}
