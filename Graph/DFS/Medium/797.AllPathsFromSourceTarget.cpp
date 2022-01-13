class Solution {
	vector <vector<int>> pathList;
	vector<vector<int>> adja;
	bool visited[15];

	void init(int nodeNum) {
		for (int i = 0; i < nodeNum; i++) {
			visited[i] = false;
		}
	}

	void dfs(int current, int target, vector<int> curList) {
		curList.push_back(current);

		if (current == target) {
			pathList.push_back(curList);
			return;
		}

		for (int i = 0; i < adja[current].size(); i++) {
			if(!visited[adja[current][i]]) {
				visited[adja[current][i]] = true;
				dfs(adja[current][i], target, curList);
				visited[adja[current][i]] = false; // backtracking
			}
		}
	} 

public:
	vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
		adja = graph;
		init(graph.size());

		visited[0] = true;
		dfs(0, graph.size() - 1, vector<int>());

		return pathList;
	}
};