/* SPECIAL CASES REQUIRING GRAPH MODIFICATION
   NOTE many of theses applications decrease the time complexity
   (e.g. Bipartite reduces to sqrt(V)*E)
   TODO maybe make these there own snippets

- multi-source, multi-sink
  let s1, ... sn and t1, ..., tm be the sources and sinks
  make a new node s, and add s->si edges with inf capacity
  make a new node t, and add ti->t edges with inf capacity
  then run as usual

- maximum cardinality bipartite matching
  given BPG with X,Y bipartition and E edge set
  make a network graph with V = XuYu{s,t}
  E' = {all edges in original}u{(s,x):x in X}u{(y,t):y in Y}
  set capacity(e)=1 for each e in E', then run flow.
  edges in matching are those with flow 1 which exist in original graph

- minimum path cover (min # of vertex-disjoint paths to cover a DAG)
  given G(V,E) (a DAG), let Vin = {v in V: v has positive indegree}
  and Vout = {v in V: v has positive outdegree}. Let E' be edges
  (u,v) in E so u in Vout and v in Vin. Let G' = (Vin u Vout, E')
  running bipartite on G' gives the min #.

- max flow with vertex capacities
  instead of just limiting flow on each edge, suppose we have c(v)>=0
  for each vertex (not the source or sink),
  so the flow through v must be <= c(v).
  transform each v into two nodes: vin and vout
  make all edges (u,v) instead (u,vin)
  and all edges (v,u) instead (vout, u)
  and finally make an edge (vin,vout) with capacity c(v)
*/

// each edge has a capacity and a flow
// flow must be <= capacity
struct FlowEdge {
    ll v, u, cap, flow = 0; // capacity, flow
    FlowEdge(ll v, ll u, ll cap) : v(v), u(u), cap(cap) 
    FlowEdge() : FlowEdge(0,0,0) {}
};

// taken from https://cp-algorithms.com/graph/dinic.html
// modified for use by us
// solves the maximum flow problem in O(V^2 * E) time (faster than it sounds usually)
// solves min cut with similar time complexity (overhead proportional to V+E)
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
        if (pushed == 0 || v == t)
            return pushed;
        for (ll &cid=ptr[v];cid<adj[v].size();cid++) {
            ll id = adj[v][cid], u = edges[id].u;
            if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1)
                continue;
            ll tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0) continue;
            edges[id].flow += tr, edges[id ^ 1].flow -= tr;
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
    
    // helper for min_cut, find vertices reachable
    // from s in the final residual graph
    void _dfs_reachable(ll x, vector<bool> &visited) {
        visited[x] = true;
        for(ll cid : adj[x]) {
            ll u = edges[cid].u;
            if(!visited[u] && edges[cid].flow < edges[cid].cap) {
                _dfs_reachable(u, visited);
            }
        }
    }
    
    // returns {min_cut_weight, vertices_in_S}
    // min cut is a partition (S,T) of vertex set
    // so weight of edges from S to T is minimized
    pair<ll,vector<ll>> min_cut() {
        auto f = flow();
        ll max_flow_val = f.first;
        vector<bool> visited(n, false);
        _dfs_reachable(s, visited);
        vector<ll> ans;
        for(int i=0;i<n;i++)
            if(visited[i]) ans.push_back(i);
        return {max_flow_val, ans};
    }
};

#define umap unordered_map

// untested code
// make new graph with vertex capacities
// using algorithm described above
pair<umap<ll,pair<ll,ll>>, MaxFlowGraph> with_vertex_capacities(MaxFlowGraph &original_graph, umap<ll,ll> &vcaps) {
    // whatever s, t were in old graph, they are last 2 nodes in the new graph
    // every other node is split in two, v and v+V where V is old size
    umap<ll,pair<ll,ll>> old_new_vertex_map;

    ll N = 2*vcaps.size() + 2, s = original_graph.s, t = original_graph.t;
    ll old_N = original_graph.n;
    ll x=0;
    for(ll v=0;v<old_N;v++) {
        if(v!=s && v!=t) { // node needs to be split
            old_new_vertex_map[v] = {x,x+old_N}; // split the node into xin xout
        }
    }
    old_new_vertex_map[s] = {-1, N-2};
    old_new_vertex_map[t] = {N-1, -1};
    
    // make new graph with s,t as last two nodes
    MaxFlowGraph new_graph(N, N-2, N-1);
    for(const auto &fe : original_graph.edges) {
        ll v = fe.v, u = fe.u, cap = fe.cap;
        // is a (v,u) edge
        // make it a (vout, uin) edge
        ll vout = old_new_vertex_map[v].second;
        ll uin = old_new_vertex_map[u].first;
        new_graph.add_edge(vout, uin, cap);
    }
    for(ll v=0;v<old_N;v++) {
        if(v!=s && v!=t) {
            auto vp = old_new_vertex_map[v];
            new_graph.add_edge(vp.first, vp.second, vcaps[v]);
        }
    }
    return {old_new_vertex_map, new_graph};
}
