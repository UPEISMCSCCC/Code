#include <unordered_map>
#include <cmath>

#define ll long long

int discretelog(int a, int b, int m) {
	ll n = sqrt(m)+1, an = 1;
	for (int i = 0; i < n; i++)
		an = (an * a) % m;
	
	unordered_map<int, int> v;
	ll c = an;
	for (int i = 1; i <= n; i++) {
		if (!v.count(c)) v[c] = i;
		c = (c * an) % m;
	}
	
	c = b;
	for (int i = 0; i <= n; i++) {
		if (v.count(c)) return (v[c] * n - i + m - 1) % (m-1);
		c = (c * a) % m;
	}
	return -1;
}
