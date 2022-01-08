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

	unordered_map <string, NodeValue > groupGraph;

	NodeValue findValue(string nodeId) {

		if (!groupGraph.count(nodeId)) {
			groupGraph[nodeId] = {nodeId, 1.0};
		}

		NodeValue entry = groupGraph[nodeId];
		
		if (entry.first != nodeId) {
			NodeValue newEntry = findValue(entry.first);

			groupGraph[nodeId] = {newEntry.first, entry.second * newEntry.second};
		}

		return groupGraph[nodeId];
	}

	void unionVertex(string dividend, string divisor, double quotient) {
		NodeValue dividendEntry = findValue(dividend);
		NodeValue divisorEntry = findValue(divisor);

		string dividendGroupId = dividendEntry.first;
		string divisorGroupId = divisorEntry.first;
		double dividendWeight = dividendEntry.second;
		double divisorWeight = divisorEntry.second;

		// merge the two groups together,
	        // by attaching the dividend group to the one of divisor
	        if (dividendGroupId != divisorGroupId) {
	        	groupGraph[dividendGroupId] = {divisorGroupId, divisorWeight * quotient / dividendWeight};
	        }
	}

public:
	vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
		groupGraph.clear();

		// Step 1). build the union groups
		for (int i = 0; i < equations.size(); i++) {
			string dividend = equations[i][0];
			string divisor = equations[i][1];
			double quotient = values[i];

			unionVertex(dividend, divisor, quotient);
		}

		// Step 2). run the evaluation, with "lazy" updates in find() function
		vector<double> result(queries.size());
		for (int i = 0; i < queries.size(); i++) {
			string dividend = queries[i][0];
			string divisor = queries[i][1];

			if (!groupGraph.count(dividend) || !groupGraph.count(divisor)) {
				// case 1). at least one variable did not appear before
				result[i] = -1;
			} else {
				NodeValue dividendEntry = findValue(dividend);
				NodeValue divisorEntry = findValue(divisor);

				string dividendGroupId = dividendEntry.first;
				string divisorGroupId = divisorEntry.first;
				double dividendWeight = dividendEntry.second;
				double divisorWeight = divisorEntry.second;

				if (dividendGroupId != divisorGroupId) {
					// case 2). the variables do not belong to the same chain/group
					result[i] = -1;
				} else {
					// case 3). there is a chain/path between the variables
			                result[i] = dividendWeight / divisorWeight;
				}
			}
		}

		return result;
	}
};