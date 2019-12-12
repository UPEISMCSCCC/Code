ull nPr(ull n, ull r) {
	ull v = 1;
	for (ull i = n-r+1; i <= n; i++)
		v *= i;
	return v;
}

ull nPr(ull n, ull r, ull m) {
	ull v = 1;
	for (ull i = n-r+1; i <= n; i++)
		v = (v * i) % m;
	return v;
}

ull nCr(ull n, ull r) {
	long double v = 1;
	for (ull i = 1; i <= r; i++)
		v = v * (n-r+i) /i;
	return (ull)(v + 0.001);
}
