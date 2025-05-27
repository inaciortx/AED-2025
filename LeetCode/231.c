bool isPowerOfTwo(int n) {
    
    double powertwo = 1;

    if ( n == 1) { 
        return true;
    }

    while ( powertwo < n ) {
        powertwo = powertwo * 2;

        if ( powertwo == n) {
            return true;
        }
    }
    return false;
}