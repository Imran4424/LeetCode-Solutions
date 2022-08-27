
class Solution {
public:
	vector<int> countBits(int n) {
		vector <int> bits;
		bits.push_back(0);

		if (n < 1) {
			return bits;
		}

		for (int i = 1; i <= n; ++i) {
			int num = i;
			int count = 0;
			while(num != 0) {
				// justing count 1 digits
				// not holding there's no need
				if (num % 2) {
					count++;
				}
				
				num = num / 2;
			}

			bits.push_back(count);
		}

		return bits;
	}
};