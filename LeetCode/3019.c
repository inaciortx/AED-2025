int countKeyChanges(char* s) {
    
    int len = strlen(s);
    int counter = 0;

    for ( int i = 0; i < len - 1; i++ ) {
        if ( abs(s[i] - s[i+1]) != 32 && abs(s[i]) - s[i+1] != 0) {
            counter++;
        }
    }

    return counter;
}