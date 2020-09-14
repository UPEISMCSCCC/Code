struct FlowEdge {
    ll v, u, cap, flow = 0; // capacity, flow
    FlowEdge(ll v, ll u, ll cap) : v(v), u(u), cap(cap) 
    FlowEdge() : FlowEdge(0,0,0) {}
};

// taken from https://cp-algorithms.com/graph/dinic.html
// modified for use by us
// solves the maximum flow problem in O(V^2 * E) time
struct MaxFlowGraph {
    const ll flow_inf = INT_MAX;
    vector<FlowEdge> edges;
    vector<vector<int>> adj;
    ll n, m;
    ll s, t;
    vector<ll> level, ptr;
    queue<ll> q;

    MaxFlowGraph(ll n, ll s, ll t)
    : n(n), s(s), t(t), m(0), adj(n), level(n), ptr(n)
    { }

    void add_edge(ll v, ll u, ll cap) {
        edges.push_back({v, u, cap}), edges.push_back({u, v, 0});
        adj[v].push_back(m), adj[u].push_back(m+1);
        m += 2;
    }

    bool bfs() {
        while (!q.empty()) {
            ll v = q.front(); q.pop();
            for (ll id : adj[v]) {
                if(edges[id].cap-edges[id].flow<1 || level[edges[id].u]!=-1) continue;
                level[edges[id].u] = level[v] + 1, q.push(edges[id].u);
            }
        }
        return level[t] != -1;
    }

    ll dfs(ll v, ll pushed) {
        if (pushed == 0)
            return 0;
        if (v == t)
            return pushed;
        for (ll &cid=ptr[v];cid<adj[v].size();cid++) {
            ll id = adj[v][cid], u = edges[id].u;
            if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1)
                continue;
            ll tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0)
                continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }

    // returns {maxflow, flowedges_in_solution}
    pair<ll, vector<FlowEdge>> flow() {
        ll f = 0;
        while (true) {
            fill(level.begin(),level.end(),-1);
            level[s] = 0;
            q.push(s);
            if(!bfs()) break;
            fill(ptr.begin(),ptr.end(),0);
            while (ll pushed=dfs(s,flow_inf)) f += pushed;
        }
        vector<FlowEdge> flow_edges;
        for(auto fe : edges) {
            if(fe.flow > 0) flow_edges.push_back(fe);
        }
        return {f,flow_edges};
    }
};
