ll tetraloop(ll a, ll b, ll m) {
	if(b == 0 || a == 1) return 1;
	ll w = tetraloop(a,b-1,phi(m)), r = 1;
	for (;w;w/=2) {
		if (w&1) {
			r *= a; if (r >= m) r -= (r/m-1)*m;
		}
		a *= a; if (a >= m) a -= (a/m-1)*m;
	}
	return r;
}
int tetration(int a, int b, int m) {
	if (a == 0 || m == 1) return ((b+1)&1)%m;
	return tetraloop(a,b,m) % m;
}