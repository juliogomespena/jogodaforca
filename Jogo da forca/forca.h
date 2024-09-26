//Headers
#include <stdio.h>
#include <string.h>

//Constantes
#define TAMANHO_STRING 200
#define MAX_TENTATIVAS 10

//Declaração de funções
void SortearPalavra(char* palavraSorteada[], char* dica[]);
void ImprimirForca(char palavraSorteada[], char palavraDigitada[], int tamanhoPalavraSorteada, int tentativa, char dica[]);
char Chutar();
int VerificarChute(char palavraSorteada[], char palavraDigitada[], char letraDigitada, int tamanhoPalavraSorteada, int* tentativa);
void ResultadoJogo(char palavraSorteada[], int acertou, int enforcado);
void IniciarJogo(char palavraSorteada[], char palavraDigitada[], int tamanhoPalavraSorteada, int tentativa, char dica[]);
void AdicionarPalavra();