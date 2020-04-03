

int fib(int num) {
    if(0 == num || 1 == num) {
        return num;
    }

    return fib(num - 1) + fib(num - 2);
}

