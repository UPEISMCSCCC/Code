#include <algorithm>
#include <vector>
#include <utility>

// generate 0 <= a/b <= 1 ordered, b <= n
// farey(4) = 0/1 1/4 1/3 1/2 2/3 3/4 1/1
// length is sum of phi(i) for i = 1 to n

vector<pair<int, int>> farey(int n) {
	int h = 0, k = 1, x = 1, y = 0, r;
	vector<pair<int, int>> v;
	do {
		v.push_back({h, k});
		r = (n-y)/k;
		y += r*k; x += r*h;
		swap(x,h); swap(y,k);
		x = -x; y = -y;
	} while (k > 1);
	v.push_back({1, 1});
	return v;
}
