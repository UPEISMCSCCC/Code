#define point complex<double>
#define sq(a) ((a)*(a))
#define cb(a) ((a)*(a)*(a))

double dot(point a, point b) { return real(conj(a)*b); }
double cross(point a, point b) { return imag(conj(a)*b); }

struct line { point a, b; };
struct circle { point c; double r; };
struct segment { point a, point b; };
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

// triangle methods
double area_heron(double a, double b, double c) {
	if (a < b) swap(a, b);
	if (a < c) swap(a, c);
	if (b < c) swap(b, c);
	if (a > b + c) return -1;
	return sqrt((a+b+c)*(c-a+b)*(c+a-b)*(a+b-c)/16.0);
}

// segment methods
double lengthsq(segment a) { return sq(real(a.a) - real(a.b)) + sq(imag(a.a) - imag(a.b)); }
double length(segment a) { return sqrt(lengthsq(a)); }

// circle methods
double circumference(circle a) { return 2 * a.r * M_PI; }
double area(circle a) { return sq(a.r) * M_PI; }

// rectangle methods
double width(rectangle a) { return abs(real(a.br) - real(a.tl)); }
double height(rectangle a) { return abs(imag(a.br) - real(a.tl)); }
double diagonal(rectangle a) { return sqrt(sq(width(a)) + sq(height(a))); }
double area(rectangle a) { return width(a) * height(a); }
double perimeter(rectangle a) { return 2 * (width(a) + height(a)); }
// check if `a` fit's inside `b`
// swap equalities to exclude tight fits
bool doesFitInside(rectangle a, rectangle b) {
	int x = width(a), w = width(b), y = height(a), h = height(b);
	if (x > y) swap(x, y);
	if (w > h) swap(w, h);
	if (w < x) return false;
	if (y <= h) return true;
	double a=sq(y)-sq(x), b=x*h-y*w, c=x*w-y*h;
	return sq(a) <= sq(b) + sq(c);
}
