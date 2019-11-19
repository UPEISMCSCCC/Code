bitset<100000001> sieve;

// generate sieve - O(n log n)
void genSieve(int n) {
	sieve[0] = sieve[1] = 1;
	for (ull i = 3; i * i < n; i += 2)
		if (!sieve[i])
			for (ull j = i * 3; j <= n; j += i * 2)
				sieve[j] = 1;
}

// query sieve after it's generated - O(1)
bool querySieve(int n) {
	return n == 2 || (n % 2 != 0 && !sieve[n]);
}
