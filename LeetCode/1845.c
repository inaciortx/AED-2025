
typedef struct {
    
bool *seats;
int nextS;
int numOfSeats;

} SeatManager;


SeatManager* seatManagerCreate(int n) {
    
    SeatManager *s = ( SeatManager *)malloc( sizeof(SeatManager));
    s -> seats = malloc( sizeof(bool) * n );
    s -> numOfSeats = n;
    s -> nextS = 0;

    for ( int i = 0; i < s -> numOfSeats; i++ ) {
        s -> seats[i] = false;
    }
    
    return s;

}

int seatManagerReserve(SeatManager* obj) {
    
    obj-> seats[obj->nextS] = true;
    int seat = obj -> nextS+1;
    obj -> nextS++;

    if ( obj -> nextS  == obj -> numOfSeats ) {
        return seat;
    }

    while ( obj -> nextS != obj -> numOfSeats && obj -> seats[obj->nextS] ) {
        obj->nextS++;
    }

    return seat;
}

void seatManagerUnreserve(SeatManager* obj, int seatNumber) {
    
    obj -> seats[seatNumber-1] = false;

    if ( seatNumber-1 < obj -> nextS ) {
        obj -> nextS = seatNumber - 1;
    }
}

void seatManagerFree(SeatManager* obj) {
    free ( obj -> seats );
    free ( obj );
}

/**
 * Your SeatManager struct will be instantiated and called as such:
 * SeatManager* obj = seatManagerCreate(n);
 * int param_1 = seatManagerReserve(obj);
 
 * seatManagerUnreserve(obj, seatNumber);
 
 * seatManagerFree(obj);
*/