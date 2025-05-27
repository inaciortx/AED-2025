int findPoisonedDuration(int* timeSeries, int timeSeriesSize, int duration) {
    
    int totalSec = duration;
    int diferenca = 0;

    for ( int i = 0; i < timeSeriesSize-1; i++ ){
        totalSec += duration;
        if ( timeSeries[i+1] - timeSeries[i] < duration ){
        diferenca = duration - (timeSeries[i+1] - timeSeries[i]);
        totalSec -= diferenca;
        }
    }
    return totalSec;
}