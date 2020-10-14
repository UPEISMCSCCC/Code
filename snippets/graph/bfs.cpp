// adjacency list named 'graph'
// - if you only need to bfs once
// visited can be gutted for parent
//- path reconstruction in reverse
// flip start/end only in undirected graphs
// - can store a distance array too
int visited[MAX];
int parent[MAX];
int vc = 0;
vector<int> bfs(int start, int end) {
	visited[start] = ++vc;
	parent[start] = -1;
	queue<int> q;
	q.push(start);
	int f = 1, m = graph.size();
	while (!q.empty()) {
		int v = q.front(); q.pop();
		for (auto e : graph[v]) {
			if (visited[e] != vc) {
				visited[e] = vc;
				q.push(e);
				parent[e] = v;
				if (++f == m || e == end) goto DONE;
			}
		}
	}
	DONE:
	// path reconstruction
	if (visited[end] != vc) return {};
	vector<int> path;
	for (int v = end; v != -1; v = parent[v])
		path.push_back(v);
	return path;
}