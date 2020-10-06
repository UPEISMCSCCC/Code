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

// memory-efficient variant if you don't need reconstruction
int lcs_compressed(vector<int>& a, vector<int>& b) {
    int m = a.size(), n = b.size(), bi, L[2][n + 1];
    for (int i = 0; i <= m; i++)  {
        bi = i & 1;
        for (int j = 0; j <= n; j++)  { 
            if (i == 0 || j == 0)  L[bi][j] = 0; 
            else if (a[i-1] == b[j-1]) L[bi][j] = L[1 - bi][j - 1] + 1; 
            else L[bi][j] = max(L[1 - bi][j], L[bi][j - 1]); 
        } 
    }
    return L[bi][n]; 
}

#define T int
// for two vectors X and Y, each of *unique* elements, finds the length of LCS of the
// sequences obtained by removing any uncommon elements of the two vectors
// is a special case where we can reduce to NlogN using lis algorithm
// solves https://open.kattis.com/problems/princeandprincess
int lcs_of_permutations(vector<T> &X, vector<T> &Y) {
    unordered_set<T> sx, sy;
    for(T t : X) sx.insert(t);
    vector<T> new_x, new_y;
    for(T t : Y) if(sx.count(t))
        sy.insert(t), new_y.push_back(t);
    for(T t : X) if(sy.count(t))
        new_x.push_back(t);
    unordered_map<T, int> mm;
    int n = new_x.size();
    vector<T> ans(n);
    for(int i=0;i<n;i++) mm[new_x[i]] = i;
    for(int i=0;i<n;i++) ans[i] = mm[new_y[i]];
    return lis(ans);
}
