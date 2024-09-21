//Headers
#include <stdio.h>  

//Variáveis globais
int acertou = 0; //Variável para verificar se o jogador acertou a palavra
int enforcado = 0; //Variável para verificar se o jogador foi enforcado

//Função para imprimir a forca
void ImprimirForca(int tentativa)
{
	switch (tentativa)
	{
	case 0:
		//Imprimindo o cabeçalho do jogo  
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
		//Imprimindo o cabeçalho do jogo  
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
		//Imprimindo o cabeçalho do jogo  
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
		//Imprimindo o cabeçalho do jogo  
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
		//Imprimindo o cabeçalho do jogo  
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
		//Imprimindo o cabeçalho do jogo  
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
	return;
}

//Função para o jogador chutar uma letra
char Chutar()
{
	//Declarando variáveis
	char letraDigitada = NULL; //Letra que o jogador irá digitar

	//Pede para usuário chutar uma letra
	printf_s("Chute uma letra: ");
	scanf_s(" %c", &letraDigitada);
	letraDigitada = toupper(letraDigitada);

	return letraDigitada;
}

//Função de loop do jogo
void IniciarJogo(char palavraSorteada[], int tamanhoPalavraSorteada, int tentativa)
{
	//Declarando variáveis
	char palavraDigitada[200]; //Palavra que o jogador irá digitar
	int acertouLetra = 0; //Variável para verificar se o jogador acertou a letra

	palavraDigitada[tamanhoPalavraSorteada] = '\0'; //Adicionando o caractere nulo no final da palavra digitada

	//Iniciando o jogo
	while (!acertou && !enforcado)
	{
		//Declara letraDigitada e recebe valor de Chutar();
		char letraDigitada = Chutar();

		printf("\n\n\n");

		//Loop para verificar chute
		for (int i = 0; i < tamanhoPalavraSorteada; i++)
		{
			//Se a letra digitada for igual a letra da palavra sorteada, a letra digitada é inserida na palavra digitada
			if (palavraSorteada[i] == letraDigitada)
			{
				palavraDigitada[i] = letraDigitada;
				acertouLetra = 1;
			}
		}

		//Se não acertou a letra, incrementa a tentativa
		if (acertouLetra == 0)
			tentativa++;
		else acertouLetra = 0;

		//Chama funcão para imprimir a forca
		ImprimirForca(tentativa);

		for (int i = 0; i < tamanhoPalavraSorteada; i++)
		{
			//Escreve os _ para as letras que ainda não foram digitadas e as letras que já foram digitadas
			if (palavraSorteada[i] == ' ')
				printf_s("   ");
			else if (palavraSorteada[i] == palavraDigitada[i])
				printf_s(" %c ", palavraDigitada[i]);
			else
				printf_s(" _ ");

			//Se espaço, mantém espaço
			if (palavraSorteada[i] == ' ') palavraDigitada[i] = ' ';
		}

		//Verifica se o jogador acertou a palavra ou se jogador enforcou
		if (strcmp(palavraSorteada, palavraDigitada) == 0) acertou = 1;
		if (tentativa == 5) enforcado = 1;

		printf_s("\n\n");
	}
	return;
}

//Função para imprimir o resultado do jogo
void ResultadoJogo()
{
	//Imprimindo mensagem de vitória ou derrota
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

//Função principal do jogo
int main()
{
	//Declarando variáveis  
	char palavraSorteada[200]; //Palavra que será usada para o jogo
	int tamanhoPalavraSorteada; //Tamanho da palavra sorteada
	int tentativa = 0; //Tentativas do jogador

	sprintf_s(palavraSorteada, sizeof(palavraSorteada), "WHEY PROTEIN"); //Input de palavra temporário
	tamanhoPalavraSorteada = strlen(palavraSorteada); //Calculando o tamanho da palavra sorteada

	//Imprimindo a mensagem de boas vindas e dica
	printf_s("Bem vindo ao Jogo da Forca!\n");
	printf_s("Dica: ANIMAL\n\n");

	//Chama funcão para imprimir a forca pela primeira vez
	ImprimirForca(tentativa);

	//Imprimindo os espaços a serem preenchidos
	for (int i = 0; i < tamanhoPalavraSorteada; i++)
	{
		//Escreve os _ para cada letra da palavra sorteada
		if (palavraSorteada[i] == ' ')
			printf_s("   ");
		else
			printf_s(" _ ");
	}

	//Inicia o loop do jogo
	IniciarJogo(palavraSorteada, tamanhoPalavraSorteada, tentativa);

	ResultadoJogo();

	printf_s("\n\n");

	return 0;
}