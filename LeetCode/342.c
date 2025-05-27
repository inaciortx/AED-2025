bool isPowerOfFour(int n) {
    
    double powerfour = 1;

    if ( n == 1) { 
        return true;
    }

    while ( powerfour < n ) {
        powerfour = powerfour * 4;

        if ( powerfour == n) {
            return true;
        }
    }
    return false;
}
