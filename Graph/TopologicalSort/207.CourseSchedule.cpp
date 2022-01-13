/*
	There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. 
	You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you 
	must take course bi first if you want to take course ai.

    	For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.

	Return true if you can finish all courses. Otherwise, return false.
*/

class Solution {
public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		vector <int> adjacency[numCourses];
		vector <int> inDegree(numCourses, 0);

		for (int i = 0; i < prerequisites.size(); i++) {
			adjacency[prerequisites[i][1]].push_back(prerequisites[i][0]);
			inDegree[prerequisites[i][0]]++;
		}

		vector <int> topologicalOrder;

		queue <int> freeList;
		for (int i = 0; i < numCourses; i++) {
			if (0 == inDegree[i]) {
				freeList.push(i);
			}
		}

		while(!freeList.empty()) {
			int hand = freeList.front();
			freeList.pop();

			topologicalOrder.push_back(hand);

			for (int i = 0; i < adjacency[hand].size(); i++) {
				inDegree[adjacency[hand][i]]--;

				if (0 == inDegree[adjacency[hand][i]]) {
					freeList.push(adjacency[hand][i]);
				}
			}
		}

		if (numCourses == topologicalOrder.size()) {
			return true;
		}

		return false;
	}
};