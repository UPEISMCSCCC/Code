struct point3d {
	double x, y, z;
	point3d operator+(point3d a) const { return {x+a.x, y+a.y, z+a.z}; }
	point3d operator*(double a) const { return {x*a, y*a, z*a}; }
	point3d operator-() const { return {-x, -y, -z}; }
	point3d operator-(point3d a) const { return *this + -a; }
	point3d operator/(double a) const { return *this * (1/a); }
	double norm() { return x*x + y*y + z*z; }
	double abs() { return sqrt(norm()); }
	point3d normalize() { return *this / this->abs(); }
};

double dot(point3d a, point3d b) { return a.x*b.x + a.y*b.y + a.z*b.z; }
point3d cross(point3d a, point3d b) { return {a.y*b.z - a.z*b.y, a.z*b.x - a.x*b.z, a.x*b.y - a.y*b.x}; }

struct line3d { point3d a, b; };
struct plane { double a, b, c, d; } // a*x + b*y + c*z + d = 0
struct sphere { point3d c; double r; };

#define sq(a) ((a)*(a))
#define cb(a) ((a)*(a)*(a))
double surface(circle a) { return 4 * sq(a.r) * M_PI; }
double volume(circle a) { return 4.0/3.0 * cb(a.r) * M_PI; }
