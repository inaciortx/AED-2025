char findTheDifference(char* s, char* t) {

    bool find = false;
    int i = 0;
    
    for ( i = 0; t[i] != '\0'; i++ ) {
        for ( int j = 0; s[j] != '\0'; j++ ) {
            if ( t[i] == s[j] ) {
                s[j] = '*';
                find = true;
                break;
            } else {
                find = false;
            }
            
        }
        if ( !find ) {
            return t[i];
        }

    }

    return t[i];

}