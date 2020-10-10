#define ll long long
#define OFFSET 50000

// vector to polynomial
vector<ll> make_poly(vector<ll> &v) {
    ll mx = *max_element(v.begin(), v.end());
    vector<ll> A(mx+1, 0);
    for(ll a : v) A[a]++;
    return A;
}

// number of pairs (a,b) so a+b = c for some c
// assumes non negative elements
// relies on FFT multiplication of polynomials
ll count_ways(vector<ll> &a, vector<ll> &b, vector<ll> &c) {
    const vector<ll> pA = make_poly(a), pB = make_poly(b);
    vector<ll> sumPoly = fftmult(pA, pB);
    ll ans = 0;
    for(ll cx : c) {
        if(cx < sumPoly.size()) {
            ans += sumPoly[cx];
        }
    }
    return ans;
}

// number of ways two things from A can add to get something in A
// i.e. pairs (i,j,k) so A[i]+A[j] = A[k] where i,j,k distinct.
// assumes all elements are in [-OFFSET, OFFSET]
// solves https://open.kattis.com/problems/aplusb
ll count_ways_1v(vector<ll> &Ap) {
    unordered_map<ll,ll> Amap;
    for(ll x : Ap) Amap[x]++;
    vector<ll> A(Ap);
    ll N = A.size();
    vector<ll> C(A); // holds the stuff in A we are trying to sum to get
    
    // scale A to [0, 2*OFFSET], add twice for targets
    for(ll i=0;i<N;i++) A[i] += OFFSET, C[i] += 2*OFFSET;
    
    // get raw number of pairs
    ll ans = count_ways(A, A, C);
    // subtract cases where i=j and i or j=k
    for(ll a : Ap) {
        ans -= Amap[2*a]; // i=j
        ans -=  2*(Amap[0] - (a==0));
    }
    return ans;
}
