

double myPow(double x, long long int n) {
	if(0 == n || 1 == x) {
		return 1;
	}

	if(n < 0) {
		n = -n;
		x = 1 / x;
	}

	return (n % 2 == 0) ? myPow(x * x, n / 2) : x * myPow(x * x, n / 2);
}