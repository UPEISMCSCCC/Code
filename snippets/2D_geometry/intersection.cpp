// -1 coincide, 0 parallel, 1 intersection
int intersection(line a, line b, point& p) {
	if (abs(cross(a.b - a.a, b.b - b.a)) > EPS) {
		p = cross(b.a - a.a, b.b - a.b) / cross(a.b - a.a, b.b - b.a) * (b - a) + a;
		return 1;
	}
	if (abs(cross(a.b - a.a, a.b - b.a)) > EPS) return 0;
	return -1;
}
// area of intersection
double intersection(circle a, circle b) {
	double d = abs(a.c - b.c);
	if (d <= b.r - a.r) return area(a);
	if (d <= a.r - b.r) return area(b);
	if (d >= a.r + b.r) return 0;
	double alpha = acos((sq(a.r) + sq(d) - sq(b.r)) / (2 * a.r * d));
	double beta = acos((sq(b.r) + sq(d) - sq(a.r)) / (2 * b.r * d));
	return sq(a.r) * (alpha - 0.5 * sin(2 * alpha)) + sq(b.r) * (beta - 0.5 * sin(2 * beta));
}
// -1 outside, 0 inside, 1 tangent, 2 intersection
int intersection(circle a, circle b, vector<point>& inter) {
	double d2 = norm(b.c - a.c), rS = a.r + b.r, rD = a.r - b.r;
	if (d2 > sq(rS)) return -1;
	if (d2 < sq(rD)) return 0;
	double ca = 0.5 * (1 + rS * rD / d2);
	point z = point(ca, sqrt(sq(a.r) / d2 - sq(ca)));
	inter.push_back(a.c + (b.c - a.c) * z);
	if (abs(imag(z)) > EPS) inter.push_back(a.c + (b.c - a.c) * conj(z));
	return inter.size();
}
// points of intersection
vector<point> intersection(line a, circle c) {
	vector<point> inter;
	c.c -= a.a;
	a.b -= a.a;
	point m = a.b * real(c.c / a.b);
	double d2 = norm(m - c.c);
	if (d2 > sq(c.r)) return 0;
	double l = sqrt((sq(c.r) - d2) / norm(a.b));
	inter.push_back(a.a + m + l * a.b);
	if (abs(l) > EPS) inter.push_back(a.a + m - l * a.b);
	return inter;
}
// area of intersection
double intersection(rectangle a, rectangle b) {
	double x1 = max(real(a.tl), real(b.tl)), y1 = max(imag(a.tl), imag(b.tl));
	double x2 = min(real(a.br), real(b.br)), y2 = min(imag(a.br), imag(b.br));
	return (x2 <= x1 || y2 <= y1) ? 0 : (x2-x1)*(y2-y1);
}