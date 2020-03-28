bool cmp(point a, point b) {
	if (abs(real(a) - real(b)) > EPS) return real(a) < real(b);
	if (abs(imag(a) - imag(b)) > EPS) return imag(a) < imag(b);
	return false;
}
convex_polygon convexhull(polygon a) {
	sort(a.points.begin(), a.points.end(), cmp);
	vector<point> lower, upper;
	for (int i = 0; i < a.points.size(); i++) {
		while (lower.size() >= 2 && cross(lower.back() - lower[lower.size() - 2], a.points[i] - lower.back()) < EPS)
			lower.pop_back();
		while (upper.size() >= 2 && cross(upper.back() - upper[upper.size() - 2], a.points[i] - upper.back()) > -EPS)
			upper.pop_back();
		lower.push_back(a.points[i]);
		upper.push_back(a.points[i]);
	}
	lower.insert(lower.end(), upper.rbegin() + 1, upper.rend());
	return convex_polygon(lower);
}