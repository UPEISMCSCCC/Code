// check if there exists a binary matrix with
// row sums a[i] and column sums b[i]
// cannot be used to actually get the matrix, that's
// a graph theory problem for another branch
bool exists_binary_matrix(vector<ll> &a, vector<ll> &b) {
  while (!a.empty()) {
    sort(b.begin(), b.end(), greater<ll>());
    ll k = a.back();
    a.pop_back();
    if(k > b.size()) return false;
    if(k == 0) continue;
    if(b[k - 1] == 0) return false;
    for (ll i = 0; i < k; i++) b[i]--;
  }
  return count(b.begin(), b.end(), 0) == b.size();
}
