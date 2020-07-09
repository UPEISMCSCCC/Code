template<class T> struct MatrixSum {
	Vec<2, T> p;
	MatrixSum(Vec<2, T>& v) {
		p = Vec<2,T>(v.size()+1, v[0].size()+1);
		for (int i = 0; i < v.size(); i++)
			for (int j = 0; j < v[0].size(); j++)
				p[i+1][j+1] = v[i][j] + p[i][j+1] + p[i+1][j] - p[i][j];
	}
	T sum(int u, int l, int d, int r) {
		return p[d][r] - p[d][l] - p[u][r] + p[u][l];
	}
};