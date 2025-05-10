bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
    
int espaços_livres = 0;
int i;
int zero_counter = 0;

if ( n == 0){
    return true;
}

if ( flowerbedSize == 1) {
    if ( n > 1 ){
        return false;
    }
    if( flowerbed[0] == 0){
        return true;
    } else {
        return false;
    }
}

if ( flowerbedSize == 2){
    if ( n > 1 ){
        return false;
    }
    if( flowerbed[0] == 0 && flowerbed[1] == 0){
        return true;
    } else {
        return false;
    }
}

if ( flowerbed[0] == 0 && flowerbed[1] == 0 ) {
    espaços_livres++;
    flowerbed[0] = 1;
}
if ( flowerbed[flowerbedSize - 1] == 0 && flowerbed[flowerbedSize - 2] == 0 ) {
    espaços_livres++;
    flowerbed[flowerbedSize - 1] = 1;
}

for( i=0; i<flowerbedSize; i++) {
    while( flowerbed[i] == 0){
        zero_counter++;
        i++;
        if ( i >= flowerbedSize){
            break;
        }
        if ( zero_counter == 3 ) {
            espaços_livres++;
            zero_counter = 0;
            i--;
            flowerbed[i-1] = 1;
        }   
    }
    zero_counter = 0;
}

if ( n <= espaços_livres ) {
    return true;
} else {
    return false;
}
}