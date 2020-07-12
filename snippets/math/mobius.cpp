const int MAXN = 10000000;
// mu[n] = 0 iff n has no square factors
// 1 if even number of prime factors, -1 for odd
short mu[MAXN] = {0,1};
void mobius(){
	for (int i = 1; i < MAXN; i++)
		if (mu[i])
			for (int j = i + i; j < MAXN;j += i)
				mu[j] -= mu[i];
}