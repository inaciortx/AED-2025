bool lemonadeChange(int* bills, int billsSize) {
    
    int wallet[2] = {0};

    for ( int i = 0; i < billsSize; i++ ) {
        if (bills[i] < 20){
        wallet[(bills[i]/5)-1] += bills[i];
        }
        if ( bills[i] == 10 ) {
            wallet[0] -=5 ;
            
        }
        if ( bills[i] == 20 ){
            wallet[0] -= 5;
            if( wallet[1] > 0){
            wallet[1] -= 10;
            } else{
                wallet[0] -= 10;
            }
        }
        if ( wallet[0] < 0 || wallet[1] < 0) {
            return false;
        }
    }
        
    return true;
}