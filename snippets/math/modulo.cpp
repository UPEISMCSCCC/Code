#define MOD 1000000007
#define madd(a,b,m) (a+b-((a+b-m>=0)?m:0))
#define mult(a,b,m) ((ull)a*b%m)
#define msub(a,b,m) (a-b+((a<b)?m:0))

ll mpow(ll b, ll e, ll m) {
	ll x = 1;
	while (e > 0) {
		if (e % 2) x = (x * b) % m;
		b = (b * b) % m;
		e /= 2;
	}
	return x % m;
}

ull mfac(ull n, ull m) {
	ull f = 1;
	for (int i = n; i > 1; i--)
		f = (f * i) % m;
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

// tonelli shanks = sqrt(n) % m, m is prime
ll legendre(ll a, ll m){
	if (a % m==0) return 0;
	if (m == 2) return 1;
	return mpow(a,(m-1)/2,m);
}
ll msqrt(ll n, ll m) {
	ll s = __builtin_ctzll(m-1), q = (m-1ll)>>s, z = rand()%(m-1)+1;
	if (m == 2) return 1;
	if (s == 1) return mpow(n,(m+1)/4ll,m);
	while (legendre(z,m)!=m-1) z = rand()%(m-1)+1;
	ll c = mpow(z,q,m), r = mpow(n,(q+1)/2,m), t = mpow(n,q,m), M = s;
	while (t != 1){
		ll i=1, ts = (t * t) % m;
		while (ts != 1) i++, ts = (ts * ts) % m;
		ll b = c;
		for (int j = 0; j < M-i-1; j++) b = (b * b) % m;
		r = r * b % m; c = b * b % m; t = t * c % m; M = i;
	}
	return r;
}