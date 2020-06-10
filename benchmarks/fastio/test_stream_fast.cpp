#include "../../tests/test_header.h"

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);

void read(unsigned int& n) {
	cin >> n;
}

void print(unsigned int& n) {
	cout << n;
}

int main() {
	fastio;
	
	unsigned int c = 0, v = 0;
	for (int i = 0; i < 1000000; i++) {
		read(v);
		c += v;
	}
	print(c);
}