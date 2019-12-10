// ax^2 + bx + c = 0, find x
vector<double> solveEq(double a, double b, double c) {
	vector<double> r;
	double z = b * b - 4 * a * c;
	if (z == 0)
		r.push_back(-b/(2*a));
	else if (z > 0) {
		r.push_back((sqrt(z)-b)/(2*a));
		r.push_back((sqrt(z)+b)/(2*a));
	}
	return r;
}