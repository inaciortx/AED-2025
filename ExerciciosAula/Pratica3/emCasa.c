#define MOD 1000000007
#define MAX 1001

long long pascal[MAX][MAX];

void buildPascal() {

    for ( int i = 0; i < MAX; i++ ) {
        pascal[i][0] = pascal[i][i] = 1;
        for (int j = 1; j < i; j++) {
            pascal[i][j] = ( pascal[i-1][j-1] + pascal[i-1][j] ) % MOD;
        }
    }

}

long long countWays(int* nums, int size) {
    
    if ( size <= 2 ) {
        return 1;
    }

    int root = nums[0];
    int left[MAX], right[MAX];
    int l = 0, r = 0;

    for (int i = 1; i < size; i++) {
        if (nums[i] < root)
            left[l++] = nums[i];
        else
            right[r++] = nums[i];
    }

    long long leftWays = countWays(left, l);
    long long rightWays = countWays(right, r);
    long long intercal = pascal[l + r][l];

    return (((leftWays * rightWays) % MOD) * intercal) % MOD;
}

int numOfWays(int* nums, int size) {

    buildPascal();
    
    return (countWays(nums, size) - 1 + MOD) % MOD;
}
