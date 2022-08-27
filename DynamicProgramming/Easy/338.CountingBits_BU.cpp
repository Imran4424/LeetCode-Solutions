
class Solution {
public:
	vector<int> countBits(int n) {
		vector <int> dpBits(n + 1);
		dpBits[0] = 0;

		if (n < 1) {
			return dpBits;
		}

		for (int i = 1; i <= n; ++i) {
			
			dpBits[i] = dpBits[i / 2] + i % 2;
		}

		return dpBits;
	}
};