# Code

This repo contains various bits of code that can be used for competitive programming. Some relatively difficult problems can only be solved using these data structures or algorithms.

C++ is the default language used here. Sometimes unique features of C++ is used, but generally it can be converted to other languages without much hassle.

## Information

### Algorithms

* [QuickSelect](./snippets/algorithm/quickselect.cpp) - Search for an element in an unsorted array, similar to a binary search but without the sorted restriction. Effectively performs quicksort, but only on the relevant subsections of the array.

### Data Structures

* [Fenwick Tree](./snippets/data_structures/fenwick.cpp) - efficient structure for keeping track of and updating cumulative sums.
* [Hash Table](./snippets/data_structures/hashtable.cpp) - faster version of std::unordered_map
* [Ordered Set](./snippets/data_structures/ordered_set.cpp) - version of std::set with array-like access methods
* [Rope](./snippets/data_structures/rope.cpp) - version of string, optimized for arbitrary insertions/deletions
* [Trie](./snippets/data_structure/trie.cpp) - prefix tree
