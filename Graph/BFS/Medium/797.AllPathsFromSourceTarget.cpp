class Solution {
public:
	vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
		vector <vector<int>> pathList;
		
		if (0 == graph.size()) {
			return pathList;
		}

		queue <vector <int>> pathQueue;
		vector <int> path;
		path.push_back(0);
		pathQueue.push(path);

		while(!pathQueue.empty()) {
			vector <int> currentPath = pathQueue.front();
			pathQueue.pop();

			int currentNode = currentPath.back();

			for (int nextNode : graph[currentNode]) {
				vector <int> tempPath(currentPath.begin(), currentPath.end());
				tempPath.push_back(nextNode);

				if (nextNode == graph.size() - 1) {
					// found one path
					// no need to go further
					pathList.push_back(tempPath);
				} else {
					pathQueue.push(tempPath);
				}
			}
		}

		return pathList;
	}
};