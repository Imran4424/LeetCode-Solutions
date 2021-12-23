/*
	Given an integer n, return true if it is a power of three. Otherwise, return false.

	An integer n is a power of three, if there exists an integer x such that n == 3^x.

*/

class Solution {
    int logAbaseB(int a, int base) {
        return log(a) / log(base);
    }
    
    int maxPow(int x) {
        return pow(x, logAbaseB(INT_MAX, x));
    }
public:
    bool isPowerOfThree(int n) {
        return n > 0 && maxPow(3) % n == 0;
    }
};