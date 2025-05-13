/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getSneakyNumbers(int* nums, int numsSize, int* returnSize) {

    int *sneakyNumbers = ( int * )malloc( sizeof(int) * 2);
    *returnSize = 2;
    int c = 0;

    for( int i = 0; i <  numsSize; i++ ) {
        for ( int j = i+1; j < numsSize; j++ ) {
            if( nums[i] == nums[j]){
                sneakyNumbers[c] = nums[i];
                c++;
            }
        }
    }

    return sneakyNumbers;
    
}