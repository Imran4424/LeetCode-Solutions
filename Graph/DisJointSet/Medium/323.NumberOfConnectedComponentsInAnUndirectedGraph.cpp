/*
	You have a graph of n nodes. You are given an integer n and an array edges where 
	edges[i] = [ai, bi] indicates that there is an edge between ai and bi in the graph.

	Return the number of connected components in the graph.

*/

class Solution {
	int parent[2001];
	int treeHeight[2001];
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
	int countComponents(int n, vector<vector<int>>& edges) {
		connectedComponents = n;
		initDisjoint(n);

		for (int i = 0; i < edges.size(); i++) {
			unionVertex(edges[i][0], edges[i][1]);
		}

		return connectedComponents;
	}
};