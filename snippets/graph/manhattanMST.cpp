// given N points with integer coordinates
// returns at most 4N edges which will contain the MST
// where weight is the manhatten (abs(x1-x2)+abs(y1-y2))
// take these edges, make undirected graph, then run mst
// seems to be an NlogN construction, taken from 
// https://github.com/kth-competitive-programming/kactl/blob/master/content/geometry/ManhattanMST.h
// and modified slightly for use by us
// solves https://open.kattis.com/problems/gridmst
// may also work for floating point coordinates

typedef complex<int> P;
vector<edge> manhattanMST(vector<P> ps) {
    vector<int> id(ps.size());
	  iota(id.begin(), id.end(), 0);
	  vector<edge> edges;
    const auto cmp = [&](int i, int j) {return real(ps[i]-ps[j])<imag(ps[j]-ps[i]);};
	  for(int k=0;k<4;k++) {
		    sort(id.begin(), id.end(), cmp);
		    map<int, int> sweep;
		    for (int i : id) {
            auto it=sweep.lower_bound(-imag(ps[i]));
			      for (;it!=sweep.end();sweep.erase(it++)) {
				        int j = it->second;
				         P d = ps[i]-ps[j];
				        if (imag(d) > real(d)) break;
				        edges.push_back({i, j, imag(d) + real(d)});
			      }
			      sweep[-imag(ps[i])] = i;
		    }
		    for (P& p : ps)
            if(k%2!=0) p = P(-real(p), imag(p));
            else p = P(imag(p), real(p));
    }
	  return edges;
}
