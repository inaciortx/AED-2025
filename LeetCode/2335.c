int fillCups(int* amount, int amountSize) {
    
    int temp = 0;
    int sec = 0;

    while ( amount[0] > 0 || amount[1] > 0 || amount[2] > 0 ) {

        if ( amount[0] > amount[2] ){
            temp = amount[0];
            amount[0] = amount[2];
            amount[2] = temp;
        }
        if( amount[0] > amount[1] ) { 
            temp = amount[0];
            amount[0] = amount[1];
            amount[1] = temp;
        }
        amount[2]--;
        amount[1]--;
        sec++;
    }

    return sec;
}