bool verify(char **board, int boardSize, int *boardColSize, char *word, int line, int col, int iword);

bool exist(char** board, int boardSize, int* boardColSize, char* word) {
    
    for ( int i = 0; i < boardSize; i++ ) {
        for ( int j = 0; j < boardColSize[i]; j++ ) {
            if ( board[i][j] == word[0] ){
                if ( verify( board, boardSize, boardColSize, word, i, j, 0 ) ) {
                        return true;
                }
            }
        }
    }
    return false;
}

bool verify(char **board, int boardSize, int *boardColSize, char *word, int line, int col, int iword){

    if (word[iword] == '\0') {
        return true;  
    }

    if (line < 0 || line >= boardSize || col < 0 || col >= boardColSize[line] || board[line][col] != word[iword]) {
        return false;  
    }

    char temp = board[line][col];
    board[line][col] = '*';  

    if (verify(board, boardSize, boardColSize, word, line, col + 1, iword + 1)) {
        board[line][col] = temp;
        return true;
    }

    if (verify(board, boardSize, boardColSize, word, line + 1, col, iword + 1)) {
        board[line][col] = temp;
        return true;
    }

    if (verify(board, boardSize, boardColSize, word, line, col - 1, iword + 1)) {
        board[line][col] = temp;
        return true;
    }

    if (verify(board, boardSize, boardColSize, word, line - 1, col, iword + 1)) {
        board[line][col] = temp;
        return true;
    }

    board[line][col] = temp;
    return false;
}