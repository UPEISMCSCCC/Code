#include <algorithm>
#define ull unsigned long long

ull lcm(ull a, ull b) {
	return (a * b) / __gcd(a, b);
}
