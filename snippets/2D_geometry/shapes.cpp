#define point complex<double>
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

#define sq(a) ((a)*(a))
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
	if (d2 > rS * rS) return -1;
	if (d2 < rD * rD) return 0;
	double ca = 0.5 * (1 + rS * rD / d2);
	point z = point(ca, sqrt(a.r * a.r / d2 - ca * ca));
	inter.push_back(a.c + (b.c - a.c) * z);
	if (abs(imag(z)) > EPS) inter.push_back(a.c + (b.c - a.c) * conj(z));
	return inter.size();
}
vector<point> intersection(line a, circle c) {
	vector<point> inter;
	c.c -= a;
	b -= a;
	point m = b * real(c.c / b);
	double d2 = norm(m - c.c);
	if (d2 > c.r * c.r) return 0;
	double l = sqrt((c.r * c.r - d2) / norm(b));
	inter.push_back(a + m + l * b);
	if (abs(l) > EPS) inter.push_back(a + m - l * b);
	return inter;
}

double intersection(rectangle a, rectangle b) {
	double x1 = max(real(a.tl), real(b.tl)), y1 = max(imag(a.tl), imag(b.tl));
	double x2 = min(real(a.br), real(b.br)), y2 = min(imag(a.br), imag(b.br));
	return (x2 <= x1 || y2 <= y1) ? 0 : (x2-x1)*(y2-y1);
}
double width(rectangle a) { return abs(real(a.br) - real(a.tl)); }
double height(rectangle a) { return abs(imag(a.br) - real(a.tl)); }
double diagonal(rectangle a) { return sqrt(width(a) * width(a) + height(a) * height(a)); }
double area(rectangle a) { return width(a) * height(a); }
double perimeter(rectangle a) { return 2 * (width(a) + height(a)); }
