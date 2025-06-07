int countCompleteDayPairs(int* hours, int hoursSize) {
    
    int pairs = 0;

    for ( int i = 0; i < hoursSize; i++ ) {
        for ( int j = i+1; j < hoursSize; j++ ) {
            if ( (hours[i] + hours[j]) % 24 == 0 ){
                pairs++;
            }
        }
    }

    return pairs;
}