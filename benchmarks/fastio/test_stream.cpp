#include "../../tests/test_header.h"

void read(unsigned int& n) {
	cin >> n;
}

void print(unsigned int& n) {
	cout << n;
}

int main() {
	unsigned int c = 0, v = 0;
	for (int i = 0; i < 1000000; i++) {
		read(v);
		c += v;
	}
	print(c);
}