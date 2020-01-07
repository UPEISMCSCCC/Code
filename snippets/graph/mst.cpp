struct edge{
	int u,v,w;
	edge (int _, int __, int ___) { u = _, v = __, w = ___;}
};

// returns ptr to vector of edges in the mst, reasonably fast
// graph[i] = vector of edges incident to vertex i
// places total weight of the mst in &total
vector<edge> *mst(vector<edge> *graph, size_t n, size_t m, long long &total) {
    total = 0;
    const auto compEdge = [](edge e, edge f) { return e.w > f.w; };
    priority_queue<edge,vector<edge>,decltype(compEdge)> pq(compEdge);
    vector<edge> *MST = new vector<edge>;
    bool marked[n];
    memset(marked,false,n);
	  marked[0] = true; // mark vertex 0 as visited
    for (int i=0;i<graph[0].size();i++) pq.push(graph[0][i]); // push all edges incident to vertex 0
    edge e(0,0,0);
    int u,v,w,chosen;
    while(MST->size()!=n-1 && pq.size()!=0) {
        e = pq.top();
        pq.pop();
        u = e.u, v = e.v, w = e.w;
        if(marked[u] && marked[v]) continue;
        else if(marked[u]) chosen=v;
        else chosen=u;
        for(int i=0;i<graph[chosen].size();i++) pq.push(graph[chosen][i]);
        marked[chosen] = true;
        MST->push_back(e);
        total += e.w;
    }
    if(MST->size()==n-1) {
        return MST;
    }
    else {
        delete MST;
        return nullptr;
    }
}
