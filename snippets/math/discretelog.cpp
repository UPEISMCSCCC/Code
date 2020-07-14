int discretelog(int a, int b, int m) {
    ll n = sqrt(m) + 1, an = 1;
    for (ll i = 0; i < n; ++i)
        an = (an * a) % m;

    unordered_map<ll, ll> vals;
    for (ll q = 0, cur = b; q <= n; q++) {
        vals[cur] = q;
        cur = (cur * a) % m;
    }

    for (ll p = 1, cur = 1; p <= n; p++) {
        cur = (cur * an) % m;
        if (vals.count(cur)) {
            int ans = n * p - vals[cur];
            return ans;
        }
    }
    return -1;
}
