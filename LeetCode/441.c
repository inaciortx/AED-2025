int arrangeCoins(int n) {
    
    int used_coins = 1, complete_row = 0;
    do {
        n -= used_coins;
        used_coins++;
        complete_row++;

    } while ( n >= used_coins );

    return complete_row;
}