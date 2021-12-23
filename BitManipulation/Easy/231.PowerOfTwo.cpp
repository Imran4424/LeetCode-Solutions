/*
	Given an integer n, return true if it is a power of two. Otherwise, return false.

	An integer n is a power of two, if there exists an integer x such that n == 2^x.

*/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        if (1 == n || 2 == n) {
            return true;
        }
        
        if (n % 2 != 0 || 0 == n) {
            return false;
        }
        
        return isPowerOfTwo(n / 2);
    }
};