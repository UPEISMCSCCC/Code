#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp> 
using namespace __gnu_pbds; 
typedef trie<string, null_type, trie_string_access_traits<>, 
        pat_trie_tag, trie_prefix_search_node_update> trie_type;

int main() {
	// generate trie
    trie_type trie;
    for (int i = 0; i < 20; i++)
        trie.insert(to_string(i)); // true if new, false if old
        
	// print things with prefix "1"
    auto range = trie.prefix_range("1");
    for (auto it = range.first; it != range.second; it++)
        cout << *it << " ";
}