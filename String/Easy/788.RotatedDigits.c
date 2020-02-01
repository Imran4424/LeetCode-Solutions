bool isValid(int number) {
    int digits[5];
    int index = 0;
    
    while(0 != number) {
        digits[index++] = number % 10;
        number = number / 10;
    }
    
    int reverseAble = 0, notReverseAble = 0;
    
    for(int i = 0; i < index; i++) {
        if(2 == digits[i] || 5 == digits[i] || 6 == digits[i] || 9 == digits[i]) {
            reverseAble++;
        } else if(3 == digits[i] || 4 == digits[i] || 7 == digits[i]) {
            notReverseAble++;
        }
    }
    
    if(0 == notReverseAble && reverseAble > 0) {
        return true;
    }
    
    return false;
}

int rotatedDigits(int N) {
    int validCount = 0;
    
    for(int i = 1; i <= N; i++) {
        if(isValid(i)) {
            validCount++;
        }
    }
    
    return validCount;
}