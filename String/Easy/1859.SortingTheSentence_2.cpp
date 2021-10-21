bool sortByLastChar(string &s1, string &s2) {
    return s1[s1.size() - 1] < s2[s2.size() - 1];
}

class Solution {
public:
    string sortSentence(string s) {
        vector<string> tokens;
        stringstream runTest(s);
        
        string element;
        
        while(getline(runTest, element, ' ')) {
            tokens.push_back(element);
        }
        
        sort(tokens.begin(), tokens.end(), sortByLastChar);
        
        string sortedString = "";
        
        for (int i = 0; i < tokens.size(); i++) {
            tokens[i].pop_back();         
            sortedString += tokens[i];
            
            if (i + 1 != tokens.size()) {
                sortedString += " ";
            }
        }
        
        return sortedString;
    }
};