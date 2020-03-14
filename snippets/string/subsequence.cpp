// "banana", "ban" >> 3 (ban, ba..n, b..an)
ull subsequences(string body, string subs) {
	int m = subs.length(), n = body.length();
	if (m > n) return 0;
	ull** arr = new ull*[m+1];
	for (int i = 0; i <= m; i++) arr[i] = new ull[n+1];
	for (int i = 1; i <= m; i++) arr[i][0] = 0;
	for (int i = 0; i <= n; i++) arr[0][i] = 1;
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			arr[i][j] = arr[i][j-1] + ((body[j-1] == subs[i-1])? arr[i-1][j-1] : 0);
	return arr[m][n];
}
