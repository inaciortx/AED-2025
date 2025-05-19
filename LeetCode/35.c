int searchInsert(int* nums, int numsSize, int target) {

    if ( nums[numsSize-1] < target ){
        return numsSize;
    }

    for (int i = 0; i < numsSize; i++){
        if ( nums[i] == target ) {
            return i;
        }
        else if ( nums[i] > target){
            return i;
        }
    }

    return 0;
}