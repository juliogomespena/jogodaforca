//Headers
#include <stdio.h>
#include "forca.h"
#include <string.h>

//Fun��o principal do jogo
int main()
{
	int jogarNovamente = 1; //Vari�vel para verificar se o jogador quer jogar novamente

	while (jogarNovamente)
	{
		//Declarando vari�veis  
		char palavraSorteada[200] = { 0 }; //Palavra que ser� usada para o jogo
		int tamanhoPalavraSorteada; //Tamanho da palavra sorteada
		char palavraDigitada[200] = { 0 }; // Palavra que o jogador ir� digitar
		int tentativa = 0; //Tentativas do jogador
		char dica[200] = { 0 }; //Dica para o jogador

		//Sorteando a palavra
		SortearPalavra(palavraSorteada, dica);
		tamanhoPalavraSorteada = strlen(palavraSorteada); //Calculando o tamanho da palavra sorteada
		palavraDigitada[tamanhoPalavraSorteada] = '\0'; // Adicionando o caractere nulo no final da palavra digitada

		//Imprimindo a mensagem de boas vindas e dica
		printf_s("Bem vindo ao Jogo da Forca!\n");
		printf_s("Dica: %s\n\n", dica);

		//Chama func�o para imprimir a forca pela primeira vez
		ImprimirForca(palavraSorteada, palavraDigitada, tamanhoPalavraSorteada, tentativa);

		//Inicia o jogo
		IniciarJogo(palavraSorteada, palavraDigitada, tamanhoPalavraSorteada, tentativa);

		printf_s("\n\n");

		printf_s("Deseja jogar novamente? 0 - NAO / 1 - SIM: ");
		scanf_s("%d", &jogarNovamente);

		printf_s("\n\n");
	}

	return 0;
}

//Fun��o para sortear a palavra
void SortearPalavra(char* palavraSorteada[], char* dica)
{
	//Declarando vari�veis
	int qtdPalavras = 0; //Quantidade de palavras no arquivo
	FILE* arquivoPalavras; //Ponteiro para o arquivo de palavras
	errno_t err = fopen_s(&arquivoPalavras, "palavras.txt", "r"); //Abrindo o arquivo de palavras

	//Verificando se o arquivo foi aberto corretamente
	if (err != 0)
	{
		printf_s("Erro ao abrir o arquivo de palavras!\n");
		exit(1);
	}
	else
	{
		srand(time(NULL)); //Iniciando a semente para o rand

		//Contando quantidade de palavras
		while (!feof(arquivoPalavras))
		{
			char ch = fgetc(arquivoPalavras);
			if (ch == '\n')
			{
				qtdPalavras++;
			}
		}

		rewind(arquivoPalavras); //Voltando o ponteiro para o in�cio do arquivo

		int indiceSorteado = rand() % qtdPalavras; //Sorteando um �ndice para a palavra

		for (int i = 0; i <= indiceSorteado; i++)
		{
			char linha[200]; //Linha do arquivo
			fgets(linha, 200, arquivoPalavras); // Lendo a linha sorteada

			//Separando a palavra da dica
			char* nextTk = NULL; //Token para receber dica
			char* tk = strtok_s(linha, "/", &nextTk); //Token para receber a palavra
			//Se token da palavra n�o for nulo
			if (tk != NULL)
			{
				//Copia token da palavra para a vari�vel palavraSorteada
				strcpy_s(palavraSorteada, 200, tk);
				//Token da dica recebe dia
				nextTk = strtok_s(NULL, "/", &nextTk);
				//Se dica n�o for nula
				if (tk != NULL)
				{
					//Copia valor do token da dica para vari�vel de dica
					strcpy_s(dica, 200, nextTk);
				}
			}
		}
	}
	fclose(arquivoPalavras); //Fechando o arquivo de palavras
}

