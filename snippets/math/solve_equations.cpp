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

// ax^3 + bx^2 + cx + d = 0, find x
vector<double> solveEq(double a, double b, double c, double d) {
	vector<double> res;
	long double a1 = b/a, a2 = c/a, a3 = d/a;
	long double q = (a1*a1 - 3*a2)/9.0, sq = -2*sqrt(q);
	long double r = (2*a1*a1*a1 - 9*a1*a2 + 27*a3)/54.0;
	long double z = r*r-q*q*q, theta;
	if (z <= 0) {
		theta = acos(r/sqrt(q*q*q));
		res.push_back(sq*cos(theta/3.0) - a1/3.0);
		res.push_back(sq*cos((theta+2.0*PI)/3.0) - a1/3.0);
		res.push_back(sq*cos((theta+4.0*PI)/3.0) - a1/3.0);
	}
	else {
		res.push_back(pow(sqrt(z)+fabs(r), 1/3.0));
		res[0] = (res[0] + q / res[0]) * ((r<0)?1:-1) - a1 / 3.0;
	}
	return res;
}