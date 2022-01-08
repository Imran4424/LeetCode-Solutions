
/*
	You have a graph of n nodes labeled from 0 to n - 1. You are given an integer n and a 
	list of edges where edges[i] = [ai, bi] indicates that there is an undirected edge 
	between nodes ai and bi in the graph.

	Return true if the edges of the given graph make up a valid tree, and false otherwise.

	
	Cycle Detection
*/

class Solution {
	int parent[2001];
	int treeHeight[2001];
	int regionCount;

	void initDisjoint(int vertex = 2000) {
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

	bool unionFind(int xV, int yV) {
		int xP = findParent(xV);
		int yP = findParent(yV);

		if (xP != yP) {
			if(treeHeight[xP] > treeHeight[yP]) {
				parent[yP] = xP;
			} else if (treeHeight[xP] < treeHeight[yP]) {
				parent[xP] = yP;
			} else {
				parent[yP] = xP;
				treeHeight[xP]++;
			}

			regionCount--;
			return false;
		}

		return true;
	}

public:
	bool validTree(int n, vector<vector<int>>& edges) {
		initDisjoint(n);
		regionCount = n;

		for (int i = 0; i < edges.size(); i++) {
			if(unionFind(edges[i][0], edges[i][1])) {
				return false;
			}
		}

		if (1 != regionCount) {
			return false;
		}

		return true;
	}
};