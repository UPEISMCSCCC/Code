struct edge {
    int u,v,w;
    edge (int u, int v, int w) : u(u), v(v), w(w) {}
    edge () : u(0), v(0), w(0) {}
};
bool operator < (const edge &e1, const edge &e2) { return e1.w < e2.w; }
bool operator > (const edge &e1, const edge &e2) { return e1.w > e2.w; }

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
    edge e;
    int u,v,w,chosen;
    while(MST.size()!=graph.size()-1 && pq.size()!=0) {
        e = pq.top(); pq.pop();
        u = e.u, v = e.v, w = e.w;
        if(marked[u] && marked[v]) continue;
        else if(marked[u]) chosen=v;
        else chosen=u;
        for(edge ep : graph[chosen]) pq.push(ep);
        marked[chosen] = 1;
        MST.push_back(e);
        total += e.w;
    }
    return MST;
}
