int maxOperations(int* nums, int numsSize) {
    
    int op = 0;
    int score = nums[0]+ nums[1];
    
    for ( int i = 0; i < numsSize - 1; i++ ) {
        if ( nums[i] + nums[i+1] == score ) {
            i++;
            op++;
        }
        else if ( nums[i] + nums[i+1] != score ) {
            break;
        }
    }

    return op;
}