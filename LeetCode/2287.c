int rearrangeCharacters(char* s, char* target) {
    
    int slen = strlen(s);
    int targetlen = strlen(target);
    int charcount = 0;
    int wordcount = 0;
    int iword = 0; 
    int i = 0;


    for ( i = 0; i < slen; i++ ){
        if ( s[i] == target[iword]){
            charcount++;
            iword++;
            s[i] = '#';
            i = -1;
            if ( charcount == targetlen){
                charcount = 0;
                wordcount++;
                iword = 0;
            }
        }   
    }   

return wordcount;

}