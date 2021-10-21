class Solution {
public:
    bool checkIfPangram(string sentence) {
        set<char> letterSet;
        
        for (int i = 0; i < sentence.size(); i++) {
            letterSet.insert(sentence[i]);
        }
        
        return letterSet.size() == 26;
    }
};