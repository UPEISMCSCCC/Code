#define HASHER 27
ull basicHash(string s) {
	ull v = 0, b = 1;
	for (auto c : s) {
		v += (c - 'a') * b;
		b *= HASHER;
	}
	return v;
}