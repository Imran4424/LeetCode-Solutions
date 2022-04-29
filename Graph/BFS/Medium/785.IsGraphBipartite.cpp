/*
	There is an undirected graph with n nodes, where each node is numbered between 0 and n - 1. 
	You are given a 2D array graph, where graph[u] is an array of nodes that node u is adjacent to. 
	More formally, for each v in graph[u], there is an undirected edge between node u and node v. 
	The graph has the following properties:

	There are no self-edges (graph[u] does not contain u).
	There are no parallel edges (graph[u] does not contain duplicate values).
	If v is in graph[u], then u is in graph[v] (the graph is undirected).
	The graph may not be connected, meaning there may be two nodes u and v such that there is no path between them.

	A graph is bipartite if the nodes can be partitioned into two independent sets A and B such that 
	every edge in the graph connects a node in set A and a node in set B.

	Return true if and only if it is bipartite.
*/

class Solution {
	vector <int> visited;
	int visitedCount;

	bool BFS(vector<vector<int>>& graph) {
		queue <int> myQueue;

		// first entry
		for (int i = 0; i < graph.size(); i++) {
			if (-1 == visited[i] && graph[i].size()) {
				myQueue.push(i);
				visited[i] = 0;
				break;
			}
		}

		while(!myQueue.empty()) {
			int hand = myQueue.front();
			visitedCount--;
			myQueue.pop();

			for (int i = 0; i < graph[hand].size(); i++) {
				// not colored yet
				if (-1 == visited[graph[hand][i]]) {
					myQueue.push(graph[hand][i]);
					//coloring the opposite
					visited[graph[hand][i]] = !(visited[hand]);
				} else {
					// colored
					// check the color
					if (visited[hand] == visited[graph[hand][i]]) {
						// if colors are same
						// return false
						return false;
					}
				}
			}
		}

		return true;
	}


public:
	bool isBipartite(vector<vector<int>>& graph) {
		visited = vector(graph.size(), -1);
		visitedCount = graph.size();

		// one node region
		for (int i = 0; i < graph.size(); i++) {
			if (0 == graph[i].size()) {
				visitedCount--;
			}
		}

		bool bpGraph = true;
		while(bpGraph && visitedCount) {
			bpGraph = BFS(graph);
		}

		return bpGraph;

	}
};

/*
	-1 - not visited
	0 - color black
	1 - color red

*/