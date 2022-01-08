/*
	You are given an array of variable pairs equations and an array of real numbers values, 
	where equations[i] = [Ai, Bi] and values[i] represent the equation Ai / Bi = values[i]. 
	Each Ai or Bi is a string that represents a single variable.

	You are also given some queries, where queries[j] = [Cj, Dj] represents the jth query 
	where you must find the answer for Cj / Dj = ?.

	Return the answers to all queries. If a single answer cannot be determined, return -1.0.

	Note: The input is always valid. You may assume that evaluating the queries will not result 
	in division by zero and that there is no contradiction.
*/

class Solution {
	typedef pair<string, double> NodeValue;

	unordered_map <string, NodeValue > weightedGraph;

	NodeValue findValue(string nodeId) {

		if (!weightedGraph.count(nodeId)) {
			weightedGraph[nodeId] = {nodeId, 1. 0};
		}

		NodeValue entry = weightedGraph[nodeId];
		
		if (entry.first != nodeId) {
			NodeValue newEntry = findValue(entry.first);

			weightedGraph[nodeId] = {entry.first, entry.second * newEntry.second};
		}

		return weightedGraph[nodeId];
	}

	void unionVertex(string dividend, string divisor, double quotient) {
		NodeValue dividendEntry = findValue(dividend);
		NodeValue divisorEntry = findValue(divisor);

		
	}

public:
	vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
		weightedGraph.clear();

		// Step 1). build the union groups
		for (int i = 0; i < equations.size(); i++) {
			string dividend = equations[i][0];
			string divisor = equations[i][1];
			double quotient = values[i];

			unionVertex(dividend, divisor, quotient);
		}
	}
};