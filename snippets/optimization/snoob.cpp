// SameNumberOfOneBits, next permutation
int snoob(int a) {
	int b = a & -a, c = a + b;
	return c | ((a ^ c) >> 2) / b;
}
// example usage
int main() {
	char l1[] = {'1', '2', '3', '4', '5'};
	char l2[] = {'a', 'b', 'c', 'd'};
	int d1 = 5, d2 = 4;
	// prints 12345abcd, 1234a5bcd, ...
	int min = (1<<d1)-1, max = min << d2;
	for (int i = min; i <= max; i = snoob(i)) {
		int p1 = 0, p2 = 0, v = i;
		while (p1 < d1 || p2 < d2) {
			cout << ((v & 1) ? l1[p1++] : l2[p2++]);
			v /= 2;
		}
		cout << '\n';
	}
}