bool isPowerOf2(ll a) {
	return a > 0 && !(a & a-1);
}
bool isPowerOf3(ll a) {
	return a>0&&!(12157665459056928801ull%a);
}
bool isPower(ll a, ll b) {
	double x = log(a) / log(b);
	return abs(x-round(x)) < 0.00000000001;
}