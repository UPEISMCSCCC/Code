// closest pair of a set of integer points
// reasonably fast nlogn sourced from https://github.com/kth-competitive-programming/kactl/blob/master/content/geometry/ClosestPair.h
// modified for use with just std::pair
// solves https://open.kattis.com/problems/closestpair2 and https://open.kattis.com/problems/closestpair1 both in <0.3s
// use with ordered set (pbds) for possible speedup
#define point pair<ll,ll>
#define dist2(pt) ((pt).first*(pt).first+(pt).second*(pt).second)

pair<point, point> closest(vector<point> &v) {
    set<point> S;
    const auto cmp = [](const point &a, const point &b) { return a.second < b.second; };
    sort(v.begin(), v.end(), cmp);
    pair<ll, pair<point, point>> ret = {LLONG_MAX, {point(), point()}};
    int j = 0;
    for (point p : v) {
        point d(1 + (ll)sqrt(ret.first), 0);
        while (v[j].second <= p.second - d.first) S.erase(v[j++]);
        auto pmd = point(p.first-d.first, p.second-d.second);
        auto ppd = point(p.first+d.first, p.second+d.second);
        auto lo = S.lower_bound(pmd), hi = S.upper_bound(ppd);
        for (; lo != hi; ++lo) {
            auto lmp = point(lo->first - p.first, lo->second - p.second);
            ret = min(ret, pair<ll, pair<point, point>>(dist2(lmp), {*lo, p}));
        }
        S.insert(p);
    }
    return ret.second;
}
