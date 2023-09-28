#include <stdio.h> //biblioteca de comunicação com o usuario
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() //função responsável por cadastrar os usuários no sistema
{
	
	//inicio criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final criação de variáveis/string
	
	printf("POR GENTILEZA, DIGITE O CPF A SER CADASTRADO: \n"); //coletando informação do usuário.
	scanf("%s", &cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //resposnável por copiar o valor das stirng
	FILE *file; //cria o arquivo
	
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file, cpf);//salva o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,", ");
	fclose(file);
	
	printf("DIGITE O NOME A SER CADASTRADO: ");
	scanf("%s",&nome);
	
	file = fopen(arquivo, "a"); // irá salvar o arquivo
	fprintf(file, nome); 
	fprintf(file,", "); //serve para separar os arquivos na hora de consultá-lo
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
	setlocale(LC_ALL, "Portuguese");//definição da linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("DIGITE O CPF A SER CONSULTADO: ");
	scanf("%s",cpf); //%s se refere a string
	
	FILE *file; //selecionar a pasta do arquivo
	file = fopen(cpf,"r"); //selecionar para abrir o arquivo,no caso, "r" de read
	
	if(file == NULL) // se for ventura não tiver o arquivo, o sistema irá apontar que não existe.
	{
	 printf ("O ARQUIVO NÃO FOI LOCALIZADO!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	
	{
		printf("\nESSAS SÃO AS INFORMAÇÕES DO USUÁRIO: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system ("pause");
	
}
int deletar()
{
	char cpf[40];
	
	printf("DIGITE O CPF DO USUÁRIO A SER DELETADO: ");
	scanf("%s",cpf);
	
	remove (cpf);
	
	FILE *file; //seleção do arquivo
	file = fopen(cpf,"r"); //abra o arquivo com o CPF na descrição
	
	if (file == NULL)
	
	{	
	printf ("O USUÁRIO NÃO SE ENCONTRA NO SISTEMA, POIS ELE FOI DELETADO COM SUCESSO! \n");
	system("pause");
	}
		
}

int main()
{
	int opcao=0;//definição das variáveis
	int laco=1;
	
	for (laco=1;laco=1;)
	{
		
		system ("cls");
    	setlocale(LC_ALL, "Portuguese");//definição da linguagem
	
	
	 printf("## Escritório do Marcelo ##\n\n\n");//início do menu
	 printf("Escolha a opção desejada do menu:\n\n");
	 printf ("\t1 - Registrar nomes\n\n");
	 printf ("\t2 - Consultar nomes\n\n");
	 printf ("\t3 - Deletar nomes \n\n");
	 printf ("\t4 -Sair do sistema\n\n");
	 printf ("Opção: "); //final do menu
	
	 scanf("%d", &opcao); //armazenando a escolha do usuário
	
	 system("cls"); //responsável por limpar a tela
	 
	 switch (opcao) //início da seleção //inicio da seleção do menu
	 {
	 	case 1:
	 	registro(); //chamada de funções
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
		printf("ESSA OPÇÃO NÃO ESTÁ DISPONÍVEL!\n");
		system ("pause");
		break;	

	} //fim da seleção
}
}
