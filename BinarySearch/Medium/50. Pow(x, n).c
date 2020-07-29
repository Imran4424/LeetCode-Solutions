

double myPow(double x, int n) {
	double poweredNum = x;

	for (int i = 2; i <= n; i++) {
		poweredNum = poweredNum * x;
	}

	return poweredNum;
}
