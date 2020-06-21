#include "../test_header.h"
#include "../../snippets/string/utilities.cpp"

int main() {
	string s;
	vector<string> v;

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
	
	s = "a,b,c";
	v = split(s, ',');
	assert(v.size() == 3 && v[0] == "a" && v[1] == "b" && v[2] == "c");
	s = "abc";
	v = split(s, ',');
	assert(v.size() == 1 && v[0] == "abc");
}