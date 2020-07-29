

double myPow(double x, int n) {
	if(n < 0) {
		n = -n;
		x = 1 / x;
	}

	double poweredNum = x;

	while(n > 1) {
		poweredNum = poweredNum * poweredNum;

		n = n / 2; 
	}

	return poweredNum;
}
