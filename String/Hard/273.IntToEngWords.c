

char * numberToWords(long long int num) {
    int digits[12];
    int index = 0;
    
    char *spelling = malloc(100 * sizeof(char));
    
    while(0 != num) {
    	digits[index++] = num % 10;
    	num = num / 10;
    } 
}

