#include "../test_header.h"
#include "../../snippets/string/utilities.cpp"

int main() {
	string s;

	s = "AbcDefGhi";
	lowercase(s);
	assert(s == "abcdefghi");
	
	s = "AbcDefGhi";
	uppercase(s);
	assert(s == "ABCDEFGHI");
	
	s = "abc";
	trim(s);
	assert (s == "abc");
	s = "  abc";
	trim(s);
	assert (s == "abc");
	s = "abc   ";
	trim(s);
	assert (s == "abc");
	s = "   abc   ";
	trim(s);
	assert (s == "abc");
}