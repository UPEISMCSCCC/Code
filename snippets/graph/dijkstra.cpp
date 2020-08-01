#define incidency_list vector<vector<edge>>

const int inf = 20000001; // change as needed

// use add_edge(..., true) for digraphs
void add_edge(incidency_list &graph, int u, int v, int w, bool directed=true) {
    graph[u].push_back({u,v,w});
    if(!directed) graph[v].push_back({v,u,w});
}

vector<int> dijkstra(incidency_list graph, int src) {
    vector<int> D(graph.size(), inf);
    priority_queue<edge, vector<edge>, greater<edge>> pq;
    pq.push({src,src,0});
    D[src]=0;
    while(!pq.empty()) {
        edge e = pq.top(); pq.pop();
        int v = e.v;
        for(int i=0;i<graph[v].size();i++) {
            int u = graph[v][i].v;
            if(D[v] + graph[v][i].w < D[u]) {
                D[u] = D[v] + graph[v][i].w;
                pq.push({src,u,D[u]});
            }
        }
    }
    return D;
}
