string lcp(string* arr, int n) {
	if (n == 0) return "";
	if (n == 1) return arr[0];
	sort(arr, arr + n);
	string r = ""; int v = 0;
	while (v < arr[0].length() && arr[0][v] == arr[n-1][v])
		r += arr[0][v++];
	return r;
}