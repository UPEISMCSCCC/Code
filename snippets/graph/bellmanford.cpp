const int inf = 20000001;

vector<ll> bellman_ford(vector<edge> edges, int src, int V) { 
	vector<ll> D(V,inf);
	D[src] = 0;
	for (int i=1;i<=V-1;i++)
		for (edge e : edges)
			if (D[e.u] != inf && D[e.u] + e.w < D[e.v]) 
				D[e.v] = D[e.u] + e.w;
	// detect negative cycles: *typically* 2 is as good as V-1 for this
	for (int i=1;i<=V-1;i++)
		for (edge e : edges)
			if (D[e.u] != inf && D[e.u] + e.w < D[e.v]) 
				D[e.v] = -inf;
	return D;
}
