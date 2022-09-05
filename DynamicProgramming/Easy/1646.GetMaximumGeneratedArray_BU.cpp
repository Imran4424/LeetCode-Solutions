
class Solution {
public:
	int getMaximumGenerated(int n) {
		if (0 == n) {
			return 0;
		}

		if (n < 3) {
			return 1;
		}

		int dp[n + 1];
		dp[0] = 0;
		dp[1] = 1;

		int maxVal = 1;
		int result = n / 2;

		for (int i = 1; i <= result; ++i) {
			dp[2 * i] = dp[i];

			if (dp[2 * i] > maxVal) {
				maxVal = dp[2 * i];
			}

			// even and i == result
			if (!(n % 2) && i == result) {
				continue;
			}

			dp[2 * i + 1] = dp[i] + dp[i + 1];
			if (dp[2 * i + 1] > maxVal) {
				maxVal = dp[2 * i + 1];
			}
		}

		return maxVal;
	}
};