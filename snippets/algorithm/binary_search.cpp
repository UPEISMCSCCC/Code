// search for k in [p,n)
template<typename T>
int binsearch(T x[], int k, int n, int p = 0) {
    for (int i = n; i >= 1; i /= 2)
        while (p+i < n && x[p+i] <= k) p += i;
    return p; // bool: x[p] == k;
}
