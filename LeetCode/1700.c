int countStudents(int* students, int studentsSize, int* sandwiches, int sandwichesSize) {

    int end = studentsSize - 1;
    int sTop = 0;
    int sEat = studentsSize;
    int cicle = 0;


    while ( sEat != 0 && cicle != sEat) {

        if ( sandwiches[sTop] == students[0] ) {
            
            for ( int i = 0; i < end; i++ ) {
                students[i] = students[i+1];
            }
            cicle = 0;
            sTop++;
            end--;
            sEat--;
        } else {
            int temp = students[0];
            for ( int i = 0; i < end; i++ ) {
                students[i] = students[i+1];
            }
            students[end] = temp;
            cicle++;
        }
    }
    return sEat;
}

    