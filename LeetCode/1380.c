/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* luckyNumbers(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    
    int *luckyNum = NULL;
    int lowerNum = 0;
    int tempj = 0;
    int tempi = 0;
    int notlucky = 0;
    int j = 0;
    *returnSize = 0;

    for ( int i = 0; i < matrixSize; i++ ){
        notlucky = 0;
        lowerNum = matrix[i][0];
        
        for( j = 0; j < *matrixColSize; j++ ){
            if ( matrix[i][j] < lowerNum){
                lowerNum = matrix[i][j];
                tempj = j;
                tempi = i;
            }
        }
        for ( int k = 0; k < matrixSize; k++ ){
            if ( matrix[k][tempj] > lowerNum){
                notlucky++;
                break;
            } 
        }
        if ( notlucky == 0){
            (*returnSize)++;
            luckyNum = realloc(luckyNum, sizeof(int) * (*returnSize) );
            luckyNum[*returnSize-1] = lowerNum;
        }
       
    }
    return luckyNum;
}