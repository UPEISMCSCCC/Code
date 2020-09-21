// check if number is in cantor set
// defined by infinitely removing the open middle third of open intervals
// starts as [0,1], then [0,1/3], [2/3,1], etc.
// equivalently, those real numbers in [0,1] that have a base-3 expansion
// not containing any 1's.
// solves https://open.kattis.com/problems/cantor in 0.00s

// 10^6 precision (assumes <= 6 decimals, can be changed)
#define PREC 1000000
bool in_cantor_rational(ll x, ll y) {
    ll g = __gcd(x,y);
    x /= g, y /= g;
    if(x==0 || (x==1 && y==1)) return true;
    for(ll i=0;i<y;i++) {
        x=3*min(x,y-x);
        if(x<0) return false;
    }
    return true;
}

// time complexity is O(log(PREC) + q)
// where x = p/q is lowest rational form
bool in_cantor(double x) {
    ll s = (int)(x * PREC);
    return in_cantor_rational(s, PREC);
}
