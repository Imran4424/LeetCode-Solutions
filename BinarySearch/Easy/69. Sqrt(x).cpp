
class Solution {
public:
	int mySqrt(int x) {
		if (x < 2) {
			return x;
		}

		long long int low = 2;

		long long int high = x / 2;
		long long int mid;

		long long int current;

		while (low <= high) {
			mid = low + (high - low) / 2;
			current = mid * mid;

			if (current == x) {
				return mid;
			} else if (current > x) {
				high = mid - 1;
			} else {
				low = mid + 1;
			}
		}

		return mid - 1;
	}
};


