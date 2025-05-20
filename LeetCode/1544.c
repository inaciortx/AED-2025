char* makeGood(char* s) {
    
    int len = strlen(s);
    
    for ( int i = 0; i < len - 1; i++ ){
        if ( abs(s[i] - s[i+1]) == 32 ) {
           char *newstr = malloc(len - 1);
           int k = 0;

           for ( int j = 0; j < len; j++ ){
                if ( j != i && j != i+1 ){
                    newstr[k++] = s[j];
                }
           }
            newstr[k] = '\0';

            char *Goodstring = makeGood(newstr);
            free(newstr);
            return Goodstring;
            }
        }
    return strdup(s);
    }     
