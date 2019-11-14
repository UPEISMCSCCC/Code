#include <vector>
#include <algorithm>
#define ll long long

// do not call directly
ll pollard_rho(ll n, ll s) {
	ll x, y;
	x = y = rand() % (n - 1) + 1;
	int head = 1, tail = 2;
	while (true) {
		x = mult(x, x, n);
		x = (x + s) % n;
		if (x == y) return n;
		ll d = __gcd(max(x - y, y - x), n);
		if (1 < d && d < n) return d;
		if (++head == tail) y = x, tail <<= 1;
	}
}

// call for prime factors
void factorize(ll n, vector<ll> &divisor) {
	if (n == 1) return;
	if (isPrime(n)) divisor.push_back(n);
	else {
		ll d = n;
		while (d >= n) d = pollard_rho(n, rand() % (n - 1) + 1);
		factorize(n / d, divisor);
		factorize(d, divisor);
	}
}