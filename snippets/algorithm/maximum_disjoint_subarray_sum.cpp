// a state is (index, positive part, negative part)
// so the sum is positive part - negative part
void find_all_sums(vector<int> &vals, vector<pair<int,int>> &sums, int i, int pos, int neg, int hi) {
    sums.push_back({pos-neg, pos});
    if(i == hi) return;
    find_all_sums(vals, sums, i+1, pos, neg, hi);
    find_all_sums(vals, sums, i+1, pos+vals[i], neg, hi);
    find_all_sums(vals, sums, i+1, pos, neg+vals[i], hi);
}

int maximum_disjoint_subset_sum(vector<int> &A) {
    int n = A.size();
    vector<pair<int,int>> s1_sums, s2_sums;
    find_all_sums(A,s1_sums,0,0,0,n/2);
    find_all_sums(A,s2_sums,n/2,0,0,n);
    sort(s2_sums.begin(), s2_sums.end());
    int ans = 0;
    for(int j=0;j<s1_sums.size();j++) {
        int sum = s1_sums[j].first, pos = s1_sums[j].second;
        pair<int,int> q = {sum+1, 0};
        auto it = lower_bound(s2_sums.begin(), s2_sums.end(), q);
        if(it==s2_sums.begin()) continue;
        else {
            it--;
            int idx = it - s2_sums.begin();
            if(s2_sums[idx].first == sum) {
                ans = max(ans, pos - sum + s2_sums[idx].second);
            }
        }
    }
    return ans;
}
