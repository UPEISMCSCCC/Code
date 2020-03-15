// SameNumberOfOneBits, next permutation
int snoob(int a) {
	int b = a & -a, c = a + b;
	return c | ((a ^ c) >> 2) / b;
}