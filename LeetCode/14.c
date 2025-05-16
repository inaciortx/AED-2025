char* longestCommonPrefix(char** strs, int strsSize) {
    
    char *cPrefix = NULL;
    int i, j = 0;

    if ( strsSize == 0){
        cPrefix = malloc(1);
        cPrefix[0] = '\0';
        return cPrefix;
    }
    if ( strsSize == 1) {
        cPrefix = malloc( sizeof(char) * (strlen(strs[0]) + 1) );
        strcpy( cPrefix, strs[0] );
        return cPrefix;
    }

    for (;;){
        i=0;
        while ( i+1 != strsSize && strs[i][j] != '\0' && strs[i+1][j] != '\0' && strs[i][j] == strs[i+1][j] ) {
            i++;
        }
        if ( i+1 != strsSize ){
            break;
        }
        j++;
    }

    cPrefix = malloc(sizeof(char) * (j+1));
    cPrefix[j] = '\0';

    for ( i = 0; i < j; i++ ){
        cPrefix[i] = strs[0][i];
    }

return cPrefix;

}

