struct SuffixArray {
	vector<int> sa, lcp;
	SuffixArray(string& s, int lim=256) {
		int n = s.length() + 1, k = 0, a, b;
		vector<int> x(begin(s), end(s)+1), y(n), ws(max(n, lim)), rank(n);
		sa = lcp = y;
		iota(begin(sa), end(sa), 0);
		for (int j = 0, p = 0; p < n; j = max(1, j * 2), lim = p) {
			p = j; iota(begin(y), end(y), n - j);
			for (int i = 0; i < (n); i++)
				if (sa[i] >= j)
					y[p++] = sa[i] - j;
			fill(begin(ws), end(ws), 0);
			for (int i = 0; i < (n); i++) ws[x[i]]++;
			for (int i = 1; i < (lim); i++) ws[i] += ws[i - 1];
			for (int i = n; i--;) sa[--ws[x[y[i]]]] = y[i];
			swap(x, y); p = 1; x[sa[0]] = 0;
			for (int i = 1; i < (n); i++) {
				a = sa[i - 1]; b = sa[i];
				x[b] = (y[a] == y[b] && y[a + j] == y[b + j]) ? p - 1 : p++;
			}
		}
		for (int i = 1; i < (n); i++) rank[sa[i]] = i;
		for (int i = 0, j; i < n - 1; lcp[rank[i++]] = k)
			for (k && k--, j = sa[rank[i] - 1];
				 s[i + k] == s[j + k]; k++);
	}
	// smallest cyclic shift
	int cyclic() { return sa[0]; }
	// longest repeated substring
	pair<int,int> lrs() {
		int length = -1, index = -1;
		for (int i = 0; i < lcp.size(); i++) {
			if (lcp[i] > length) {
				length = lcp[i];
				index = sa[i];
			}
		}
		return {index,length};
	}
	// count distinct substrings, excluding empty
	int distincts() {
		int n = sa.size() - 1, r = n - sa[0];
		for (int i = 1; i < lcp.size(); i++)
			r += (n - sa[i]) - lcp[i - 1];
		return r;
	}
	// count repeated substrings, excluding empty
	int repeateds() {
		int r = 0;
		for (int i = 1; i < lcp.size(); i++)
			r += max(lcp[i] - lcp[i-1], 0);
		return r;
	}
	// burrows wheeler transform
	// sa needs to be sa(s + s), ds = s+s too
	string bwt(string& ds) {
		int n = ds.size();
		string toret;
		for (int i = 0; i < n; i++)
			if (sa[i+1] < n/2)
				toret += ds[sa[i+1] + n/2 - 1];
		return toret;
	}
};