


int mySqrt(int x) {

	if(0 == x || 1 == x) {
		return x;
	}

	int low = 1;
	int high = x / 2;

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

	if(high * high > x) {
		return high - 1;
	} 
	
	return high;
}