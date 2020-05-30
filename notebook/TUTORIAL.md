# How to use this notebook

This section contains various descriptions and helpful resources for ensuring that the notebook here is fully understood and usable. The notebook is dense and intimidating, but has lots of useful and important snippets in it.

## `run.sh` & `test.sh`

These are two scripts that can be used (in linux environments, or windows environments capable of emulating them) to run C++ code faster. `run.sh` simply compiles a program named `prog.cpp` and runs it. `test.sh` takes this a step further and automatically runs it on various test cases (input in `.in` files, correct answer in `.ans` files) and compares the output to the correct answers.

## Header

```cpp
// use better compiler options
#pragma GCC optimize("Ofast","unroll-loops")
#pragma GCC target("avx2,fma")
```
This includes various options that use better optimization options. Sometimes these will actually end up slower (though uncommon) but in general these will result in faster programs.

```cpp
// include everything
#include <bits/stdc++.h>
#include <bits/extc++.h>
#include <sys/resource.h>
```
This includes all of the standard library, as well as GCC's extended library and the linux-specific resource header (used for setting the stack limit).

```cpp
// namespaces
using namespace std;
using namespace __gnu_cxx; // rope
using namespace __gnu_pbds; // tree/trie
```
These simplify code by making using the namespace for any standard library or GNU extension unnecessary. This is not universal (if it is nested further, like in `std::chrono::steady_clock` you would still need `chrono::steady_clock`) and there are conflicts (need to use `std::to_string` because `__gnu_cxx::to_string` also exists) but overall these simplify code.

```cpp
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
```
This is a set of simple functions that greatly increase the speed of input/output streams (`cin` and `cout`). They don't affect other IO functions (`printf`, `getchar`, etc). Other methods are still faster, but this can quickly improve runtime performance of a program that currently uses `cin` and `cout`. Note that this can interfere with interactive problems.

```cpp
#define nostacklim rlimit RZ;getrlimit(3,&RZ);RZ.rlim_cur=-1;setrlimit(3,&RZ);
```
This define acts as a function that sets the stack limit to be significantly larger. In cases where recursive depth is an issue, this may be applied as a quick-fix in some contests that make no rules about it. It's worth mentioning that recursion can be avoided and an iterative solution is generally faster, and is preferred for that reason.

```cpp
#define DEBUG(v) cerr<<__LINE__<<": "<<#v<<" = "<<v<<'\n';
```
This prints out (to error, so that it is not considered in most judges) debug information about a variable. Specifically, it prints out `<current line>: <variable name> = <variable value>`.


```cpp
#define ll long long
#define ull unsigned ll
#define i128 __int128
#define u128 unsigned i128
#define ld long double
```
These provide shortened names for some common types (specifically, types that are long to type out).

```cpp
// global variables
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
```
This sets a global variable for rng used for some randomized algorithms. This is more advanced than `rand()` specifically so that it's harder to construct cases where it fails (in codeforces, particularly).

## Fast IO

These provide functions that are supposed to be very fast for input/output. These are much faster than the alternatives (`cin/cout`, `scanf/printf`, etc) but come at the cost of being relatively long to code (and hard to use in competition for that reason).

## Common Structs

The `Vec` struct is an n-dimensional vector with default initialization.

An example usage would be:
```cpp
	Vec<2, int> arr(5, 10, -1);
```
This creates a 2D array of the bounds `arr[5][10]` that is default initialized to `-1`. The last argument is optional, and will use default initialization if it's not included (`0` for `int`).

## Judge Speed

This is intended to be run during contest prep. If the contest judge reports back how long your program took (before it gets wrong answer), this should take a fairly standard amount of time that you can compare with popular platforms.

## Judge Error Codes

This function is made for contest prep to see what sort of error messages you will get when your program is wrong. To test each potential error code, simply run the function by passing in whatever error code you want to check.

## GCC Builtin Docs

These consist of documentation for GCC specific extensions and implementations that would not be available in the language documentation provided in most contests.

```cpp
__int128 a;
unsigned __int128 b;
```

These are types that provide greater precision than 64-bit types, which are normally the largest available in C++. Unfortunately IO doesn't support these types, so they have to either be cast or have each digit read/printed manually.

```cpp
__float128 c;
```

Like the above types, this type provides greater precision than other floating point types (`double` being 64-bit and `long double` being 80-bit). It should likely be cast to `long double` when printing, and its extra precision used for intermediary calculations.