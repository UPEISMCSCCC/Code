struct defint { int i = -1; };
vector<int> boyermoore(string txt, string pat) {
	vector<int> toret; unordered_map<char, defint> badchar;
	int m = pat.size(), n = txt.size();
	for (int i = 0; i < m; i++) badchar[pat[i]].i = i;
	int s = 0;
	while (s <= n - m) {
		int j = m - 1;
		while (j >= 0 && pat[j] == txt[s + j]) j--;
		if (j < 0) {
			toret.push_back(s);
			s += (s + m < n) ? m - badchar[txt[s + m]].i : 1;
		} else
			s += max(1, j - badchar[txt[s + j]].i);
	}
	return toret;
}