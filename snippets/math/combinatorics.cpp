ull nPr(ull n, ull r) {
	ull v = 1;
	for (int i = n-r + 1; i <= n; i++)
		v *= i;
	return v;
}

ull nCr(ull n, ull r) {
	double v = 1;
	for (int i = 1; i <= r; i++)
		v = v * (n-r+i) /i;
	return (ull)(v + 0.001);
}
