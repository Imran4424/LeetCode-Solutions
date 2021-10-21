class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string sentenceOne = "";
        string sentenceTwo = "";
        
        int i = 0;
        while (i < word1.size() && i < word2.size()) {
            sentenceOne += word1[i];
            sentenceTwo += word2[i];
            i++;
        }
        
        while (i < word1.size()) {
            sentenceOne += word1[i];
            i++;
        }
        
        while (i < word2.size()) {
            sentenceTwo += word2[i];
            i++;
        }
        
        return sentenceOne == sentenceTwo;
    }
};