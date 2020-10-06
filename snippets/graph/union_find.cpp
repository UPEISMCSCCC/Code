int uf_find(subset* s, int i) {
	if (s[i].p != i) s[i].p = uf_find(s, s[i].p);
	return s[i].p;
}

void uf_union(subset* s, int x, int y) {
	int xp = uf_find(s, x), yp = uf_find(s, y);
	if (s[xp].rank > s[yp].rank) s[yp].p = xp, s[xp].sz += s[yp].sz;
	else if (s[xp].rank < s[yp].rank) s[xp].p = yp, s[yp].sz += s[xp].sz;
	else s[yp].p = xp, s[xp].rank++, s[xp].sz += s[yp].sz;
}

int uf_size(subset *s, int i) {
	return s[uf_find(s, i)].sz;
}
