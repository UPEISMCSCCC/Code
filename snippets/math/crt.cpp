#define ll long long

bool ecrt(ll* r, ll* m, int n, ll& re, ll& mo) {
	ll x, y, d; mo = m[0]; re = r[0];
	for (int i = 1; i < n; i++) {
		d = egcd(mo, m[i], x, y);
		if ((r[i] - re) % d != 0) return false;
		x = (r[i] - re) / d * x % (m[i] / d);
		re += x * mo;
		mo = mo / d * m[i];
		re %= mo;
	}
	re = (re + mo) % mo;
	return true;
}