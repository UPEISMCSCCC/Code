const ll inf = 1LL << 62;
#define FOR(i,n) for (int i = 0; i < n; i++)
void floydWarshall(Vec<2, ll>& m) {
	int n = m.size();
	FOR(i,n) m[i][i] = min(m[i][i], 0LL);
	FOR(k,n) FOR(i,n) FOR(j,n) if (m[i][k] != inf && m[k][j] != inf) {
		auto newDist = max(m[i][k] + m[k][j], -inf);
		m[i][j] = min(m[i][j], newDist);
	}
	FOR(k,n) if (m[k][k] < 0) FOR(i,n) FOR(j,n)
		if (m[i][k] != inf && m[k][j] != inf) m[i][j] = -inf;
}