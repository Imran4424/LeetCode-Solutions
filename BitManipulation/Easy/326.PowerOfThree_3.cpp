/*
	Given an integer n, return true if it is a power of three. Otherwise, return false.

	An integer n is a power of three, if there exists an integer x such that n == 3^x.

*/

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) {
            return false;
        }
        
        while(n % 3 == 0) {
            n /= 3;
        }
        
        return 1 == n;
    }
};