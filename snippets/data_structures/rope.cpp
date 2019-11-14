#include <ext/rope>
using namespace __gnu_cxx;

// O(log n) insert, delete, concatenate

int main() {
	// generate rope
	rope<int> v;
	for (int i = 0; i < 100; i++)
		v.push_back(i);
	
	// move range to front
	rope<int> copy = v.substr(10, 10);
	v.erase(10, 10);
	v.insert(copy.mutable_begin(), copy);
	
	// print elements of rope
	for (auto it : v)
		cout << it << " ";
}