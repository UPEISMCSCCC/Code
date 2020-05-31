// c = array size, n = nth perm, return index
vector<int> gen_permutation(int c, int n) {
	vector<int> idx(c), per(c), fac(c); int i;
	for (i = 0; i < c; i++) idx[i] = i;
	for (i = 1; i <= c; i++) fac[i-1] = n%i, n/=i;
	for (i = c - 1; i >= 0; i--)
		per[c-i-1] = idx[fac[i]],
		idx.erase(idx.begin() + fac[i]);
	return per;
}