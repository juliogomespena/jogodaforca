#include <stdio.h>  

//Vari�veis globais
int acertou = 0; //Vari�vel para verificar se o jogador acertou a palavra
int enforcado = 0; //Vari�vel para verificar se o jogador foi enforcado

//Fun��o principal do programa
int main()  
{  
	//Declarando vari�veis  
	char palavraSorteada[200]; //Palavra que ser� usada para o jogo
	char palavraDigitada[200]; //Palavra que o jogador ir� digitar
	char letraDigitada = NULL; //Letra que o jogador ir� digitar
	int tamanhoPalavraSorteada; //Tamanho da palavra sorteada
	int tentativa = 0; //Tentativas do jogador
	int acertouLetra = 0; //Vari�vel para verificar se o jogador acertou a letra

	sprintf_s(palavraSorteada, sizeof(palavraSorteada), "ORNITORRINCO"); //Input de palavra tempor�rio
	tamanhoPalavraSorteada = strlen(palavraSorteada); //Calculando o tamanho da palavra sorteada
	palavraDigitada[tamanhoPalavraSorteada] = '\0'; //Adicionando o caractere nulo no final da palavra digitada

	//Imprimindo a mensagem de boas vindas e dica
	printf_s("Bem vindo ao Jogo da Forca!\n");
	printf_s("Dica: ANIMAL\n\n");

	//Chama func�o para imprimir a forca
	ImprimirForca(tentativa);

	//Imprimindo a palavra e os espa�os a serem preenchidos
	for (int i = 0; i < tamanhoPalavraSorteada; i++)
	{
		//Escreve os _ para cada letra da palavra sorteada
		if (palavraSorteada[i] == ' ')
			printf_s("   ");
		else
			printf_s(" _ ");
	}

	printf_s("\n\n");

	//Iniciando o jogo
	while (!acertou && !enforcado)
	{
		//Pede para usu�rio chutar uma letra
		printf_s("Chute uma letra: ");
		scanf_s(" %c", &letraDigitada);
		letraDigitada = toupper(letraDigitada);

		printf("\n\n\n");

		//Imprimindo a palavra e os espa�os a serem preenchidos
		for (int i = 0; i < tamanhoPalavraSorteada; i++)
		{
			//Se a letra digitada for igual a letra da palavra sorteada, a letra digitada � inserida na palavra digitada
			if (palavraSorteada[i] == letraDigitada)
			{
				palavraDigitada[i] = letraDigitada;
				acertouLetra = 1;
			}
			//Se espa�o, mant�m espa�o
			if (palavraSorteada[i] == ' ') palavraDigitada[i] = ' ';
		}

		//Se n�o acertou a letra, incrementa a tentativa
		if (acertouLetra == 0)
			tentativa++;
		else acertouLetra = 0;

		//Chama func�o para imprimir a forca
		ImprimirForca(tentativa);

		for (int i = 0; i < tamanhoPalavraSorteada; i++)
		{
			//Escreve os _ para as letras que ainda n�o foram digitadas e as letras que j� foram digitadas
			if (palavraSorteada[i] == ' ')
				printf_s("   ");
			else if (palavraSorteada[i] == palavraDigitada[i])
				printf_s(" %c ", palavraDigitada[i]);
			else
				printf_s(" _ ");
		}

		//Verifica se o jogador acertou a palavra e se jogador enforcou
		if (strcmp(palavraSorteada, palavraDigitada) == 0) acertou = 1;
		if (tentativa == 5) enforcado = 1;

		printf_s("\n\n");
	}

	if(enforcado == 1)
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
		printf_s("      .-\:      /-.     \n");
		printf_s("     | (|:.     |) |    \n");
		printf_s("      '-|:.     |-'     \n");
		printf_s("        \::.    /       \n");
		printf_s("         '::. .'        \n");
		printf_s("           ) (          \n");
		printf_s("         _.' '._        \n");
		printf_s("        '-------'		  \n");
	}

	return 0;  
}

int ImprimirForca(int tentativa)
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
	return 0;
}