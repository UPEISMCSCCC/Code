#define edge_list vector<edge>
#define adj_sets vector<set<int>>

struct EulerPathGraph {
	adj_sets graph; // actually indexes incident edges
	edge_list edges; int n; vector<int> indeg;
	EulerPathGraph(int n): n(n) {
		indeg = *(new vector<int>(n,0));
		graph = *(new adj_sets(n, set<int>()));
	}
	
	void add_edge(int u, int v) {
		graph[u].insert(edges.size());
		indeg[v]++;
		edges.push_back(edge(u,v,0));
	}
	
	bool eulerian_path(vector<int> &circuit) {
		if(edges.size()==0) return false;
		stack<int> st;
		int a[] = {-1, -1};
		for(int v=0;v<n;v++) {
			if(indeg[v]!=graph[v].size()) {
				bool b = indeg[v] > graph[v].size();
				if (abs(((int)indeg[v])-((int)graph[v].size())) > 1) return false;
				if (a[b] != -1) return false;
				a[b] = v;
			}
		}
		int s = (a[0]!=-1 && a[1]!=-1 ? a[0] : (a[0]==-1 && a[1]==-1 ? edges[0].u : -1));
		if(s==-1) return false;
		while(!st.empty() || !graph[s].empty()) {
			if (graph[s].empty()) { circuit.push_back(s); s = st.top(); st.pop(); }
			else {
				int w = edges[*graph[s].begin()].v;
				graph[s].erase(graph[s].begin());
				st.push(s); s = w;
			}
		}
		circuit.push_back(s);
		return circuit.size()-1==edges.size();
	}
};
