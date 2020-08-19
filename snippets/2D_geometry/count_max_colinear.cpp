const ll range = 10000;
struct Slope { // a rational number with unsigned infinity (1,0)
	ll p, q;
	
	Slope(ll pP=0, ll qP=0) {
		if(qP==0) {
			p = 1, q = 0;
			return;
		}
		ll g = __gcd(pP, qP);
		pP /= g, qP /= g;
		if(qP < 0) pP *= -1, qP *= -1;
		p = pP, q = qP;
	}
	
	bool operator== (const Slope &other) const {
		return other.p == p && other.q == q;
	}
};
namespace std {
	template<>
	struct hash<Slope> { // typical rectangular/lattice hash
		size_t operator() (const Slope &r) const {
			return (2*range+1) * (r.p + range) + r.q + range;
		}
	};
}

// n points in [-range, range]
// compute the largest colinear subset
int max_colinear_points(vector<pair<ll,ll>> &points) {
	if(points.size() <= 2) return points.size();
	int best = 0;
	unordered_map<Slope, int> counter;
	for(int i=0;i<points.size();i++) {
		for(int j=i+1;j<points.size();j++) {
			Slope slope(points[i].second-points[j].second,points[i].first-points[j].first);
			best = max(best, ++counter[slope]+1);
		}
		if(i != points.size()-1) counter.clear();
	}
	return best;
}
