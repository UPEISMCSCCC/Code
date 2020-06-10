#include "../../tests/test_header.h"

void read(unsigned int& n) {
	scanf("%u", &n);
}

void print(unsigned int& n) {
	printf("%u", n);
}

int main() {
	unsigned int c = 0, v = 0;
	for (int i = 0; i < 1000000; i++) {
		read(v);
		c += v;
	}
	print(c);
}