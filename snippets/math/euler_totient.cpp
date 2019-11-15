int phi(int n) {
	int r = n;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) r -= r / i;
		while (n % i == 0) n /= i;
	}
	if (n > 1) r -= r / n;
	return r;
}
