int maximum69Number (int num) {
    
    char *numstring = NULL;

    int numSize = snprintf(NULL, 0, "%d", num );
    numstring = realloc( numstring, numSize + 1 );
    numstring[numSize] = '\0';
    snprintf( numstring, numSize + 1, "%d", num );

    for ( int i = 0; i < numSize; i++ ){
        if ( numstring[i] == '6' ) {
            numstring[i] = '9';
            break;
        }
    }
    num = atoi( numstring );
    return num;

}
