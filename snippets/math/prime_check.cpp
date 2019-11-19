// Miller-Rabin primality test - O(10 log^3 n)
bool isPrime(ull n) {
	if (n < 2) return false;
	if (n == 2) return true;
	if (n % 2 == 0) return false;

	ull s = n - 1;
	while (s % 2 == 0) s /= 2;

	for (int i = 0; i < 10; i++) {
		ull temp = s;
		ull a = rand() % (n - 1) + 1;
		ull mod = mpow(a, temp, n);
		while (temp != n - 1 && mod != 1 && mod != n - 1) {
			mod = mult(mod, mod, n);
			temp *= 2;
		}
		if (mod != n - 1 && temp % 2 == 0) return false;
	}
	return true;
}
