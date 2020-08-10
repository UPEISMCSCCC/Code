typedef long long T;
const T range = 10000;

/*
given N points with coordinates in [-range, range]
compute the size of the largest subset of the points
for which all points in the subset are colinear.
Time: O(N^2 log(range)) average
Solves https://open.kattis.com/problems/maxcolinear in 0.62s (not amazing)
*/

struct Slope { // a rational number with unsigned infinity (1,0)
    T p, q;
    
    Slope(T pP=T(), T qP=T()) {
        if(qP==0) {
            p = 1, q = 0;
            return;
        }
        T g = __gcd(pP, qP);
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

int max_colinear_points(vector<pair<T,T>> &points) {
    if(points.size() <= 2) return points.size();
    int best = 0;
    unordered_map<Slope, int> counter;
    for(int i=0;i<points.size();i++) {
        for(int j=i+1;j<points.size();j++) {
            if(i!=j) {
                Slope slope(points[i].second-points[j].second,points[i].first-points[j].first);
                best = max(best, ++counter[slope]+1);
            }
        }
        if(i != points.size()-1) counter.clear();
    }
    return best;
}
