int oddCells(int m, int n, int** indices, int indicesSize, int* indicesColSize) {
    
    int **matrix = malloc(sizeof(int*) * m);
    int oddnumcount = 0;
    int i, j;
    for (i = 0; i < m; i++) {
        matrix[i] = malloc(sizeof(int) * n);
        for (j = 0; j < n; j++) {
            matrix[i][j] = 0;
        }
    }
    for (i = 0; i < indicesSize; i++) {
        int row = indices[i][0];
        int col = indices[i][1];

        for (j = 0; j < n; j++) {
            matrix[row][j]++;
        }

        for (j = 0; j < m; j++) {
            matrix[j][col]++;
        }
    }
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (matrix[i][j] % 2 != 0) {
                oddnumcount++;
            }
        }
    }
    return oddnumcount;
}