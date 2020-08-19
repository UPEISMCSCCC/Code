ostream& operator<<(ostream& o, unsigned __int128 n) {
	auto t = n<0 ? -n : n; char b[128], *d = end(b);
	do *--d = '0'+t%10, t /= 10; while (t);
	o.rdbuf()->sputn(d,end(b)-d);
	return o;
}
ostream& operator<<(ostream& o, __int128 n) {
	if (n < 0) return o << '-' << (unsigned __int128)n;
	return o << (unsigned __int128)n;
}