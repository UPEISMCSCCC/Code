const int MAXN = 100000;
template<int N>
struct Sieve {
	bool sieve[N];
	constexpr Sieve() : sieve() {
		sieve[0] = sieve[1] = 1;
		for (int i = 2; i * i < N; i++)
			if (!sieve[i])
				for (int j = i * 2; j < N; j += i)
					sieve[j] = 1;
	}
};
bool isPrime(int n) {
	static constexpr Sieve<MAXN> s;
	return !s.sieve[n];
}