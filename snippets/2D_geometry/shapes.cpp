#define point complex<double>
double dot(point a, point b) { return real(conj(a)*b); };
double cross(point a, point b) { return imag(conj(a)*b); };

struct circle { point c; double r; };
struct triangle { point a, b, c; };
