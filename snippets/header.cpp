// use better compiler options
#pragma GCC optimize("Ofast","unroll-loops")
#pragma GCC target("avx2,fma")

// include everything
#include <bits/stdc++.h>
#include <bits/extc++.h>
#include <sys/resource.h>

// namespaces
using namespace std;
using namespace __gnu_cxx; // rope
using namespace __gnu_pbds; // tree/trie

// common defines
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define nostacklim rlimit RZ;getrlimit(3,&RZ);RZ.rlim_cur=-1;setrlimit(3,&RZ);
#define DEBUG(v) cout<<"DEBUG: "<<#v<<" = "<<v<<'\n';
#define ll long long
#define ull unsigned ll
#define i128 __int128
#define u128 unsigned i128

// global variables
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
