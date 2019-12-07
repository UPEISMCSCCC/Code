ull* catalan = new ull[1000000];

void genCatalan(int n, int mod) {
	catalan[0] = catalan[1] = 1;
	for (int i = 2; i <= n; i++) {
		catalan[i] = 0;
		for (int j = i - 1; j >= 0; j--) {
			catalan[i] += (catalan[j] * catalan[i-j-1]) % mod;
			if (catalan[i] >= mod)
				catalan[i] -= mod;
		}
	}
}

// TODO: consider binomial coefficient method
