#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int top;
    int score;
    char *word;
} MyStack;

int TestCaseX(MyStack *obj, char *s, int x, int y) {
    int sIndex = 0;
    int slen = strlen(s);

    while (sIndex < slen) {
        char curr = s[sIndex];

        if (obj->top > 0 && obj->word[obj->top - 1] == 'a' && curr == 'b') {
            obj->top--;
            obj->score += x;
        } else {
            obj->word[obj->top] = curr;
            obj->top++;
        }
        sIndex++;
    }

    MyStack *tempStack = (MyStack *)malloc(sizeof(MyStack));
    tempStack->word = malloc(sizeof(char) * slen);
    tempStack->top = 0;
    tempStack->score = obj->score;

    for (int i = 0; i < obj->top; i++) {
        char curr = obj->word[i];

        if (tempStack->top > 0 && tempStack->word[tempStack->top - 1] == 'b' && curr == 'a') {
            tempStack->top--;
            tempStack->score += y;
        } else {
            tempStack->word[tempStack->top] = curr;
            tempStack->top++;
        }
    }

    int score = tempStack->score;
    free(tempStack->word);
    free(tempStack);

    return score;
}

int TestCaseY(MyStack *obj, char *s, int x, int y) {
    int sIndex = 0;
    int slen = strlen(s);

    while (sIndex < slen) {
        char curr = s[sIndex];

        if (obj->top > 0 && obj->word[obj->top - 1] == 'b' && curr == 'a') {
            obj->top--;
            obj->score += y;
        } else {
            obj->word[obj->top] = curr;
            obj->top++;
        }
        sIndex++;
    }

    MyStack *tempStack = (MyStack *)malloc(sizeof(MyStack));
    tempStack->word = malloc(sizeof(char) * slen);
    tempStack->top = 0;
    tempStack->score = obj->score;

    for (int i = 0; i < obj->top; i++) {
        char curr = obj->word[i];

        if (tempStack->top > 0 && tempStack->word[tempStack->top - 1] == 'a' && curr == 'b') {
            tempStack->top--;
            tempStack->score += x;
        } else {
            tempStack->word[tempStack->top] = curr;
            tempStack->top++;
        }
    }

    int score = tempStack->score;
    free(tempStack->word);
    free(tempStack);

    return score;
}

int maximumGain(char *s, int x, int y) {
    int slen = strlen(s);
    MyStack *stack = (MyStack *)malloc(sizeof(MyStack));
    stack->word = malloc(sizeof(char) * slen);
    stack->top = 0;
    stack->score = 0;

    int score;
    if (x > y) {
        score = TestCaseX(stack, s, x, y);
    } else {
        score = TestCaseY(stack, s, x, y);
    }

    free(stack->word);
    free(stack);

    return score;
}

int main() {
    char s1[] = "cdbcbbaaabab";
    int x1 = 4;
    int y1 = 5;
    int result1 = maximumGain(s1, x1, y1);
    printf("Resultado 1: %d\n", result1); // Esperado: 19

    char s2[] = "aabbaaxybbaabb";
    int x2 = 5;
    int y2 = 4;
    int result2 = maximumGain(s2, x2, y2);
    printf("Resultado 2: %d\n", result2);

    char s3[] = "ababbab";
    int x3 = 10;
    int y3 = 20;
    int result3 = maximumGain(s3, x3, y3);
    printf("Resultado 3: %d\n", result3);

    return 0;
}

//gcc -g ..\leetcode1717.c -o leetcode1717.exe
//drmemory -ignore_kernel -- ./leetcode1717.exe 