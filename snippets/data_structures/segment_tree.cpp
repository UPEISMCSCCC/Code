//max(a,b), min(a,b), a+b, a*b, gcd(a,b), a^b
struct SegmentTree {
	typedef int T;
	static constexpr T UNIT = INT_MIN;
	T f(T a, T b) {
		if (a == UNIT) return b;
		if (b == UNIT) return a;
		return max(a,b);
	}
	int n; vector<T> s;
	SegmentTree(int n, T def=UNIT) : s(2*n, def), n(n) {}
	SegmentTree(vector<T> arr) : SegmentTree(arr.size()) {
		for (int i=0;i<arr.size();i++) update(i,arr[i]);
	}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos*2+1]);
	}
	T query(int b, int e) { // query [b, e)
		T ra = UNIT, rb = UNIT;
		for (b+=n, e+=n; b<e; b/=2, e/=2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
	T get(int p) { return query(p, p+1); }
};
