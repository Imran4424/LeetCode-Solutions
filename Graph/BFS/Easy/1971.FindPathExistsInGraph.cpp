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
	bool visited[200001];

	void init(int nodeNum) {
		for (int i = 0 ; i <= nodeNum; i++) {
			visited[i] = false;
		}
	}
public:
	bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
		vector <int> adja[n + 1];
		init(n);

		// build graph
		for (int i = 0; i < edges.size(); i++) {
			adja[edges[i][0]].push_back(edges[i][1]);
			adja[edges[i][1]].push_back(edges[i][0]);
		}

		queue <int> stList;
		stList.push(start);

		while(!stList.empty()) {
			int hand = stList.front();
			if (hand == end) {
				return true;
			}
			stList.pop();
			visited[hand] = true;

			for (int i = 0; i < adja[hand].size(); i++) {
				if (!visited[adja[hand][i]]) {
					stList.push(adja[hand][i]);
				}
			}
		}

		return false;
	}
};