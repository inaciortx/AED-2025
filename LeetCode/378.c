int ordena(const void* a, const void* b) {
   return (*(int*)a - *(int*)b);
}


int kthSmallest(int** matrix, int matrixSize, int* matrixColSize, int k) {
    
int *heap = malloc( sizeof(int) * ( matrixSize ) * ( *matrixColSize) );
int size = matrixSize * (*matrixColSize);
int c = 0;

for ( int i = 0; i < *matrixColSize; i++ ){
    for ( int j = 0; j < matrixSize; j++ ) {

        heap[c] = matrix[i][j];
        c++;

    }
}

qsort( heap, size, sizeof(int), ordena );

return heap[k-1];

}