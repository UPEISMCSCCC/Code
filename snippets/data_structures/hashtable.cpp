// similar to unordered_map, but faster
struct chash {
	const uint64_t C = (ll)(2e18 * M_PI) + 71;
	ll operator()(ll x) const { return __builtin_bswap64(x*C); }
};
int main() {
	gp_hash_table<ll,int,chash> hashtable({},{},{},{},{1<<16});
	for (int i = 0; i < 100; i++)
		hashtable[i] = 200+i;
	if (hashtable.find(10) != hashtable.end())
		cout << hashtable[10];
}