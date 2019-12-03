// digits in factorial
#define kamenetsky(n) (floor((n * log10(n / M_E)) + (log10(2 * M_PI * n) / 2.0)) + 1)

// approximation of factorial
#define stirling(n) ((n == 1) ? 1 : sqrt(2 * M_PI * n) * pow(n / M_E, n))

// natural log of factorial
#define lfactorial(n) (lgamma(n+1))
