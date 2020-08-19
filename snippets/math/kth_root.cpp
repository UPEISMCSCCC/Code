struct KthRoot {
	vector<ull> pow[65]; // pow[k][x] = pow(x+2,k)  (k >= 4)
	KthRoot() {
		for (ull t = 2; t < (1<<16); t++) {
			ull s = t*t; s = s*s;
			for (int k = 4; ; k++) {
				pow[k].push_back(s);
				if (__builtin_umulll_overflow(s,t,&s)) break;
			}
		}
	}
	ull sqrt(ull n) const {
		if (n == -1ull) return (unsigned int)(-1);
		ull x = std::sqrt((double)n);
		return x*x > n ? x-1 : x;
	}
	ull cbrt(ull n) const {
		ull x = 0, y = 0;
		for (int s = 63; s >= 0; s -= 3) {
			x <<= 1;
			y = 3*x*(x+1)+1;
			if (y <= (n>>s)) n -= y<<s, x++;
		}
		return x;
	}
	// returns floor(n^(1/k)), k >= 1
	ull operator()(ull n, int k) {
		if (k == 1 || n == 0) return n;
		if (k == 2) return sqrt(n);
		if (k == 3) return cbrt(n);
		auto ub = upper_bound(pow[k].begin(), pow[k].end(), n);
		return (ub-pow[k].begin())+1;
	}
};