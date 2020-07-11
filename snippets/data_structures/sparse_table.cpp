template<class T> struct SparseTable {
	vector<vector<T>> m;
	SparseTable(vector<T> arr) {
		m.push_back(arr);
		for (int k = 1; (1<<(k)) <= size(arr); k++) {
			m.push_back(vector<T>(size(arr)-(1<<k)+1));
			for (int i = 0; i < size(arr)-(1<<k)+1; i++)
				m[k][i] = min(m[k-1][i], m[k-1][i+(1<<(k-1))]);
		}
	}
	// min of range [l,r]
	T query(int l, int r) {
		int k = __lg(r-l+1);
		return min(m[k][l], m[k][r-(1<<k)+1]);
	}
};