#define point complex<double>
#define sq(a) ((a)*(a))
#define cb(a) ((a)*(a)*(a))

double dot(point a, point b) { return real(conj(a)*b); }
double cross(point a, point b) { return imag(conj(a)*b); }

struct line { point a, b; };
struct circle { point c; double r; };
struct triangle { point a, b, c; };
struct rectangle { point tl, br; };

struct convex_polygon {
	vector<point> points;
	convex_polygon(triangle a) {
		points.push_back(a.a); points.push_back(a.b); points.push_back(a.c);
	};
	convex_polygon(rectangle a) {
		points.push_back(a.tl); points.push_back({real(a.tl), imag(a.br)});
		points.push_back(a.br); points.push_back({real(a.br), imag(a.tl)});
	}
};

struct polygon {
	vector<point> points;
	polygon(triangle a) {
		points.push_back(a.a); points.push_back(a.b); points.push_back(a.c);
	}
	polygon(rectangle a) {
		points.push_back(a.tl); points.push_back({real(a.tl), imag(a.br)});
		points.push_back(a.br); points.push_back({real(a.br), imag(a.tl)});
	}
	polygon(convex_polygon a) {
		for (point v : a.points)
			points.push_back(v);
	}
};

double lengthsq(line a) { return sq(real(a.a) - real(a.b)) + sq(imag(a.a) - imag(a.b)); }
double length(line a) { return sqrt(lengthsq(a)); }
// -1 coincide, 0 parallel, 1 intersection
int intersection(line a, line b, point& p) {
	if (abs(cross(a.b - a.a, b.b - b.a)) > EPS) {
		p = cross(b.a - a.a, b.b - a.b) / cross(a.b - a.a, b.b - b.a) * (b - a) + a;
		return 1;
	}
	if (abs(cross(a.b - a.a, a.b - b.a)) > EPS) return 0;
	return -1;
}

double circumference(circle a) { return 2 * a.r * M_PI; }
double area(circle a) { return sq(a.r) * M_PI; }
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

double intersection(rectangle a, rectangle b) {
	double x1 = max(real(a.tl), real(b.tl)), y1 = max(imag(a.tl), imag(b.tl));
	double x2 = min(real(a.br), real(b.br)), y2 = min(imag(a.br), imag(b.br));
	return (x2 <= x1 || y2 <= y1) ? 0 : (x2-x1)*(y2-y1);
}
double width(rectangle a) { return abs(real(a.br) - real(a.tl)); }
double height(rectangle a) { return abs(imag(a.br) - real(a.tl)); }
double diagonal(rectangle a) { return sqrt(sq(width(a)) + sq(height(a))); }
double area(rectangle a) { return width(a) * height(a); }
double perimeter(rectangle a) { return 2 * (width(a) + height(a)); }
