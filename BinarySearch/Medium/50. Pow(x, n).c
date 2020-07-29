

double myPow(double x, int n) {
	if(0 == n) {
		return 1;
	}

	if(n < 0) {
		n = -n;
		x = 1 / x;
	}

	double poweredNum = x;

	while(n > 1) {
		if(n % 2 == 0) {
			poweredNum = poweredNum * poweredNum;
		} else {
			poweredNum = x * poweredNum * poweredNum;
		}

		n = n / 2; 
	}

	return poweredNum;
}
