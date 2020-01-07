// returns vector of edges in the mst
// graph[i] = vector of edges incident to vertex i
// places total weight of the mst in &total
// if returned vector has size != n-1, there is no MST
vector<edge> mst(vector<vector<edge>> graph, ll &total) {
    total = 0;
    priority_queue<edge, vector<edge>, greater<edge>> pq;
    vector<edge> MST;
    bitset<20001> marked; // change size as needed
    marked[0] = 1;
    for (edge ep : graph[0]) pq.push(ep);
    while(MST.size()!=graph.size()-1 && pq.size()!=0) {
        edge e = pq.top(); pq.pop();
        int u = e.u, v = e.v, w = e.w;
        if(marked[u] && marked[v]) continue;
        else if(marked[u]) swap(u, v);
        for(edge ep : graph[u]) pq.push(ep);
        marked[u] = 1;
        MST.push_back(e);
        total += e.w;
    }
    return MST;
}
