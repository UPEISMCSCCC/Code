/*
* A bipartite graph has "left" and "right" set of nodes
* Every edge has an endpoint in each set (L/R)
* A matching is a subset of all edges
* Such that each vertex is an endpoint
* Of at most one edge in the subset
* Runtime `O(sqrt(V)E)`
* Source for original algorithm: https://codeforces.com/blog/entry/58048
* Tested on https://open.kattis.com/problems/pianolessons
*/

#define MAX_NODES 1001
bitset<MAX_NODES> V;

bool match(int node, Vec<2,int> &G, vector<int> &R, vector<int> &L) {
    if (V[node]) return false;
    V[node] = 1;
    for(auto vec : G[node]) {
        if (R[vec] == -1 || match(R[vec], G, R, L)) {
            L[node] = vec; R[vec] = node;
            return true;
        }
    }
    return false;
}

/*
* G[i] = nodes on other side adjacent to i on this side
* m = number of nodes in other side
* returns vector of the matches (u,v)
* vertices are 0,...,G.size() and 0,...,m-1
*/
vector<pair<int, int>> bipartite_match(Vec<2, int> &G, int m) {
    vector<int> L(G.size(), -1), R(m, -1);
    V.reset();
    bool running = true;
    while (running) {
        running = false;
        V.reset();
        for (int i=0;i<L.size();i++)
            if (L[i] == -1)
                running |= match(i, G, R, L);
    }
    vector<pair<int,int>> ret;
    for (int i = 0; i < L.size(); ++i)
        if(L[i]!=-1) ret.push_back({i, L[i]});
    return ret;
}
