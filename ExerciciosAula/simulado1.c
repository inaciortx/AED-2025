bool exist(char** board, int boardSize, int* boardColSize, char* word) {

       for ( int i = 0; i < boardColSize; i++) {
        for( int j = 0; i < boardSize; i++ ) {
            i2 = i;
            j2 = j;

            if ( board[i2][j2] == word[0] && j2 >= 0  && j2+1 < boardSize && i2+1 < boardColSize  ) {
                while ( board[i2][j2+1] == word[iword] || board[i2+1][j2] == word[iword] || board[i2][j2-1] == word[iword] ){
                    findWord++;
                    iword++;
                    if ( findWord == wordSize ){
                        return true;
                    }

                }
            }
            
}