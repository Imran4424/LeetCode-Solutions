class Solution {
    string morseCode[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        set<string> uniqueCodes;
        
        for (string word: words) {
            string code = "";
            for (char ch: word) {
                code += morseCode[ch - 'a'];
            }
            
            uniqueCodes.insert(code);
        }
        
        return uniqueCodes.size();
    }
};