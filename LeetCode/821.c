/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* shortestToChar(char* s, char c, int* returnSize) {
    
    *returnSize = strlen(s);
    int *shortdistances = (int *)malloc((*returnSize)*sizeof(int));
    int distance , i, j;

    for ( i = 0; i < *returnSize; i++ ) {
        shortdistances[i] = -1;
        for ( j = 0; j < *returnSize; j++ ) {
            if ( s[j] == c ) {
                distance = (i - j);
                if ( shortdistances[i] > abs(distance) || shortdistances[i] == -1) {
                    shortdistances[i] = abs(distance);
                }
            }  
        }
    }
    return shortdistances;
}