/*
	There are n cities. Some of them are connected, while some are not. If city a is 
	connected directly with city b, and city b is connected directly with city c, then 
	city a is connected indirectly with city c.

	A province is a group of directly or indirectly connected cities and no other cities 
	outside of the group.

	You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city 
	and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

	Return the total number of provinces.

*/

class Solution {
    int parent[201];
    int rank[201];
    int provinceCount;

    void initDisJoint() {
    	for (int i = 0; i <= provinceCount; i++) {
    		parent[i] = i;
    		rank[i] = 1;
    	}
    }

    int findParent(int vertex) {
    	if(vertex == parent[vertex]) {
    		return vertex;
    	}

    	return parent[vertex] = findParent(parent[vertex]);
    }

    void unionVertex(int xV, int yV) {
    	int xParent = findParent(xV);
    	int yParent = findParent(yV);

    	if(xParent != yParent) {
    		if(rank[xParent] > rank[yParent]) {
    			parent[yParent] = xParent;
    		} else if (rank[xParent] < rank[yParent]) {
    			parent[xParent] = yParent;
    		} else {
    			parent[yParent] = xParent;
    			rank[xParent]++;
    		}


    		provinceCount--;
    	}
    }
    
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        provinceCount = isConnected.size();
        initDisJoint();

        int matrixSize = isConnected.size();

        for (int i = 0; i < matrixSize; i++) {
        	for (int j = 0; j < matrixSize; j++) {
        		if (isConnected[i][j]) {
        			unionVertex(i, j);
        		}
        	}
        }

        return provinceCount;
    }
};