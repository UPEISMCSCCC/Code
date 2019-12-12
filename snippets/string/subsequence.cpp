// O(m*n) - "banana", "ban" >> 3 (ban, ba..n, b..an)
int subsequences(string body, string subsequence) {
	int m = subsequence.length(), n = body.length();
	if (m > n) return 0;
	
	ull** arr = new ull*[m+1];
	for (int i = 0; i <= m; i++)
		arr[i] = new ull[n+1];
	
	for (int i = 1; i <= m; i++)
		arr[i][0] = 0;
	for (int i = 0; i <= n; i++)
		arr[0][i] = 1;
	
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (body[j-1] != subsequence[i-1])
				arr[i][j] = arr[i][j-1];
			else
				arr[i][j] = arr[i][j-1] + arr[i-1][j-1];
		}
	}
	
	ull value = arr[m][n];
	for (int i = 0; i < m; i++) delete[] arr[i];
	delete[] arr;
	return value;
}