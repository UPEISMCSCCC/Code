string lcs(string a, string b) {
	int m = a.length(), n = b.length();
	
	int L[m+1][n+1];
	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			if (i == 0 || j == 0) L[i][j] = 0;
			else if (a[i-1] == b[j-1]) L[i][j] = L[i-1][j-1]+1;
			else L[i][j] = max(L[i-1][j], L[i][j-1]);
		}
	}
	// return L[m][n]; // length of lcs
	
	string out = "";
	int i = m - 1, j = n - 1;
	while (i >= 0 && j >= 0) {
		if (a[i] == b[j]) {
			out = a[i--] + out;
			j--;
		}
		else if (L[i][j+1] > L[i+1][j]) i--;
		else j--;
	}
	
	return out;
}