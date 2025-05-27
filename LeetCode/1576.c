char* modifyString(char* s) {

    char trade = 'a';
    
    for ( int i = 0; s[i] != '\0'; i++) {
        if ( s[i] == '?' ) {
            while (  i > 0 && s[i-1] == trade || s[i+1] == trade && i < strlen(s) ) {
                trade++;
        }
        s[i] = trade;
        trade = 'a';
    }
    }
    return s;

}