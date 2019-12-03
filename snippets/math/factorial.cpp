// digits in factorial
int kamenetsky(int n) {
	return floor((n * log10(n / M_E)) + (log10(2 * M_PI * n) / 2.0)) + 1;
}

// approximation of factorial
int stirlings(int n) {
	return (n == 1) ? 1 : sqrt(2 * M_PI * n) * pow(n / M_E, n);
}

// log of factorial
double logfact(int n) {
	return lgamma(n+1);
}