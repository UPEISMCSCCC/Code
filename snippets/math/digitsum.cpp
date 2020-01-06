#include "digitcount.cpp"

/*returns the sum of all digits of all numbers in the range [0,n]*/
/*depends on count(n,d) from digitcount.cpp*/
ll digitsum(ll n) {
    if(n<=0) return 0;
    ll res = 0;
    for(ll i=1;i<=9;i++) {
        ll c = count(n,i);
        //cout << c << " occurrences of digit " <<  i << " in range 0..." << n << '\n';
        res += i*c;
    }
    return res;
}
