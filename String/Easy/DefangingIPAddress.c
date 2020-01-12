
char* defangIPaddr(char* address){
    
    char *encodedIP = malloc(sizeof(char) * 22);
    int i, k = 0;
    
    for(i = 0; address[i] != '\0'; i++) {
        if(0 < i && '.' == address[i - 1]) {
            encodedIP[k] = ']';
            k++;
        } else if('.' == address[i]) {
            encodedIP[k] = '[';
            k++;
        }
        
        encodedIP[k] = address[i];
        k++;
    }
    
    encodedIP[k] = '\0';
    
    return encodedIP;
}
