// digits in factorial
int kamenetsky(int n) {
	return floor((n * log10(n / M_E)) + (log10(2 * M_PI * n) / 2.0)) + 1;
}

// log of factorial
double logfact(int n) {
	return lgamma(n+1);
}