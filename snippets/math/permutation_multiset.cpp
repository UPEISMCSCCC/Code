string freq2str(vector<int>& v) {
	string s;
	for (int i = 0; i < v.size(); i++)
		for (int j = 0; j < v[i]; j++)
			s += (char)(i + 'A');
	return s;
}
// nth perm of multiset, n is 0-indexed
string gen_permutation(string s, ll n) {
	vector<int> freq(26, 0);
	for (auto e : s) freq[e - 'A']++;
	for (int i = 0; i < 26; i++) if (freq[i] > 0) {
		freq[i]--; ll v = multinomial(freq);
		if (n < v) return (char)(i+'A') + gen_permutation(freq2str(freq), n);
		freq[i]++; n -= v;
	}
	return "";
}