int calPoints(char** operations, int operationsSize) {

    int top = 0;
    
    int *stack = NULL;

    for ( int i = 0; i < operationsSize ; i++ ){

        stack = realloc( stack, sizeof(int) * (top + 1) );

        if ( operations[i][0] >= '1' && operations[i][0] <= '9' || operations[i][0] == '-') {
            stack[top++] = atoi(operations[i]);
        } else if ( operations[i][0] == 'C' ) {
            top--;
        } else if ( operations[i][0] == 'D' ) {
            if ( top > 0 ) {
                stack[top] = stack[top - 1] * 2;
                top++;
            }
        } else if ( operations[i][0] == '+' ) {
            if ( top > 1) {
                stack[top] = stack[top - 1] + stack[top - 2];
                top++;
            }
        }
    }

    

    int score = 0;

    for ( int i = 0; i < top; i++ ){
        score += stack[i];
    }

    return score;

}