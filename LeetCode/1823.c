int findTheWinner(int n, int k) {

int kCount = 0;
int pAlive = n;
int *heap = malloc( n * sizeof(int) );
int i = 0;

for ( i = 1; i <= n; i++ ) {

    heap[i-1] = i;

}

for ( i = 0; livepA != 1; i++ ) {

    if ( i >= n ) {
        i = 0;
    }

    while ( heap[i] == 0 ) {
        i++;
        if ( i >= n ) {
        i = 0;
        }
    }

    kCount++;
    if ( kCount == k) {
        heap[i] = 0;
        pAlive--;
        kCount = 0;
    }  
}

int result = 0;

for (i = 0; i < n; i++ ) {
    if ( heap[i] != 0 ) {
        result = heap[i];
        break;
    }
}

free(heap);
return result;

}