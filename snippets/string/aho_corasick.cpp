// range of alphabet for automata to consider
// MAXC = 26, OFFC = 'a' if only lowercase
const int MAXC = 256;
const int OFFC = 0;

struct aho_corasick {
	struct state {
		set<pair<int, int>> out;
		int fail; vector<int> go;
		state() : fail(-1), go(MAXC, -1) {}
	};
	
	vector<state> s;
	int id = 0;
	
	aho_corasick(string* arr, int size) : s(1) {
		for (int i = 0; i < size; i++) {
			int cur = 0;
			for (int c : arr[i]) {
				if (s[cur].go[c-OFFC] == -1) {
					s[cur].go[c-OFFC] = s.size();
					s.push_back(state());
				}
				cur = s[cur].go[c-OFFC];
			}
			s[cur].out.insert({arr[i].size(), id++});
		}
		
		for (int c = 0; c < MAXC; c++)
			if (s[0].go[c] == -1)
				s[0].go[c] = 0;
		queue<int> sq;
		for (int c = 0; c < MAXC; c++) {
			if (s[0].go[c] != 0) {
				s[s[0].go[c]].fail = 0;
				sq.push(s[0].go[c]);
			}
		}
		while (sq.size()) {
			int e = sq.front(); sq.pop();
			for (int c = 0; c < MAXC; c++) {
				if (s[e].go[c] != -1) {
					int failure = s[e].fail;
					while (s[failure].go[c] == -1)
						 failure = s[failure].fail;
					failure = s[failure].go[c];
					s[s[e].go[c]].fail = failure;
					for (auto length : s[failure].out)
						s[s[e].go[c]].out.insert(length);
					sq.push(s[e].go[c]);
				}
			}
		}
	}
	
	// list of {start pos, pattern id}
	vector<pair<int, int>> search(string text) {
		vector<pair<int, int>> toret;
		int cur = 0;
	  
		for (int i = 0; i < text.size(); i++) {
			while (s[cur].go[text[i]-OFFC] == -1)
				cur = s[cur].fail;
			cur = s[cur].go[text[i]-OFFC];
			
			if (s[cur].out.size())
				for (auto end : s[cur].out)
					toret.push_back({i - end.first + 1, end.second});
		}
		return toret;
	}
};
