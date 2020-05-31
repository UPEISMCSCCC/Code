// L,R = interval [L,R], in = {{l,r}, index}
vector<int> intervalCover(double L, double R, vector<pair<pair<double,double>,int>> in) {
    int i = 0; pair<double,int> pos = {L,-1}; vector<int> a;
    sort(begin(in), end(in));
    while (pos.first < R) {
        double cur = pos.first;
        while (i < (int)in.size() && in[i].first.first <= cur)
            pos = max(pos,{in[i].first.second,in[i].second}), i++;
        if (pos.first == cur) return {};
        a.push_back(pos.second);
    }
    return a;
}