#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* shortestCompletingWord(char* licensePlate, char** words, int wordsSize);

int main() {
    char licensePlate[] = "1s3 PSt";

    // Lista de palavras
    char* words[] = {"step", "steps", "stripe", "stepple"};
    int wordsSize = sizeof(words) / sizeof(words[0]);

    // Chama a função
    char* result = shortestCompletingWord(licensePlate, words, wordsSize);

    // Imprime o resultado
    if (result != NULL) {
        printf("A menor palavra que completa a placa é: %s\n", result);
        free(result);  // Liberar a memória alocada dinamicamente
    } else {
        printf("Nenhuma palavra completa a placa.\n");
    }

    return 0;
}

char* shortestCompletingWord(char* licensePlate, char** words, int wordsSize) {
    
    char *characters = malloc( sizeof(char) * 1);
    int llen = strlen(licensePlate);
    characters[0] = '\0';
    int clen = 1;
    int k = 0;


    for ( int i = 0; i < llen; i++ ) {

        if ( (tolower(licensePlate[i]) >= 97) && (tolower(licensePlate[i]) <= 122) ) {
            characters = realloc( characters, sizeof(char) * clen + 1 );
            characters[clen] = '\0';
            characters[k] = tolower(licensePlate[i]);
            k++;
            clen++;
        }

    }

    char *chartemp = malloc( (sizeof(char) * clen) + 1 );

    int len = strlen(words[0]);

    char *smallword = NULL; 
    
    clen = strlen(characters);

    for ( int i = 0; i < wordsSize; i++ ) {
        
        strcpy ( chartemp , characters);
        int finded = 0;

        for ( int j = 0; words[i][j] != '\0'; j++ ) {

            for ( k = 0; chartemp[k] != '\0'; k++ ){

                if ( words[i][j] == chartemp[k] ){
                    finded++;
                    chartemp[k] = '*';
                    break;
                }
            }
        }
            if ( finded == clen && ( smallword == NULL || (strlen(words[i]) < strlen(smallword)) ) ) {
                    smallword = realloc( smallword, sizeof(char) * strlen(words[i]) + 1 );
                    strcpy( smallword, words[i]);
                }
    }

    free(chartemp);
    free(characters);

    return smallword;
}
