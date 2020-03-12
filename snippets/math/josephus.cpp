// 0-indexed, arbitrary k
int josephus(int n, int k) {
    if (n == 1) return 0;
    if (k == 1) return n-1;
    if (k > n) return (josephus(n-1,k)+k)%n;
    int res = josephus(n-n/k,k)-n%k;
    return res + ((res<0)?n:res/(k-1));
}

// fast case if k=2, traditional josephus
int josephus(int n) {
	return 2*(n-(1<<(32-__builtin_clz(n)-1)));
}