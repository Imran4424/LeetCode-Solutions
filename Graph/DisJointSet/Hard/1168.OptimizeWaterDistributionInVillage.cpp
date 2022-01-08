/*
	There are n houses in a village. We want to supply water for all the houses by 
	building wells and laying pipes.

	For each house i, we can either build a well inside it directly with cost 
	wells[i - 1] (note the -1 due to 0-indexing), or pipe in water from another well 
	to it. The costs to lay pipes between houses are given by the array pipes, where 
	each pipes[j] = [house1j, house2j, costj] represents the cost to connect house1j 
	and house2j together using a pipe. Connections are bidirectional.

	Return the minimum total cost to supply water to all houses.
*/

class Solution {
	int parent[10001];
	int treeHeight[10001];

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

	bool unionVertex(int xV, int yV) {
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

			return true;
		}

		return false;
	}

	struct Compare
	{
		bool operator()(const vector<int>& x, const vector<int>& y) const {
			return x[2] < y[2];
		}
	};

public:
	int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
		int cost = 0;
		initDisjoint(n);

		// adding wells cost as pipes (which is a edge)
		// this is a clever trick to convert the problem to standard MST problem
		// add the virtual vertex (index with 0) along with the new edges.
		for (int i = 0; i < n; i++) {
			pipes.push_back({0, i + 1, wells[i]});
		}

		sort(pipes.begin(), pipes.end(), Compare());

		for (int i = 0; i < pipes.size(); i++) {
			if (unionVertex(pipes[i][0], pipes[i][1])) {
				cost += pipes[i][2];
			}
		}

		return cost;
	}
};