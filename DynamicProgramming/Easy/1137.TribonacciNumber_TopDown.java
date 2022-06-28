/*
	The Tribonacci sequence Tn is defined as follows: 

	T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.

	Given n, return the value of Tn.
*/

class Solution {
	int[] dp = new int[40];

	int dpTribonacci(int n) {
		if (0 == n) {
			return 0;
		}

		if (n < 3) {
			return 1;
		}

		if (-1 != dp[n]) {
			return dp[n];
		}

		return dp[n] = dpTribonacci(n - 1) + dpTribonacci(n - 2) + dpTribonacci(n - 3);
	}

	public int tribonacci(int n) {
		for (int i = 0; i < 40; ++i) {
			dp[i] = -1;
		}

		return dpTribonacci(n);
	}
}