//Fun��o para imprimir a forca
void ImprimirForca(char palavraSorteada[], char palavraDigitada[], int tamanhoPalavraSorteada, int tentativa)
{
	switch (tentativa)
	{
		case 0:
			//Imprimindo o cabe�alho do jogo  
			printf_s("/*************************/\n");
			printf_s("/***** Jogo da Forca *****/\n");
			printf_s("/*************************/\n");
			printf_s("					\n");
			printf_s("  _______			\n");
			printf_s(" |/      |		\n");
			printf_s(" |				\n");
			printf_s(" |				\n");
			printf_s(" |				\n");
			printf_s(" |				\n");
			printf_s(" |				\n");
			printf_s("_|________	");
			break;
		case 1:
			//Imprimindo o cabe�alho do jogo  
			printf_s("/*************************/\n");
			printf_s("/***** Jogo da Forca *****/\n");
			printf_s("/*************************/\n");
			printf_s("					\n");
			printf_s("  _______			\n");
			printf_s(" |/      |		\n");
			printf_s(" |      (_)       \n");
			printf_s(" |				\n");
			printf_s(" |				\n");
			printf_s(" |				\n");
			printf_s(" |			    \n");
			printf_s("_|________	");
			break;
		case 2:
			//Imprimindo o cabe�alho do jogo  
			printf_s("/*************************/\n");
			printf_s("/***** Jogo da Forca *****/\n");
			printf_s("/*************************/\n");
			printf_s("					\n");
			printf_s("  _______			\n");
			printf_s(" |/      |		\n");
			printf_s(" |      (_)		\n");
			printf_s(" |	\\|/		\n");
			printf_s(" |		\n");
			printf_s(" |		\n");
			printf_s(" |        \n");
			printf_s("_|________	");
			break;
		case 3:
			//Imprimindo o cabe�alho do jogo  
			printf_s("/*************************/\n");
			printf_s("/***** Jogo da Forca *****/\n");
			printf_s("/*************************/\n");
			printf_s("					\n");
			printf_s("  _______			\n");
			printf_s(" |/      |		\n");
			printf_s(" |      (_)		\n");
			printf_s(" |	\\|/		\n");
			printf_s(" |	 |		\n");
			printf_s(" |			\n");
			printf_s(" |          \n");
			printf_s("_|________	");
			break;
		case 4:
			//Imprimindo o cabe�alho do jogo  
			printf_s("/*************************/\n");
			printf_s("/***** Jogo da Forca *****/\n");
			printf_s("/*************************/\n");
			printf_s("					\n");
			printf_s("  _______			\n");
			printf_s(" |/      |		\n");
			printf_s(" |      (_)		\n");
			printf_s(" |	\\|/		\n");
			printf_s(" |	 |		\n");
			printf_s(" |	/ \\		\n");
			printf_s(" |          \n");
			printf_s("_|________	");
			break;
		case 5:
			//Imprimindo o cabe�alho do jogo  
			printf_s("/*************************/\n");
			printf_s("/***** Jogo da Forca *****/\n");
			printf_s("/*************************/\n");
			printf_s("					\n");
			printf_s("  _______			\n");
			printf_s(" |/      |		\n");
			printf_s(" |      (_)		\n");
			printf_s(" |	\\|/		\n");
			printf_s(" |	 |		\n");
			printf_s(" |	/ \\		\n");
			printf_s(" |     /   \\      \n");
			printf_s("_|________	");
			break;
		default:
			break;
	}

	//Escreve os espa�os e as letras j� advinhadas
	for (int i = 0; i < tamanhoPalavraSorteada; i++)
	{
		// Se espa�o, mant�m espa�o
		if (palavraSorteada[i] == ' ') palavraDigitada[i] = ' ';

		// Escreve os _ para as letras que ainda n�o foram digitadas e as letras que j� foram digitadas
		if (palavraSorteada[i] == ' ')
			printf_s("   ");
		else if (palavraSorteada[i] == palavraDigitada[i])
			printf_s(" %c ", palavraDigitada[i]);
		else
			printf_s(" _ ");
	}

	return;
}

//Fun��o para o jogador chutar uma letra
char Chutar()
{
	//Declarando vari�veis
	char letraDigitada = NULL; //Letra que o jogador ir� digitar

	//Pede para usu�rio chutar uma letra
	printf_s("Chute uma letra: ");
	scanf_s(" %c", &letraDigitada);
	letraDigitada = toupper(letraDigitada);

	return letraDigitada;
}

