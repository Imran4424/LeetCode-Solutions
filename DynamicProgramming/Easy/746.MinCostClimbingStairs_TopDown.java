/*
	You are given an integer array cost where cost[i] is the cost of ith step on a staircase. 
	Once you pay the cost, you can either climb one or two steps.

	You can either start from the step with index 0, or the step with index 1.

	Return the minimum cost to reach the top of the floor.

	Example 1:

	Input: cost = [10,15,20]
	Output: 15
	Explanation: You will start at index 1.
	- Pay 15 and climb two steps to reach the top.
	The total cost is 15.

	Example 2:

	Input: cost = [1,100,1,1,1,100,1,1,100,1]
	Output: 6
	Explanation: You will start at index 0.
	- Pay 1 and climb two steps to reach index 2.
	- Pay 1 and climb two steps to reach index 4.
	- Pay 1 and climb two steps to reach index 6.
	- Pay 1 and climb one step to reach index 7.
	- Pay 1 and climb two steps to reach index 9.
	- Pay 1 and climb one step to reach the top.
	The total cost is 6.

 
	Constraints:

	    2 <= cost.length <= 1000
	    0 <= cost[i] <= 999
*/

class Solution {
	int[] minCost = new int[1001];

	int minValue(int x, int y) {
		if (x < y) {
			return x;
		}

		return y;
	}

	int dpCost(int[] cost, int index) {
		if (index < 2) {
			return 0;
		}

		if (-1 != minCost[index]) {
			return minCost[index];
		}

		return minCost[index] = minValue(dpCost(cost, index - 1) + cost[index - 1], dpCost(cost, index - 2) + cost[index - 2]);
	}

	public int minCostClimbingStairs(int[] cost) {
		for (int i = 0; i < 1001; ++i) {
			minCost[i] = -1;
		}

		return dpCost(cost, cost.length);
	}
}