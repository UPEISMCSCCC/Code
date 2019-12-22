# Code

This repo contains various bits of code that can be used for competitive programming. Some relatively difficult problems can only be solved using these data structures or algorithms. Readability is a concern, but reducing lines of code is prioritized for use in cheat sheets / team notebooks.

C++ is the default language used here. This choice here is that C++ is usually the fastest language in common use for competitive programming, and that usually C++ can be translated into other languages while the opposite is not necessarily true. Sometimes unique features of C++ is used, but generally it can be converted to other languages without much hassle.

## Information

### Algorithms

* [QuickSelect](./snippets/algorithm/quickselect.cpp) - Search for an element in an unsorted array, similar to a binary search but without the sorted restriction. Effectively performs quicksort, but only on the relevant subsections of the array. This does swap elements within the array and will alter the array's ordering.

### Data Structures

* [Fenwick Tree](./snippets/data_structures/fenwick.cpp) - efficient structure for keeping track of and updating cumulative sums. Updates sums in `O(log n)`
* [Hash Table](./snippets/data_structures/hashtable.cpp) - faster version of std::unordered_map
* [Ordered Set](./snippets/data_structures/ordered_set.cpp) - version of std::set with array-like access methods
* [Rope](./snippets/data_structures/rope.cpp) - version of string, optimized for insertions/deletions at arbitrary points within the string.
* [Trie](./snippets/data_structure/trie.cpp) - prefix tree, or a tree that stores strings based on common prefixes.

### Graph

* [Union Find](./snippets/graph/union_find.cpp) - determine subsets that nodes belong to

### Math

* [Catalan](./snippets/math/catalan.cpp) - generate the catalan numbers under a modulus
* [Combinatorics](./snippets/math/combinatorics.cpp) - functions related to combinatorics
* * [nCr](./snippets/math/combinatorics.cpp) - number of combinations, either whole or under a modulo
* * [nPr](./snippets/math/combinatorics.cpp) - number of permutations, either whole or under a modulo
* [Chinese Remainder Theorem](./snippets/math/crt.cpp) - extended chinese remainder theorem
* [Discrete Logarithm](./snippets/math/discretelog.cpp) - logarithm based on modulus
* [Euler Phi](./snippets/math/euler_totient.cpp) - positive integers up to `n` that are relatively prime to `n`
* [Factorials](./snippets/math/factorial.cpp) - Quick methods for calculating factorials
* * [Kamenetsky's Formula](./snippets/math/factorial.cpp) - approximate number of digits of a factorial
* * [Stirling's Approximation](./snippets/math/factorial.cpp) - approximation of a factorial
* * [Log Factorial](./snippets/math/factorial.cpp) - natural log of a factorial computed very quickly
* [Prime Factorization](./snippets/math/factorization.cpp) - quickly find the prime factorization of a number using Pollard Rho
* [Farey Sequence](./snippets/math/farey.cpp) - generate a list of increasing fractions from 0/1 to 1/1
* [Fast Fourier Transform](./snippets/math/fft.cpp) - calculate the Discrete Fourier transform of a polynomial quickly
* * [Polynomial Multiplication](./snippets/math/fft.cpp) - quickly calculate the multiplication of two polynomials using the fft
* [Extended Greatest Common Denominator](./snippets/math/gcd.cpp) - Extended Euclidean algorithm, given `a` and `b` calculates `x, y, gcd(a, b)` in `ax + by = gcd(a, b)`
* [Lowest Common Multiple](./snippets/math/lcm.cpp) - calculated the lcm of two numbers
* [Modulo Math](./snippets/math/modulo.cpp) - modular addition, multiplication, division, subtraction, powers, factorials, and inverses
* [Miller-Rabin Primality Test](./snippets/math/prime_check.cpp) - quick probabilistic test whether a number is prime or not
* [Sieve of Eratosthenes](./snippets/math/prime_sieve.cpp) - generate a prime sieve to allow for very fast lookups whether a number is prime or not
* [Simpson's Rule](./snippets/math/simpsons.cpp) - approximation of an integral of a function
* [Equation Solver](./snippets/math/solve_equations.cpp) - solve quadratic and cubic functions

### String

* [Number Converter](./snippets/string/int_to_english.cpp) - convert an integer into its english equivalent
* [Longest Common Prefix](./snippets/string/lcp.cpp) - sort-based method of determining the longest prefix shared among all elements in an array
* [Longest Common Subsequence](./snippets/string/lcs.cpp) - dynamic programming solution for finding the longest subsequence shared between two strings
* [Longest Palindrome Substring](./snippets/string/manacher.cpp) - Manacher's algorithm for finding the palindrome length of every substring of a given string
* [Subsequence Count](./snippets/string/subsequence.cpp) - dynamic programming solution for counting the number of times a string appears as a subsequence in a larger string
