#define ll long long

ll egcd(ll a, ll b, ll& x, ll& y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	ll gcd = egcd(b, a % b, x, y);
	x -= a / b * y;
	ll swap = y; y = x; x = swap;
	return gcd;
}