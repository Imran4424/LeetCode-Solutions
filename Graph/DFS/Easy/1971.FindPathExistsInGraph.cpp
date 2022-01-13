/*
	There is a bi-directional graph with n vertices, where each vertex is labeled 
	from 0 to n - 1 (inclusive). The edges in the graph are represented as a 2D integer 
	array edges, where each edges[i] = [ui, vi] denotes a bi-directional edge between 
	vertex ui and vertex vi. Every vertex pair is connected by at most one edge, and no vertex 
	has an edge to itself.

	You want to determine if there is a valid path that exists from vertex start to vertex end.

	Given edges and the integers n, start, and end, return true if there is a valid path from 
	start to end, or false otherwise.
*/

class Solution {
	vector <int> *adja;
	vector<bool> visited;

	bool dfs(int current, int target) {
		visited[current] = true;

		if (current == target) {
			return true;
		}

		for (int i = 0; i < adja[current].size(); i++) {
			if (!visited[adja[current][i]]) {
				if (dfs(adja[current][i], target)) {
					return true;
				}
			}
		}

		return false;
	}
public:
	bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
		adja = new vector<int>[n + 1];
		visited = vector<bool>(n + 1, false);

		// build graph
		for (int i = 0; i < edges.size(); i++) {
			adja[edges[i][0]].push_back(edges[i][1]);
			adja[edges[i][1]].push_back(edges[i][0]);
		}

		return dfs(start, end);
	}
};