int romanToInt(char * s){
    int romanDigit[26];
    
    romanDigit[(int)('I' - 'A')] = 1;
    romanDigit[(int) ('V' - 'A')] = 5;
    romanDigit[(int)('X' - 'A')] = 10;
    romanDigit[(int)('L' - 'A')] = 50;
    romanDigit[(int)('C' - 'A')] = 100;
    romanDigit[(int)('D' - 'A')] = 500;
    romanDigit[(int)('M' - 'A')] = 1000;
    
    int decimalVal = 0;
    
    for(int i = 0; i < s[i] != '\0'; i++) {
        if('\0' != s[i + 1]) {
            int current = romanDigit[(int)(s[i] - 'A')];
            int next = romanDigit[(int)(s[i + 1] - 'A')];
            
            if(current < next) {
                decimalVal = decimalVal - current;
                //printf("negative\n");
            } else {
                decimalVal = decimalVal + current;
                //printf("positive \n");
            }
        } else {
            decimalVal = decimalVal + romanDigit[(int)(s[i] - 'A')];
        }
    }
    
    return decimalVal;
}