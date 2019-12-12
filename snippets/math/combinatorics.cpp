ull nPr(ull n, ull r) {
	ull v = 1;
	for (int i = n-r + 1; i <= n; i++)
		v *= i;
	return v;
}