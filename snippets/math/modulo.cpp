#define MOD 1e9+7
#define madd(a,b,m) (((a%m)+(b%m))%m)
#define mult(a,b,m) (((a%m)*(b%m))%m)
#define msub(a,b,m) (((a%m)-(b%m)+m)%m)

ll mpow(ll b, ll e, ll m) {
	ll x = 1;
	while (e > 0) {
		if (e % 2 == 1) x = (x * b) % m;
		b = (b * b) % m;
		e /= 2;
	}
	return x % m;
}

ull mfac(ull n, ull m) {
	ull f = 1;
    for (int i = n; i > 1; i--) {
		f = f * i;
		f %= m;
	}
	return f;
}

// if m is not guaranteed to be prime
ll minv(ll b, ll m) {
	ll x = 0, y = 0;
	if (egcd(b, m, x, y) != 1) return -1;
	return (x % m + m) % m;
}
ll mdiv_compmod(int a, int b, int m) {
	if (__gcd(b, m) != 1) return -1;
	return mult(a, minv(b, m), m);
}

// if m is prime (like 10^9+7)
ll mdiv_primemod (int a, int b, int m) {
	return mult(a, mpow(b, m-2, m), m);
}
