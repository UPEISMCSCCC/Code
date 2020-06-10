#include "../../tests/test_header.h"

#ifdef _WIN32
#define putchar_unlocked(x) _putchar_nolock(x)
#endif

struct GC {
	char buf[1 << 16];
	size_t bc = 0, be = 0;
	char operator()() {
		if (bc >= be) {
			buf[0] = 0, bc = 0;
			be = fread(buf, 1, sizeof(buf), stdin);
		}
		return buf[bc++];
	}
} getchar_buffer;

void read(unsigned int& n) {
	char c; n = 0;
	while ((c=getchar_buffer())!=' '&&c!='\n')
		n = n * 10 + c - '0';
}

void print(unsigned int n) {
	if (n / 10) print(n / 10);
	putchar_unlocked(n % 10 + '0');
}

int main() {
	unsigned int c = 0, v = 0;
	for (int i = 0; i < 1000000; i++) {
		read(v);
		c += v;
	}
	print(c);
}