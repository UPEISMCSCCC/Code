#include "../test_header.h"
#include "../../snippets/math/multinomial.cpp"
#include "../../snippets/math/permutation_multiset.cpp"

int main() {
	assert(gen_permutation("A", 0) == "A");
	assert(gen_permutation("AA", 0) == "AA");
	assert(gen_permutation("ABC", 0) == "ABC");
	assert(gen_permutation("ABC", 1) == "ACB");
	assert(gen_permutation("ABC", 2) == "BAC");
	assert(gen_permutation("ABC", 3) == "BCA");
	assert(gen_permutation("ABC", 4) == "CAB");
	assert(gen_permutation("ABC", 5) == "CBA");
	assert(gen_permutation("AAB", 0) == "AAB");
	assert(gen_permutation("AAB", 1) == "ABA");
	assert(gen_permutation("AAB", 2) == "BAA");
}

// USED TO SOLVE:
// https://open.kattis.com/problems/lexicography
