struct edge {
	int u,v,w;
	edge (int u,int v,int w) : u(u),v(v),w(w) {}
	edge () : u(0), v(0), w(0) {}
};
bool operator < (const edge &e1, const edge &e2) { return e1.w < e2.w; }
bool operator > (const edge &e1, const edge &e2) { return e1.w > e2.w; }

struct subset {
	int p, rank, sz;
	subset(int p) : p(p), rank(0), sz(1) {}
	subset() : p(0), rank(0), sz(0) {}
	void make_set(int _p) { p=_p, rank=0, sz=1; }
};
