vector<int> kmp(string text, string pattern) {
    vector<int> toret;
	int m = text.length(), n = pattern.length();

	int next[n + 1];
	for (int i = 0; i < n + 1; i++)
		next[i] = 0;

	for (int i = 1; i < n; i++) {
		int j = next[i + 1];
		while (j > 0 && pattern[j] != pattern[i])
			j = next[j];
		if (j > 0 || pattern[j] == pattern[i])
			next[i + 1] = j + 1;
	}

	for (int i = 0, j = 0; i < m; i++) {
		if (text[i] == pattern[j]) {
			if (++j == n)
				toret.push_back(i - j + 1);
		} else if (j > 0) {
			j = next[j];
			i--;
		}
	}
	return toret;
}