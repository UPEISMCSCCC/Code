// longest common prefix of strings in array
string lcp(string* arr, int n, bool sorted = false) {
	if (n == 0) return "";
	if (!sorted) sort(arr, arr + n);
	string r = ""; int v = 0;
	while (v < arr[0].length() && arr[0][v] == arr[n-1][v])
		r += arr[0][v++];
	return r;
}