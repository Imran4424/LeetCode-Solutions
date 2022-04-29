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

	vector <int> parent;
	vector <int> treeHeight;
	map<int, vector<nodes> > edgeDictionary;

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
		edgeDictionary.clear();
		parent.clear();
		treeHeight.clear();
		for (int i = 0; i < points.size(); i++) {
			parent.push_back(i);
			treeHeight.push_back(1);
		}

		// edge creation
		for (int i = 0; i < points.size(); i++) {
			for (int j = i + 1; j < points.size(); j++) {
				int dist = absolute(points[i][0] - points[j][0]) + absolute(points[i][1] - points[j][1]);

				edgeDictionary[dist].push_back({ i, j });
			}
		}


		int cost = 0;

		for (auto it : edgeDictionary) {
			for (auto nodePair: it.second) {
				if (unionVertex(nodePair.first, nodePair.second)) {
					cost += it.first;
				}
			}
			
		}

		return cost;
	}
};


/*
	This sometimes ended up with TLE

*/