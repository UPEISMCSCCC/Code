#include "../test_header.h"
#include "../../snippets/math/digitcount.cpp"

int main() {
	assert(digit_count(0, 1) == 0);
	assert(digit_count(100, 0) == 2);
	assert(digit_count(100, 1) == 1);
	assert(digit_count(123, 1) == 1);
	assert(digit_count(999, 1) == 0);
}