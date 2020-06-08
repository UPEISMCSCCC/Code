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

// linear diophantine equation ax + by = c, find x and y
// infinite solutions of form x+k*b/g, y-k*a/g
bool solveEq(ll a, ll b, ll c, ll &x, ll &y, ll &g) {
	g = egcd(abs(a), abs(b), x, y);
	if (c % g) return false;
	x *= c / g * ((a < 0) ? -1 : 1);
	y *= c / g * ((b < 0) ? -1 : 1);
	return true;
}

// m = # equations, n = # variables, a[m][n+1] = coefficient matrix
// a[i][0]x + a[i][1]y + ... + a[i][n]z = a[i][n+1]
// find a solution of some kind to linear equation
const double eps = 1e-7;
bool zero(double a) { return (a < eps) && (a > -eps); }
vector<double> solveEq(double **a, int m, int n) {
	int cur = 0;
	for (int i = 0; i < n; i++) {
		for (int j = cur; j < m; j++) {
			if (!zero(a[j][i])) {
				if (j != cur) swap(a[j], a[cur]);
				for (int sat = 0; sat < m; sat++) {
					if (sat == cur) continue;
					double num = a[sat][i] / a[cur][i];
					for (int sot = 0; sot <= n; sot++)
						a[sat][sot] -= a[cur][sot] * num;
				}
				cur++;
				break;
			}
		}
	}
	for (int j = cur; j < m; j++)
		if (!zero(a[j][n])) return vector<double>();
	vector<double> ans(n,0);
	for (int i = 0, sat = 0; i < n; i++)
		if (sat < m && !zero(a[sat][i]))
			ans[i] = a[sat][n] / a[sat++][i];
	return ans;
}

// solve A[n][n] * x[n] = b[n] linear equation
// rank < n is multiple solutions, -1 is no solutions
// `alls` is whether to find all solutions, or any
const double eps = 1e-12;
int solveEq(Vec<2, double>& A, Vec<1, double>& b, Vec<1, double>& x, bool alls=false) {
	int n = A.size(), m = x.size(), rank = 0, br, bc;
	vector<int> col(m); iota(begin(col), end(col), 0);
	for(int i = 0; i < n; i++) {
		double v, bv = 0;
		for(int r = i; r < n; r++)
			for(int c = i; c < n; c++)
				if ((v = fabs(A[r][c])) > bv)
					br = r, bc = c, bv = v;
		if (bv <= eps) {
			for(int j = i; j < n; j++)
				if (fabs(b[j]) > eps)
					return -1;
			break;
		}
		swap(A[i], A[br]);
		swap(b[i], b[br]);
		swap(col[i], col[bc]);
		for(int j = 0; j < n; j++)
			swap(A[j][i], A[j][bc]);
		bv = 1.0 / A[i][i];
		for(int j = (alls)?0:i+1; j < n; j++) {
			if (j != i) {
				double fac = A[j][i] * bv;
				b[j] -= fac * b[i];
				for(int k = i+1; k < m; k++)
					A[j][k] -= fac*A[i][k];
			}
		}
		rank++;
	}
	if (alls) for (int i = 0; i < m; i++) x[i] = -DBL_MAX;
	for (int i = rank; i--;) {
		bool isGood = true;
		if (alls)
			for (int j = rank; isGood && j < m; j++)
				if (fabs(A[i][j]) > eps)
					isGood = false;
		b[i] /= A[i][i];
		if (isGood) x[col[i]] = b[i];
		if (!alls)
			for(int j = 0; j < i; j++)
				b[j] -= A[j][i] * b[i];
	}
	return rank;
}