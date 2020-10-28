#define point complex<int>

namespace std {
    inline bool operator < (const point &a, const point b) {
        if (abs(real(a) - real(b)) > EPS) return real(a) < real(b);
        if (abs(imag(a) - imag(b)) > EPS) return imag(a) < imag(b);
        return false;
    }
};

convex_polygon convexhull(polygon a, bool include_collinear = true) {
    sort(a.points.begin(), a.points.end());
    vector<point> lower, upper;
    auto lt_cmp = [&](point::value_type x, point::value_type y) {return include_collinear ? x<y : x<=y;};
    auto gt_cmp = [&](point::value_type x, point::value_type y) {return include_collinear ? x>y : x>=y;};
    for (int i = 0; i < a.points.size(); i++) {
        while (lower.size() >= 2 && lt_cmp(cross(lower.back() - lower[lower.size() - 2], a.points[i] - lower.back()), EPS))
            lower.pop_back();
        while (upper.size() >= 2 && gt_cmp(cross(upper.back() - upper[upper.size() - 2], a.points[i] - upper.back()), -EPS))
            upper.pop_back();
        lower.push_back(a.points[i]);
        upper.push_back(a.points[i]);
    }
    lower.insert(lower.end(), upper.rbegin() + 1, upper.rend());
    return convex_polygon(lower);
}
