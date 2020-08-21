#define vi vector<int>
#define vb vector<bool>

/* get bridges (edges which if removed increases SCC count) in an undirected graph
*  complexity: O(V+E)
*  usage:
*  BridgeGraph G(V);
*  G.addEdge(...);   // add a bunch of edges
*  G.findBridges();  // G.bridges now holds the edges
*  Solves:
*  https://open.kattis.com/problems/birthday (direct solve, check if G.bridges.size() > 0)
*  https://open.kattis.com/problems/caveexploration (slight additional work for this one)
*/
struct BridgeGraph {
    int V;
    vector<vi> adj;
    vector<pair<int, int>> bridges;
    
    BridgeGraph(int V) : V(V), adj(V) {}
    
    void addEdge(int v, int w) { adj[v].push_back(w), adj[w].push_back(v); }
    
    void bridgeUtil(int u, vb &visited, vi &disc, vi &low, vi &parent) {
        static int time = 0;
        visited[u] = true;
        disc[u] = low[u] = ++time;
        for (int v : adj[u]) {
            if (!visited[v]) {
                parent[v] = u; 
                bridgeUtil(v, visited, disc, low, parent); 
                low[u] = min(low[u], low[v]); 
                if (low[v] > disc[u]) 
                    bridges.push_back({u, v});
            }
            else if (v != parent[u]) 
                low[u] = min(low[u], disc[v]); 
        }
    }
    
    void findBridges() {
        vb visited(V, false);
        vi disc(V), low(V), parent(V,-1);
        for (int i = 0; i < V; i++)
            if(!visited[i])
                bridgeUtil(i, visited, disc, low, parent);
    }
};
