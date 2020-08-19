// adjacency list named 'graph'
int visited[MAX];
int parent[MAX];
int vc = 0;
vector<int> bfs(int start, int end) {
	vc++;
	visited[start] = vc;
	parent[start] = -1;
	queue<int> q;
	q.push(start);
	while (!q.empty()) {
		int v = q.front(); q.pop();
		for (auto e : graph[v]) {
			if (visited[e] != vc) {
				visited[e] = vc;
				q.push(e);
				parent[e] = v;
				if (e == end) goto DONE;
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