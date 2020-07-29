

double myPow(double x, long long int n) {
	if(0 == n) {
		return 1;
	}

	if(n < 0) {
		n = -n;
		x = 1 / x;
	}

	double poweredNum = 1;

	while(n > 0) {
		if(1 == n % 2) {
			poweredNum = poweredNum * x;
		}

		x = x * x;

		n = n / 2; 
	}

	return poweredNum;
}
