/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findPeaks(int* mountain, int mountainSize, int* returnSize) {
    
    int *peaks = NULL;
    *returnSize = 0;
    int j = 0;

    for ( int i = 1; i < mountainSize - 1; i++ ){

        if ( mountain[i] > mountain[i-1] && mountain[i] > mountain[i+1] ){
            (*returnSize)++;
            peaks = realloc( peaks, (*returnSize) * sizeof(int) );
            peaks[j] = i;
            j++;
        }
    }
    return peaks;
}