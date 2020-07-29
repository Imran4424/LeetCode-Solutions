

double myPow(double x, int n) {
	double poweredNum = 1;

	for (int i = 1; i <= n; i++) {
		poweredNum = poweredNum * x;
	}

	for(int i = 0; i >= n; i--) {
		poweredNum = poweredNum / x;
	}

	return poweredNum;
}
