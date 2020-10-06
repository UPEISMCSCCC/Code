/*
given an array `arr` and a list of possible swaps (i,j)
can arr be sorted using (any number of) the swaps given?
relies on UF.
solves https://open.kattis.com/problems/longswaps
*/
bool can_sort(vector<int> &arr, vector<pair<int,int>> &possible_swaps) {
    int n = arr.size();
    vector<int> arr_sorted(arr), sorted_guess(n, -1);
    sort(arr_sorted.begin(), arr_sorted.end());
    subset *s = new subset[n];
    for(int i=0;i<n;i++) s[i] = subset(i);
    for(pair<int,int> p : possible_swaps) uf_union(s, p.first, p.second);
    unordered_map<int, vector<int>> disjoint_subsets;
    for(int i=0;i<n;i++) disjoint_subsets[uf_find(s, i)].push_back(i);
    const auto key_comp = [arr](int i, int j) { return arr[i] < arr[j]; };
    for(auto it=disjoint_subsets.begin();it!=disjoint_subsets.end();it++) {
        vector<int> cp(it->second);
        sort(it->second.begin(), it->second.end(), key_comp);
        for(int i=0;i<cp.size();i++) sorted_guess[cp[i]] = arr[it->second[i]];
    }
    return sorted_guess == arr_sorted;
}
