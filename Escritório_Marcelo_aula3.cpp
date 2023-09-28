#include <stdio.h> //biblioteca de comunica��o com o usuario
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() //fun��o respons�vel por cadastrar os usu�rios no sistema
{
	
	//inicio cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final cria��o de vari�veis/string
	
	printf("POR GENTILEZA, DIGITE O CPF A SER CADASTRADO: \n"); //coletando informa��o do usu�rio.
	scanf("%s", &cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //resposn�vel por copiar o valor das stirng
	FILE *file; //cria o arquivo
	
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file, cpf);//salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,", ");
	fclose(file);
	
	printf("DIGITE O NOME A SER CADASTRADO: ");
	scanf("%s",&nome);
	
	file = fopen(arquivo, "a"); // ir� salvar o arquivo
	fprintf(file, nome); 
	fprintf(file,", "); //serve para separar os arquivos na hora de consult�-lo
	fclose(file);
	
	printf("DIGITE	 O SOBRENOME A SER CADASTRADO: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fprintf(file,", ");
	fclose(file);
	
	printf("DIGITE O CARGO A SER CADASTRADO: ");
	scanf ("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
		
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");//defini��o da linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("DIGITE O CPF A SER CONSULTADO: ");
	scanf("%s",cpf); //%s se refere a string
	
	FILE *file; //selecionar a pasta do arquivo
	file = fopen(cpf,"r"); //selecionar para abrir o arquivo,no caso, "r" de read
	
	if(file == NULL) // se for ventura n�o tiver o arquivo, o sistema ir� apontar que n�o existe.
	{
	 printf ("O ARQUIVO N�O FOI LOCALIZADO!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	
	{
		printf("\nESSAS S�O AS INFORMA��ES DO USU�RIO: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system ("pause");
	
}
int deletar()
{
	char cpf[40];
	
	printf("DIGITE O CPF DO USU�RIO A SER DELETADO: ");
	scanf("%s",cpf);
	
	remove (cpf);
	
	FILE *file; //sele��o do arquivo
	file = fopen(cpf,"r"); //abra o arquivo com o CPF na descri��o
	
	if (file == NULL)
	
	{	
	printf ("O USU�RIO N�O SE ENCONTRA NO SISTEMA, POIS ELE FOI DELETADO COM SUCESSO! \n");
	system("pause");
	}
		
}

int main()
{
	int opcao=0;//defini��o das vari�veis
	int laco=1;
	
	for (laco=1;laco=1;)
	{
		
		system ("cls");
    	setlocale(LC_ALL, "Portuguese");//defini��o da linguagem
	
	
	 printf("## Escrit�rio do Marcelo ##\n\n\n");//in�cio do menu
	 printf("Escolha a op��o desejada do menu:\n\n");
	 printf ("\t1 - Registrar nomes\n\n");
	 printf ("\t2 - Consultar nomes\n\n");
	 printf ("\t3 - Deletar nomes \n\n");
	 printf ("\t4 -Sair do sistema\n\n");
	 printf ("Op��o: "); //final do menu
	
	 scanf("%d", &opcao); //armazenando a escolha do usu�rio
	
	 system("cls"); //respons�vel por limpar a tela
	 
	 switch (opcao) //in�cio da sele��o //inicio da sele��o do menu
	 {
	 	case 1:
	 	registro(); //chamada de fun��es
		break;
		
		case 2:
		consulta();
		break;
		
		case 3:
		deletar();
		break;
		
		case 4:
		printf("Obrigado por utilizar o sistema!\n");
		return 0;
		break;
		
		default:
		printf("ESSA OP��O N�O EST� DISPON�VEL!\n");
		system ("pause");
		break;	

	} //fim da sele��o
}
}
