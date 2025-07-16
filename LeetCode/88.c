int compare( const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}
int* merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    
    int j = 0;

    for ( int i = m; i < nums1Size; i++ ) {
        nums1[i] = nums2[j];
        j++;
    }

    qsort( nums1, nums1Size, sizeof(int), compare );

    return nums1;
}