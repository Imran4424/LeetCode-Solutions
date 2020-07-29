


int mySqrt(int num){
    
    long long int i;
    
    for(i = 1; i*i <= num; i++) {
        if(i*i == num) {
            return i;
        }
    }
    
    return i - 1;
}











