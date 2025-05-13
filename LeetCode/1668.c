int maxRepeating(char* sequence, char* word) {
    
    int k = 0;
    char *baseWord = word;


    while ( strstr( sequence, word ) ) {
        char *newWord = malloc( strlen(word) + strlen(baseWord) + 1);
        strcpy( newWord , word );
        strcat( newWord, baseWord );
        word = newWord;
        k++;
    }

    return k;
}