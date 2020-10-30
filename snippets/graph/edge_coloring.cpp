// source: kth
vector<int> edge_coloring(int N, vector<pair<int,int>>& eds) {
	vector<int> cc(N + 1), ret(eds.size()), fan(N), fre(N), loc;
	for (auto e : eds) ++cc[e.first], ++cc[e.second];
	int u, v, ncols = *max_element(cc.begin(), cc.end()) + 1;
	vector<vector<int>> adj(N, vector<int>(ncols, -1));
	for (auto e : eds) {
		tie(u, v) = e;
		fan[0] = v;
		loc.assign(ncols, 0);
		int at = u, end = u, d, c = fre[u], ind = 0, i = 0;
		while (d = fre[v], !loc[d] && (v = adj[u][d]) != -1)
			loc[d] = ++ind, cc[ind] = d, fan[ind] = v;
		cc[loc[d]] = c;
		for (int cd = d; at != -1; cd ^= c ^ d, at = adj[at][cd])
			swap(adj[at][cd], adj[end = at][cd ^ c ^ d]);
		while (adj[fan[i]][d] != -1) {
			int left = fan[i], right = fan[++i], e = cc[i];
			adj[u][e] = left;
			adj[left][e] = u;
			adj[right][e] = -1;
			fre[right] = e;
		}
		adj[u][d] = fan[i];
		adj[fan[i]][d] = u;
		for (int y : {fan[0], u, end})
			for (int& z = fre[y] = 0; adj[y][z] != -1; z++);
	}
	for (int i = 0; i < eds.size(); i++)
		for (tie(u, v) = eds[i]; adj[u][ret[i]] != v;) ++ret[i];
	return ret;
}