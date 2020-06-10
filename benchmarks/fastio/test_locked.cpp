#include "../../tests/test_header.h"

void read(unsigned int& n) {
	char c; n = 0;
	while ((c=getchar())!=' '&&c!='\n')
		n = n * 10 + c - '0';
}

void print(unsigned int n) {
	if (n / 10) print(n / 10);
	putchar(n % 10 + '0');
}

int main() {
	unsigned int c = 0, v = 0;
	for (int i = 0; i < 1000000; i++) {
		read(v);
		c += v;
	}
	print(c);
}