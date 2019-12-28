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
