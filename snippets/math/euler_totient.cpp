int phi(int n) {
	int r = n;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) r -= r / i;
		while (n % i == 0) n /= i;
	}
	if (n > 1) r -= r / n;
	return r;
}

#define n 100000
ll phi[n+1]; 
void computeTotient() { 
	for (int i=1; i<=n; i++) phi[i] = i;
	for (int p=2; p<=n; p++) { 
		if (phi[p] == p) { 
			phi[p] = p-1; 
			for (int i = 2*p; i<=n; i += p) phi[i] = (phi[i]/p) * (p-1); 
		} 
	} 
}
