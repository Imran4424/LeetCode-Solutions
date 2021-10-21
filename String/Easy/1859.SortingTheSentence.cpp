
class Solution {
public:
    string sortSentence(string s) {
        vector<string> tokens(10);
        
        string element;
        
        
        string sortedString = "";
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= 48 && s[i] <= 57) {
                tokens[s[i] - 48] = element + " ";
                element = "";
                i++; // for skipping the space after int value
            } else {
                element += s[i];
            }
        }
        
        for (int i = 0; i < tokens.size(); i++) {
            sortedString += tokens[i];
        }
        
        sortedString.pop_back();
        return sortedString;
    }
};