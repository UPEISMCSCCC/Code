#include <unordered_map>
#include <cmath>

#define ll long long

unordered_map<int, int> dlogc;
int discretelog(int a, int b, int m) {
	dlogc.clear();
	ll n = sqrt(m)+1, an = 1;
	for (int i = 0; i < n; i++)
		an = (an * a) % m;
	
	ll c = an;
	for (int i = 1; i <= n; i++) {
		if (!dlogc.count(c)) dlogc[c] = i;
		c = (c * an) % m;
	}
	
	c = b;
	for (int i = 0; i <= n; i++) {
		if (dlogc.count(c)) return (dlogc[c] * n - i + m - 1) % (m-1);
		c = (c * a) % m;
	}
	return -1;
}
