class Solution {
public:
    int maxDepth(string s) {
        int maxDepthCount = 0, depth = 0;
        
        for (int i = 0; i < s.size(); i++) {
            if ('(' == s[i]) {
                depth++;
                if (depth > maxDepthCount) {
                    maxDepthCount = depth;
                }
            } else if (')' == s[i]) {
                depth--;
            }
        }
        
        return maxDepthCount;
    }
};