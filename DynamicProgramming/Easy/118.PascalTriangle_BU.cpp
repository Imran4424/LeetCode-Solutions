
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector< vector<int> > pascalTriangle;
        
        for (int i = 0; i < numRows; i++) {
            // inserting the rows
            pascalTriangle.push_back(vector<int>(i + 1));
            
            // intializing outer cells with 1
            pascalTriangle[i][0] = 1;
            pascalTriangle[i][i] = 1;
            
            // returning if it is less than 3rd rows
            if (i < 2) {
                continue;
            }
            
            // populate inside cells
            // j < i cause i-th cell of this row is last row and it's already fill with 1
            for (int j = 1; j < i; ++j) {
                // from previous row, previous col + current col
                pascalTriangle[i][j] = pascalTriangle[i - 1][j - 1] + pascalTriangle[i - 1][j];
            }
        }
        
        return pascalTriangle;
    }
};

// bottom up dp