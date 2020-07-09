using iter = vector<int>::iterator;
struct WaveletTree {
	Vec<2, int> C; int s;
	// sigma = highest value + 1
	WaveletTree(vector<int>& a, int sigma) : s(sigma), C(sigma*2, 0) {
		build(a.begin(), a.end(), 0, s-1, 1);
	}
	void build(iter b, iter e, int L, int U, int u) {
		if (L == U) return;
		int M = (L+U)/2;
		C[u].reserve(e-b+1); C[u].push_back(0);
		for (auto it = b; it != e; ++it)
			C[u].push_back(C[u].back() + (*it<=M));
		auto p = stable_partition(b, e, [=](int i){return i<=M;});
		build(b, p, L, M, u*2);
		build(p, e, M+1, U, u*2+1);
	}
	
	// number of occurences of x in [0,i)
	int rank(int x, int i) {
		int L = 0, U = s-1, u = 1, M, r;
		while (L != U) {
			M = (L+U)/2;
			r = C[u][i]; u*=2;
			if (x <= M) i = r, U = M;
			else i -= r, L = M+1, ++u;
		}
		return i;
	}
	// number of occurences of x in [l,r)
	int count(int x, int l, int r) {
		return rank(x, r) - rank(x, l);
	}
	
	// kth smallest in [l, r)
	int kth(int k, int l, int r) const {
		int L = 0, U = s-1, u = 1, M, ri, rj;
		while (L != U) {
			M = (L+U)/2;
			ri = C[u][l]; rj = C[u][r]; u*=2;
			if (k <= rj-ri) l = ri, r = rj, U = M;
			else k -= rj-ri, l -= ri, r -= rj,
			L = M+1, ++u;
		}
		return U;
	}
	
	// # elements between [x,y] in [l, r)
	mutable int L, U;
	int range(int x, int y, int l, int r) const {
		if (y < x or r <= l) return 0;
		L = x; U = y;
		return range(l, r, 0, s-1, 1);
	}
	int range(int l, int r, int x, int y, int u) const {
		if (y < L or U < x) return 0;
		if (L <= x and y <= U) return r-l;
		int M = (x+y)/2, ri = C[u][l], rj = C[u][r];
		return range(ri, rj, x, M, u*2) + range(l-ri, r-rj, M+1, y, u*2+1);
	}
	// # elements <= x in [l, r)
	int lte(int x, int l, int r) {
		return range(INT_MIN, x, l, r);
	}
};