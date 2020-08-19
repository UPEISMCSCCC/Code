int mex(set<int>& s) {
	auto i = s.begin(); int v = 0;
	while (i != s.end() && *i == val) i++, v++;
	return v;
}