// Fun��o para verificar chute
int VerificarChute(char palavraSorteada[], char palavraDigitada[], char letraDigitada, int tamanhoPalavraSorteada, int* tentativa)
{
	int acertouLetra = 0; // Vari�vel para verificar se o jogador acertou a letra

	// Loop para verificar chute
	for (int i = 0; i < tamanhoPalavraSorteada; i++)
	{
		// Se a letra digitada for igual a letra da palavra sorteada, a letra digitada � inserida na palavra digitada
		if (palavraSorteada[i] == letraDigitada)
		{
			palavraDigitada[i] = letraDigitada;
			acertouLetra = 1;
		}
	}

	// Se n�o acertou a letra, incrementa a tentativa
	if (acertouLetra == 0)
		(*tentativa)++; //Incrementa endere�o de mem�ria da tentativa na fun��o IniciarJogo
	else acertouLetra = 0;

	return acertouLetra;
}

//Fun��o para imprimir o resultado do jogo
void ResultadoJogo(int acertou, int enforcado)
{
	//Imprimindo mensagem de vit�ria ou derrota
	if (enforcado == 1)
	{
		printf_s("Voce foi enforcado!\n\n");
		printf_s("    _______________         \n");
		printf_s("   /               \\        \n");
		printf_s("  /                 \\      \n");
		printf_s("//                   \\/\\    \n");
		printf_s("\\|   XXXX     XXXX   | /    \n");
		printf_s(" |   XXXX     XXXX   |/     \n");
		printf_s(" |   XXX       XXX   |      \n");
		printf_s(" |                   |      \n");
		printf_s(" \\__      XXX      __/      \n");
		printf_s("   |\\     XXX     /|        \n");
		printf_s("   | |           | |        \n");
		printf_s("   | I I I I I I I |        \n");
		printf_s("   |  I I I I I I  |        \n");
		printf_s("   \\_             _/        \n");
		printf_s("     \\_         _/          \n");
		printf_s("       \\_______/			  \n");
	}
	else if (acertou == 1)
	{
		printf_s("Voce acertou!\n\n");
		printf_s("       ___________      \n");
		printf_s("      '._==_==_=_.'     \n");
		printf_s("      .-\\:      /-.     \n");
		printf_s("     | (|:.     |) |    \n");
		printf_s("      '-|:.     |-'     \n");
		printf_s("        \\::.    /       \n");
		printf_s("         '::. .'        \n");
		printf_s("           ) (          \n");
		printf_s("         _.' '._        \n");
		printf_s("        '-------'		  \n");
	}
}

// Fun��o de loop do jogo
void IniciarJogo(char palavraSorteada[], char palavraDigitada[], int tamanhoPalavraSorteada, int tentativa)
{
	// Declarando vari�veis
	int acertou = 0; //Vari�vel para verificar se o jogador acertou a palavra
	int enforcado = 0; //Vari�vel para verificar se o jogador foi enforcado
	int acertouLetra = 0; // Vari�vel para verificar se o jogador acertou a letra

	printf_s("\n\n");

	// Iniciando o jogo
	while (!acertou && !enforcado)
	{
		// Declara letraDigitada e recebe valor de Chutar();
		char letraDigitada = Chutar();

		printf("\n\n\n");

		// Verifica chute
		acertouLetra = VerificarChute(palavraSorteada, palavraDigitada, letraDigitada, tamanhoPalavraSorteada, &tentativa);

		// Chama func�o para imprimir a forca
		ImprimirForca(palavraSorteada, palavraDigitada, tamanhoPalavraSorteada, tentativa);

		// Verifica se o jogador acertou a palavra ou se jogador enforcou
		if (strcmp(palavraSorteada, palavraDigitada) == 0) acertou = 1;
		if (tentativa == 5) enforcado = 1;

		printf_s("\n\n");
	}
	ResultadoJogo(acertou, enforcado);
	return;
}