

double myPow(double x, int n){
	if(0 == n) {
		return 1;
	}

	if(n < 0) {
		n = -n;
		x = 1 / x;
	}

	return (n % 2 == 0) ? myPow(x * x, n / 2) : x * myPow(x * x, n / 2);
}