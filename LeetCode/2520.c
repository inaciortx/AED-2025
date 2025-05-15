int countDigits(int num) {
    
    int *digits = NULL;
    int size = -1; 
    int divisorCount = 0;
    int numtemp = num;

    while ( numtemp != 0 ) {
        size++;
        digits = (int *)realloc(digits, sizeof(int) * (size+1) );
        digits[size] = numtemp % 10;
        numtemp /= 10;

    }

    if ( size == 0 ){
        return 1;
    }

    for ( int i = 0; i <= size; i++ ) {
        if ( num % digits[i] == 0 ) {
            divisorCount++;
        }
    }
       
    return divisorCount;
}

