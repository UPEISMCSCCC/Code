#include "../test_header.h"
#include "../../snippets/math/digitcount.cpp"

ll naive(ll n, ll d) {
	ll c = 0;
	for (ll i = 0; i <= n; i++) {
		ll v = i;
		while (v > 0) {
			c += v % 10 == d;
			v /= 10;
		}
	}
	return c;
}

int main() {
	assert(digit_count(0, 1) == 0);
	assert(digit_count(100, 0) == 2);
	assert(digit_count(100, 1) == 1);
	assert(digit_count(123, 1) == 1);
	assert(digit_count(999, 1) == 0);
	
	assert(count(0, 1) == naive(0, 1));
	assert(count(1, 1) == naive(1, 1));
	assert(count(1, 0) == naive(1, 0));
	assert(count(500, 1) == naive(500, 1));
	assert(count(999, 9) == naive(999, 9));
	assert(count(100, 0) == naive(100, 0));
}