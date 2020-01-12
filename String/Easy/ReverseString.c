
void reverseString(char* s, int sSize){
    
    int availSize = sSize - 1;
    
    for(int i = 0; i < sSize / 2; i++) {

    	// using a third variable to swap
        char temp = s[i];
        s[i] = s[availSize - i];
        s[availSize - i] = temp;
    }
}
