// F(n) = c[0]*F(n-1) + c[1]*F(n-2) + ...
// b is the base cases of same length c
ll matrix_exponentiation(ll n, vector<ll> c, vector<ll> b) {
	if (nth < b.size()) return b[nth-1];
	Mat<ll> a(c.size(), c.size()); ll s = 0;
	for (int i = 0; i < c.size(); i++) a[i][0] = c[i];
	for (int i = 0; i < c.size() - 1; i++) a[i][i+1] = 1;
	a = a.power(nth - c.size());
	for (int i = 0; i < c.size(); i++)
		s += a[i][0] * b[i];
	return s;
}