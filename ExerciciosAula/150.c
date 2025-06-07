int evalRPN(char** tokens, int tokensSize) {
    
    int *stack = NULL;
    int stackSize = 0;
    int stackIndex = 0;

    for ( int i = 0; i < tokensSize; i++ ) {
        
        if ( tokens[i][0] == '+') {
            stack[stackIndex - 2] = stack[stackIndex - 2] + stack[stackIndex - 1 ];
            stackIndex--;  
        } else if ( strcmp(tokens[i], "-") == 0 ) {
            stack[stackIndex - 2] = stack[stackIndex - 2] - stack[stackIndex - 1 ];
            stackIndex--;  
        } else if ( tokens[i][0] == '*' ) {
            stack[stackIndex - 2] = stack[stackIndex - 2] * stack[stackIndex - 1 ];
            stackIndex--;  
        } else if ( tokens[i][0] == '/' ) {
            stack[stackIndex - 2] = stack[stackIndex - 2] / stack[stackIndex - 1 ];
            stackIndex--;  
        } else {
            stack = realloc(stack, sizeof(int) * (stackSize + 1) );
            stack[stackIndex] = atoi(tokens[i]);
            stackSize++;
            stackIndex++;
        }
    }
    int answer = stack[0];
    free(stack);
    return answer;
}