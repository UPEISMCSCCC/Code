// l is array of palindrome length at that index
int manacher(string s, int* l) {
	int n = s.length() * 2;
	for (int i = 0, j = 0, k; i < n; i += k, j = max(j-k, 0)) {
		while (i >= j && i + j + 1 < n && s[(i-j)/2] == s[(i+j+1)/2]) j++;
		l[i] = j;
		for (k = 1; i >= k && j >= k && l[i-k] != j-k; k++)
			l[i+k] = min(l[i-k], j-k);
	}
	return *max_element(l, l + n);
}