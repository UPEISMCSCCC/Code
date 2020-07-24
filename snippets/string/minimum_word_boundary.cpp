// minimum word boundary
// compose string s using words from dict
// NOTE: can reuse words from dict
unsigned int mwb(string s, set<string> dict) {
	int l = s.size();
	vector<unsigned int> arr(l+1, -1);
	arr[0] = 0;
	for (int i = 0; i < l; i++) {
		if (arr[i] != -1) {
			for (auto e : dict) {
				int L = e.size();
				if (l >= i + L) {
					bool isGood = true;
					for (int j = 0; isGood && j < L; j++)
						if (s[i+j] != e[j])
							isGood = false;
					if (isGood)
						arr[i+L] = min(arr[i]+1, arr[i+L]);
				}
			}
		}
	}
	return arr[l];
}