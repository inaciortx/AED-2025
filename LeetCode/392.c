bool isSubsequence(char* s, char* t) {
    
    int slen = strlen(s);
    int tlen = strlen(t);
    int iword = 0;

    for ( int i = 0; i < tlen; i++){

        if ( t[i] == s[iword] ){
            iword++;
        }
    }
    if (iword >= slen){
        return true;
    } else {
        return false;
    }
    
}