/*
	Write a function that takes an unsigned integer and returns 
	the number of '1' bits it has (also known as the Hamming weight).
*/

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int oneCount = 0;
        
        while (0 != n) {
            if(n & 1) {
                oneCount++;
            }
            
            n /= 2;
        }
        
        return oneCount;
    }
};