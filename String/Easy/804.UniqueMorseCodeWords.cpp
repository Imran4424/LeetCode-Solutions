class Solution {
    string morseCode[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        set<string> uniqueCodes;
        
        for (int i = 0; i < words.size(); i++) {
            string code = "";
            for (int j = 0; j < words[i].size(); j++) {
                code += morseCode[words[i][j]- 'a'];
            }
            
            uniqueCodes.insert(code);
        }
        
        return uniqueCodes.size();
    }
};