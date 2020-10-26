#define sq(a) ((a)*(a))
double dist2(point a) { return sq(real(a))+sq(imag(a)); }

// returns diameter (max pairwise distance) of points on a convex hull.
// needs that all points are distinct and none are collinear
// takes time linear in the size of the hull
pair<point,point> hull_diameter(convex_polygon poly) {
    vector<point> &S = poly.points;
    if(S.size() < 2) return {point(), point()};
    int n = S.size(), j = 1;
    pair<ll, pair<point,point>> res({0, {S[0], S[0]}});
    for(int i=0;i<j;i++)
        for (;; j = (j + 1) % n) {
            res = max(res, pair<ll,pair<point,point>>(dist2(S[i] - S[j]), {S[i], S[j]}));
            if (cross(S[(j + 1) % n] - S[j], S[i + 1] - S[i]) >= 0)
                break;
        }
    return res.second;
}

// wraps the hull_diameter, so it works for any set of points
// relies on the convex_hull code, so O(nlogn) total
pair<point,point> farthest_pair(vector<point> &V) {
    return hull_diameter(convexhull(polygon(V), false));
}
