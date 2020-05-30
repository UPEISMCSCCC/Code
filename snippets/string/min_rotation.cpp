// simple strings = smaller than its nontrivial suffixes
// lyndon factorization = simple strings factorized
// "abaaba" -> "ab", "aab", "a"
vector<string> duval(string s) {
	int n = s.length();
	vector<string> lyndon;
	for (int i = 0; i < n;) {
		int j = i+1, k = i;
		for (; j < n && s[k] <= s[j]; j++)
			if (s[k] < s[j]) k = i;
			else k++;
		for (; i <= k; i += j - k)
			lyndon.push_back(s.substr(i,j-k));
	}
	return lyndon;
}
// lexicographically smallest rotation
int minRotation(string s) {
	int n = s.length(); s += s;
	auto d = duval(s); int i = 0, a = 0;
	while (a + d[i].length() < n) a += d[i++].length();
	while (i && d[i] == d[i-1]) a -= d[i--].length();
	return a;
}