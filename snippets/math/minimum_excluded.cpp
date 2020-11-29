// simple mex of a set
int mex(set<int>& s) {
	auto i = s.begin(); int v = 0;
	while (i != s.end() && *i == val) i++, v++;
	return v;
}

// advanced mex
struct MEX {
    set<int> a, b = {0};
    void add(int v) {
        a.insert(v);
        if (b.count(v)) b.erase(v);
        if (a.count(v+1) == 0) b.insert(v+1);
    }
    void del(int v) {
        a.erase(v);
        b.erase(v+1);
        if (v > 0 && a.count(v-1)) b.insert(v);
    }
    // find mex >= v
    int query(int v) {
        if (a.count(v) == 0) return v;
        return *(b.lower_bound(v));
    }
    // find mex >= 0
    int query() {
        return *(b.begin());
    }
};
