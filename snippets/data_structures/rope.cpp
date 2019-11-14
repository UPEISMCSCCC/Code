#include <ext/rope>
using namespace __gnu_cxx;

// O(log n) insert, delete, concatenate

int main() {
	rope<int> v;
	for (int i = 0; i < 100; i++)
		v.push_back(i);
	rope<int> copy = v.substr(10, 10);
	v.erase(10, 10);
	v.insert(copy.mutable_begin(), copy);
	for (auto it : v)
		cout << it << " ";
}