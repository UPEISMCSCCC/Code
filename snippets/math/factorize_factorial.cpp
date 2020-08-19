// NOTE: count distinct divisors of n by
// computing (q1+1)*(q2+1)*...*(qk+1)
// where qi are powers of primes pi dividing n
// use that and this code to solve https://open.kattis.com/problems/divisors

// max power of a prime p dividing n!
// O(log(n))
int legendre(int n, int p) {
	int mx = 0;
	while(n>0) n/=p, mx+=n;
	return mx;
}

bitset<10000> sieve;
vector<int> primes;

// get all primes O(n log n)
// if dealing with small numbers
void genPrimes(int n) {
	sieve[0] = sieve[1] = 1;
	primes.push_back(2);
	for (int i = 3; i <= n; i+=2)
		if (i%2 != 0 && !sieve[i]) {
			primes.push_back(i);
			for (int j = i * 3; j <= n; j += i*2)
				sieve[j] = 1;
		}
}

// make sure you call genPrimes first
// return vector of prime factor powers as vector v of size pi(n)
// so that v[i] = power of primes[i] dividing n!
// O(pi(n) * log(n)) where pi(n) is prime counting fn
// so basically O(n) since pi(n) = O(n/log(n))
vector<int> factorize_factorial(int n) {
	vector<int> factorization(primes.size(), 0);
	for(int i=0;i<primes.size() && primes[i] <= n;i++) {
		factorization[i] = legendre(n, primes[i]);
	}
	return factorization;
}

// same thing but for C(n,k)
vector<int> factorize_binom(int n, int k) {
	vector<int> factorization(primes.size(), 0);
	for(int i=0;i<primes.size() && primes[i] <= n;i++) {
		factorization[i] = legendre(n, primes[i]) - legendre(k, primes[i]) - legendre(n-k, primes[i]);
	}
	return factorization;
}
