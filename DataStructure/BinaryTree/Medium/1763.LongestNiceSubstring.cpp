typedef pair <bool, bool> nicePair;

class CustomHashTable {
    unordered_map<char, int> uniqueChar;
    unordered_map <char, bool> isNice;
    int niceCount;

    char toLower(char ch) {
        if (ch >= 'A' && ch <= 'Z') {
            return ch + 32;
        }
        
        return ch;
    }
    
public:
    CustomHashTable() { }
    
    void insert(char ch) {
        uniqueChar[ch]++;
        
        ch = toLower(ch);
        
        if (uniqueChar[ch] && uniqueChar[ch - 32]) {
            isNice[ch] = true;
        } else {
            isNice[ch] = false;
        }
    }
    
    void remove(char ch) {
        if (uniqueChar[ch] > 1) {
            uniqueChar[ch]--;
        } else {
            uniqueChar.erase(ch);
        }
        
        ch = toLower(ch);
        
        if (uniqueChar[ch] && uniqueChar[ch - 32]) {
            isNice[ch] = true;
        } else {
            isNice[ch] = false;
        }
    }
    
    bool checkNice() {
        for (auto element : isNice) {
            if (!element.second) {
                return false;
            }
        }

        return true;
    }
};

class Solution {
public:
    string longestNiceSubstring(string word) {
        int maxNice = 0, currentNice = 0;
        string maxString;
        
        for (int i = 0; word[i]; i++) {
            currentNice = 0;
            CustomHashTable myHash;
            string currentString;
            for (int j = i; word[j]; j++) {
                myHash.insert(word[j]);
                currentString.push_back(word[j]);
                currentNice++;

                if (myHash.checkNice()) {
                    if (currentNice > maxNice) {
                        maxNice = currentNice;
                        maxString = currentString;
                    }
                }
            }
        }
        
        return maxString;
    }
};


/*

This is optimized brute force but not sliding window
curret solution
1 * 5 + 2 * 4 + 3 * 3 + 4 * 2 + 1 * 5 = 35


n^2
1 * 5 + 2 * 5 + 3 * 5 + 4 * 5 + 5 * 5 = 75

*/