/*
	You are given an array points representing integer coordinates of some points on a 2D-plane, 
	where points[i] = [xi, yi].

	The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance 
	between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.

	Return the minimum cost to make all points connected. All points are connected 
	if there is exactly one simple path between any two points.
*/


class Solution {
	typedef pair <int, int> nodes;
	typedef pair < int, nodes> weightNode;

	vector <int> parent;
	vector <int> treeHeight;
	vector < weightNode > edgeDictionary;

	int absolute(int x) {
		if (x < 0) {
			return -x;
		}

		return x;
	}

	int findParent(int vertex) {
		if (parent[vertex] == vertex) {
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

public:
	int minCostConnectPoints(vector<vector<int>>& points) {
		// init
		int sizeCount = (points.size() * (points.size() - 1)) / 2;
		edgeDictionary = vector < weightNode > (sizeCount);
		parent = vector<int>(points.size() + 1);
		treeHeight = vector<int>(points.size() + 1);
		for (int i = 0; i < parent.size(); i++) {
			parent[i] = i;
			treeHeight[i] = 1;
		}

		// edge creation
		int index = 0;
		for (int i = 0; i < points.size(); i++) {
			for (int j = i + 1; j < points.size(); j++) {
				int dist = absolute(points[i][0] - points[j][0]) + absolute(points[i][1] - points[j][1]);

				edgeDictionary[index++] = { dist, { i, j }};
			}
		}

		sort(edgeDictionary.begin(), edgeDictionary.end());


		int cost = 0;

		for (auto it : edgeDictionary) {
			if (unionVertex(it.second.first, it.second.second)) {
				cost += it.first;
			}
			
		}

		return cost;
	}
};