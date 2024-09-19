//preciso de um jogo da forca #include <stdio.h>
#include <string.h>

#define MAX_ATTEMPTS 6
#define MAX_WORD_LENGTH 20

void printHangman(int attempts) {
    switch (attempts) {
        case 0:
            printf(" _________     \n");
            printf("|         |    \n");
            printf("|              \n");
            printf("|              \n");
            printf("|              \n");
            printf("|              \n");
            printf("|              \n");
            break;
        case 1:
            printf(" _________     \n");
            printf("|         |    \n");
            printf("|         0    \n");
            printf("|              \n");
            printf("|              \n");
            printf("|              \n");
            printf("|              \n");
            break;
        case 2:
            printf(" _________     \n");
            printf("|         |    \n");
            printf("|         0    \n");
            printf("|         |    \n");
            printf("|              \n");
            printf("|              \n");
            printf("|              \n");
            break;
        case 3:
            printf(" _________     \n");
            printf("|         |    \n");
            printf("|         0    \n");
            printf("|        /|    \n");
            printf("|              \n");
            printf("|              \n");
            printf("|              \n");
            break;
        case 4:
            printf(" _________     \n");
            printf("|         |    \n");
            printf("|         0    \n");
            printf("|        /|\\  \n");
            printf("|              \n");
            printf("|              \n");
            printf("|              \n");
            break;
        case 5:
            printf(" _________     \n");
            printf("|         |    \n");
            printf("|         0    \n");
            printf("|        /|\\  \n");
            printf("|        /     \n");
            printf("|              \n");
            printf("|              \n");
            break;
        case 6:
            printf(" _________     \n");
            printf("|         |    \n");
            printf("|         0    \n");
            printf("|        /|\\  \n");
            printf("|        / \\  \n");
            printf("|              \n");
            printf("|              \n");
            break;
    }
}

void printWord(char word[], int length) {
    for (int i = 0; i < length; i++) {
        printf("%c ", word[i]);
    }
    printf("\n");
}

int main() {
    char secretWord[MAX_WORD_LENGTH];
    char guessedWord[MAX_WORD_LENGTH];
    int attempts = 0;
    int length;

    printf("Enter the secret word: ");
    scanf("%s", secretWord);

    length = strlen(secretWord);

    for (int i = 0; i < length; i++) {
        guessedWord[i] = '_';
    }

    while (attempts < MAX_ATTEMPTS) {
        printf("\n");
        printHangman(attempts);
        printWord(guessedWord, length);

        char guess;
        printf("Enter a letter: ");
        scanf(" %c", &guess);

        int found = 0;
        for (int i = 0; i < length; i++) {
            if (secretWord[i] == guess) {
                guessedWord[i] = guess;
                found = 1;
            }
        }

        if (!found) {
            attempts++;
        }

        int correct = 1;
        for (int i = 0; i < length; i++) {
            if (guessedWord[i] == '_') {
                correct = 0;
                break;
            }
        }

        if (correct) {
            printf("\nCongratulations! You guessed the word: %s\n", secretWord);
            break;
        }
    }

    if (attempts == MAX_ATTEMPTS) {
        printf("\nGame over! You failed to guess the word: %s\n", secretWord);
    }

    return 0;
}
