void SortearPalavra(char* palavraSorteada[], char* dica[]);
void ImprimirForca(char palavraSorteada[], char palavraDigitada[], int tamanhoPalavraSorteada, int tentativa);
char Chutar();
int VerificarChute(char palavraSorteada[], char palavraDigitada[], char letraDigitada, int tamanhoPalavraSorteada, int* tentativa);
void ResultadoJogo(int acertou, int enforcado);
void IniciarJogo(char palavraSorteada[], char palavraDigitada[], int tamanhoPalavraSorteada, int tentativa);
void AdicionarPalavra();