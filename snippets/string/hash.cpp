#define HASHER 27
ull basicHash(string s) {
	ull v = 0;
	for (auto c : s) v = (c - 'a' + 1) + v * HASHER;
	return v;
}

const int MAXN = 1000001;
ull base[MAXN] = {1};
void genBase(int n) {
	for (int i = 1; i <= n; i++)
		base[i] = base[i-1] * HASHER;
}
struct advHash {
	ull v, l; vector<ull> wip;
	advHash(string& s): v(0) {
		wip = vector<ull>(s.length()+1);\
		wip[0] = 0;
		for (int i = 0; i < s.length(); i++)
			wip[i+1] = (s[i] - 'a' + 1) + wip[i] * HASHER;
		l = s.length(); v = wip[l];
	}
	ull del(int pos, int len) {
		return v - wip[pos+len]*base[l-pos-len] + wip[pos]*base[l-pos-len];
	}
	ull substr(int pos, int len) {
		return del(pos+len, (l-pos-len)) - wip[pos]*base[len];
	}
	ull replace(int pos, char c) {
		return v - wip[pos+1]*base[l-pos-1] + ((c - 'a' + 1) + wip[pos] * HASHER)*base[l-pos-1];
	}
	ull replace(int pos, string s) {
		// can't increase total string size
		ull r = v - wip[pos+s.size()]*base[l-pos-s.size()], c = wip[pos];
		for (int i = 0; i < s.size(); i++)
			c = (s[i]-'a'+1) + c * HASHER;
		return r + c * base[l-pos-s.size()];
	}
};