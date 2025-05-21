int maximumPopulation(int** logs, int logsSize, int* logsColSize) {
    
    int infos[2] = {0};
    int peapolecount = 0;
    int j = 0;

    while ( logsSize > j){
        int birth = logs[j][0];

        for ( int i = 0; i < logsSize; i++ ){

            if ( birth >= logs[i][0] && birth < logs[i][1] ){
                peapolecount++;
            }        
        }
        if ( peapolecount > infos[1] || (peapolecount == infos[1] && birth < infos[0]) ) {
            infos[0] = birth;
            infos[1] = peapolecount;
        }
        j++;
        peapolecount = 0;
    }
    return infos[0];
}