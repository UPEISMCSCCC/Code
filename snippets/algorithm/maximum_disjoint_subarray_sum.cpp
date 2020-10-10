vector<int> s1, s2;
// pairs of (total_sum, positive_part)
vector<pair<int,int>> s1_sums;
vector<pair<int,int>> s2_sums;


// a state is (index, positive part, negative part)
// so the sum is positive part - negative part
void find_all_s1_sums(int i, int pos, int neg) {
    s1_sums.push_back({pos-neg, pos});
    if(i == s1.size()) return;
    find_all_s1_sums(i+1, pos, neg);
    find_all_s1_sums(i+1, pos+s1[i], neg);
    find_all_s1_sums(i+1, pos, neg+s1[i]);
}

void find_all_s2_sums(int i, int pos, int neg) {
    s2_sums.push_back({pos-neg, pos});
    if(i == s2.size()) return;
    find_all_s2_sums(i+1, pos, neg);
    find_all_s2_sums(i+1, pos+s2[i], neg);
    find_all_s2_sums(i+1, pos, neg+s2[i]);
}

int maximum_disjoint_subset_sum(vector<int> &A) {
    s1.clear();
    s2.clear();
    s1_sums.clear();
    s2_sums.clear();
    int n = A.size();
    for(int i=0;i<n;i++) {
        if(i<n/2) s1.push_back(A[i]);
        else s2.push_back(A[i]);
    }
    find_all_s1_sums(0,0,0);
    find_all_s2_sums(0,0,0);
    // sort the s2 sums and positive components
    sort(s2_sums.begin(), s2_sums.end());
    int ans = 0;
    for(int j=0;j<s1_sums.size();j++) {
        int sum = s1_sums[j].first, pos = s1_sums[j].second;
        // over all {s,z} in s2_sums with s==sum
        // find the largest z to maximize the total subset sum
        pair<int,int> q = {sum+1, 0};
        auto it = lower_bound(s2_sums.begin(), s2_sums.end(), q);
        if(it==s2_sums.begin()) continue; // no such pair
        else {
            it--;
            int idx = it - s2_sums.begin();
            if(s2_sums[idx].first == sum) { // there is a z and this one is biggest
                ans = max(ans, pos - sum + s2_sums[idx].second);
            }
        }
    }
    return ans;
}
