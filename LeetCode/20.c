bool isValid(char* s) {
    int len = 0;
    while (s[len] != '\0') len++;

    char *stack = malloc(sizeof(char) * len);
    int top = 0;

    for (int i = 0; i < len; i++) {
        char c = s[i];
        if (c == '(' || c == '[' || c == '{') {
            stack[top++] = c;
        } else {
            if (top == 0) {
                free(stack);
                return false;  // nada pra fechar
            }
            char last = stack[top - 1];
            if ((c == ')' && last == '(') ||
                (c == ']' && last == '[') ||
                (c == '}' && last == '{')) {
                top--; // fecha corretamente
            } else {
                free(stack);
                return false; // ordem incorreta
            }
        }
    }

    bool result = (top == 0);
    free(stack);
    return result;
}