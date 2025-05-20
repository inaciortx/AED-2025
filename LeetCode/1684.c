int countConsistentStrings(char * allowed, char ** words, int wordsSize){

    int are_consistent = 0;
    
    for ( int i = 0; i < wordsSize; i++ ) {
        int charcmp = 0;
        for ( int j = 0; j < strlen(words[i]); j++ ) {
            for ( int k = 0; k < strlen(allowed); k++ ) {
                if ( allowed[k] == words[i][j] ){
                    charcmp++;
                }
            }    
        }
        if ( charcmp == strlen(words[i]) ){
            are_consistent++;
        }
        
    }

    return are_consistent;
}