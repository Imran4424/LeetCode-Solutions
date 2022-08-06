/*
	A string is good if there are no repeated characters.

	Given a string s​​​​​, return the number of good substrings of 
	length three in s​​​​​​.

	Note that if there are multiple occurrences of the same 
	substring, every occurrence should be counted.

	A substring is a contiguous sequence of characters in a string.

 

	Example 1:

	Input: s = "xyzzaz"
	Output: 1
	Explanation: There are 4 substrings of size 3: "xyz", "yzz", "zza", and "zaz". 
	The only good substring of length 3 is "xyz".

	Example 2:

	Input: s = "aababcabc"
	Output: 4
	Explanation: There are 7 substrings of size 3: "aab", "aba", "bab", "abc", 
	"bca", "cab", and "abc".
	The good substrings are "abc", "bca", "cab", and "abc".

 

	Constraints:

	    1 <= s.length <= 100
	    s​​​​​​ consists of lowercase English letters.
*/

class CustomHashTable {
    unordered_map<char, int> uniqueChar;
public:
    CustomHashTable() { }
    
    void insert(char ch) {
        uniqueChar[ch]++;
    }
    
    void remove(char ch) {
        if (uniqueChar[ch] > 1) {
            uniqueChar[ch]--;
        } else {
            uniqueChar.erase(ch);
        }
    }
    
    int uniqueCount() {
        return uniqueChar.size();
    }
};

class Solution {
public:
    int countGoodSubstrings(string word) {
        if (word.size() < 3) {
            return 0;
        }
        
        // create the first chunk
        CustomHashTable myHash;
        for (int i = 0; i < 3; i++) {
            myHash.insert(word[i]);
        }
        
        int left = 0;
        int count = 0;
        
        if (3 == myHash.uniqueCount()) {
            count++;
        }
        
        
        for (int right = 3; word[right]; right++, left++) {
            myHash.remove(word[left]);
            myHash.insert(word[right]);
            
            if (3 == myHash.uniqueCount()) {
                count++;
            }
        }
        
        return count;
    }
};