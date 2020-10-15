// given a set of N unique points, a distance metric, and an integer S
// returns the smallest D such that the points can be divided into at
// most S subsets, with each subset having a spanning tree with max edge weight <=D
// relies on union find, uses a binary search to get O(N^2 * \alpha(N) * log(maxD))
// where maxD is the maximum distance (diameter) of the set.
// the log(maxD) term grows linearly with increasing number of digits needed for EPS
// solves https://open.kattis.com/problems/arcticnetwork, works with EPS<=1 at least

#define point complex<int>
// eps is the precision needed for the returned D
#define EPS 0.01

// can be modified to any metric
double dist(point p, point q) {
	point x = p-q;
	return (real(x)*real(x)+imag(x)*imag(x));
}

// true if D is a upper bound on the answer
bool works(vector<point> &A, double D, int S) {
	int n = A.size();
	subset *s = new subset[n];
	for(int i=0;i<n;i++) s[i] = subset(i);
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			if(dist(A[i],A[j]) <= D)
				uf_union(s, i, j);
	vector<bool> marked(n, false);
	int components = 0;
	for(int i=0;i<n;i++) {
		int f = uf_find(s,i);
		if(!marked[f]) {
			marked[f] = true;
			components++;
		}
	}
	return components <= S;
}

// finds the minimum answer via binary search
double find_max_dist_needed(vector<point> &A, int S) {
	double hi = 0, lo = 0;
	int n = A.size();
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++) hi = fmax(hi, dist(A[i],A[j]));
	while(hi-lo >= EPS) {
		double mid = (hi+lo)/2;
		if(works(A,mid,S)) hi = mid;
		else lo = mid;
	}
	return hi;
}
