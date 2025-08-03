long long fatorial ( long long num ) {

    if ( num == 1 ){ 
        return 1;
    }
    if ( num == 0 ) {
        return 1;
    }
    return num * fatorial( num - 1 );
}

long long numOfWays( int* nums, long long numsSize) {
    
    int root = nums[0];
    long long output = 0;
    long long left = 0, right = 0;

    for ( int i = 1; i < numsSize; i++ ) {

        if ( nums[i] > root ) {
            right++;
        }
        if ( nums[i] < root ) {
            left++;
        }

    }
    if ( left == 0 ) {
        return 0;
    }
    if ( right == 0 ) {
        return 0;
    }
    if ( numsSize - 1 == 0) {
        return 0;
    }

    long long m = fatorial( numsSize - 1 );

    if ( left == right ) {
        output = m / ( fatorial(left) * (fatorial ( ( numsSize - 1) - left ) ) );
 
    
        if ( output > 1 ) {
        output--;
        }
    
        return output;

    } else {
        output = m / ( fatorial( left ) * (fatorial ( ( numsSize - 1) - left ) ) );
        output += m / ( fatorial( right ) * ( fatorial ( ( numsSize - 1) - right ) ) );

        if ( output > 1 ) {
        output--;
        }

        return output;
    }

}

