/*count(n,d) counts the number of occurences of a digit d in the range [0,n]*/
ll digit_count(ll n, ll d) {
	ll result = 0;
	while (n != 0) {
		result += ((n%10) == d ? 1 : 0);
		n /= 10;
	}
	return result;
}

ll count(ll n, ll d) {
	if (n < 10) return (d > 0 && n >= d);
	if ((n % 10) != 9) return digit_count(n, d) + count(n-1, d);
	return 10*count(n/10, d) + (n/10) + (d > 0);
}
