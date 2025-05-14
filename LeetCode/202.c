bool isHappy(int n) {

    int *somas = malloc(sizeof(int) * 2);
    int j = 0;
    somas[0] = 0;
    somas[1] = n;
    
    while ( somas[j]!= 1){

        int numberSize = snprintf(NULL, 0, "%d", n);
        if (numberSize == 1 ){
            if ( n == 1 || n == 7 ){
                return true;
            }
            return false;
        }
        char *strn = malloc( numberSize + 1);
        sprintf( strn , "%d", n);
        int *digitos = malloc(numberSize * sizeof(int));

        n = 0;

        for ( int i = 0; i < numberSize; i++){
            digitos[i] = strn[i] - '0';
            n += digitos[i] * digitos[i];
        }
        j++;
        somas = realloc( somas, sizeof(int) * (j + 1) );
        somas[j] = n;

        for( int i = 1; i < j; i++ ){
            if ( somas[i] == somas[i-1]){
                return false;
            }
        }
    }
    
    return true;
}