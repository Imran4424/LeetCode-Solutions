


int mySqrt(int x) {
	int low = 1;
	int high = x;

	while(low < high) {
		int mid = low + (high - low) / 2;

		if (mid * mid == x) {
			return mid;
		} else if(mid * mid > x) {
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}

	return high;
}