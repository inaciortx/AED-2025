/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    
    int *index = malloc( sizeof(int) * 2 );
    *returnSize = 2;

    for ( int i = 0; i < numsSize - 1; i++ ) {
        for ( int j = i+1; j < numsSize; j++ ) {
            if ( nums[j] + nums[i] == target ) {
                index[0] = j;
                index[1] = i;
                return index;
            }
        }
    }
    return index;
}
