int finalValueAfterOperations(char** operations, int operationsSize) {
    
    int X = 0;
    
    for ( int i = 0; i < operationsSize; i++ ){
        if ( ( strcmp("X++", operations[i]) == 0) || (strcmp("++X", operations[i]) == 0) ){
            X++;
        } else {
            X--;
        }
    }
    return X;

}