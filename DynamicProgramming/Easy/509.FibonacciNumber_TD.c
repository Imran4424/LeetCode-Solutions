
int dpFib[35] = {0};


int fib(int number) {
    if(0 != dpFib[number]) {
        return dpFib[number];
    }
    
    if(0 == number || 1 == number) {
        return dpFib[number] = number;
    }
    
    return dpFib[number] = fib(number - 1) + fib(number - 2);
}