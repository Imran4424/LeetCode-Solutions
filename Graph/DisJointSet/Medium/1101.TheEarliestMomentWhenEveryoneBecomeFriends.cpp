/*
	There are n people in a social group labeled from 0 to n - 1. You are given an array 
	logs where logs[i] = [timestampi, xi, yi] indicates that xi and yi will be friends at 
	the time timestampi.

	Friendship is symmetric. That means if a is friends with b, then b is friends with a. 
	Also, person a is acquainted with a person b if a is friends with b, or a is a friend 
	of someone acquainted with b.

	Return the earliest time for which every person became acquainted with every other person. 
	If there is no such earliest time, return -1.
*/

class Solution {
	int parent[101];
	int treeHeight[101];
	int connectedComponents;

	void initDisjoint(int vertex) {
		for (int i = 0; i <= vertex; i++) {
			parent[i] = i;
			treeHeight[i] = 1;
		}
	}

	int findParent(int vertex) {
		if (vertex == parent[vertex]) {
			return vertex;
		}

		return parent[vertex] = findParent(parent[vertex]);
	}

	void unionVertex(int xV, int yV) {
		int xPar = findParent(xV);
		int yPar = findParent(yV);

		if (xPar != yPar) {
			if (treeHeight[xPar] > treeHeight[yPar]) {
				parent[yPar] = xPar;
			} else if (treeHeight[xPar] < treeHeight[yPar]) {
				parent[xPar] = yPar;
			} else {
				parent[yPar] = xPar;
				treeHeight[xPar]++;
			}

			connectedComponents--;
		}
	}
public:
    int earliestAcq(vector<vector<int>>& logs, int n) {
        connectedComponents = n;
        initDisjoint(n);

        sort(logs.begin(), logs.end());

        for (int i = 0; i < logs.size(); i++) {
        	unionVertex(logs[i][1], logs[i][2]);

        	if (1 == connectedComponents) {
        		return logs[i][0];
        	}
        }

        return -1;
    }
};