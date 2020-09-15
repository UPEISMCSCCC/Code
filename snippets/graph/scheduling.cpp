// scheduling problem, some amount of people need to work on each day
// each person has list of days they can work
// all people can work at most a certain number of days
// is a certain number of days on the schedule
// assumes people are zero-indexed, days are 1-indexed

// possibles -> map from people to days they can work
// needed_per_day -> number of people needed on schedule for each day
// n_days -> number of days to schedule
// max_per_person -> max number of days each person can work
// returns {is_valid_soln, map_of_days_to_people_working_on_that_day}
// note that max_per_person = 1 and needed_per_day = 1 corresponds to bipartite

// solves https://open.kattis.com/problems/dutyscheduler in 0.00s
// to solve dutyscheduler, repeatedly call the method with increasing max_per_person (1,2,...) until a solution is found

pair<bool, umap<ll, vector<ll>>> check_schedule(unordered_map<ll, vector<ll>> &possibles, ll needed_per_day, ll n_days, ll max_per_person) {
    ll n_people = possibles.size();
    ll n_nodes = n_people + n_days + 2;
    ll s = n_nodes-2, t = n_nodes-1;
    MaxFlowGraph G(n_nodes, s, t);
    for(auto p : possibles) {
        ll x = p.first;
        for(ll d : p.second) {
            ll didx = d-1 + n_people;
            G.add_edge(x, didx, 1); // person -> day edge
        }
        G.add_edge(s, x, max_per_person); // source -> person edge
    }
    for(ll d=n_people;d<s;d++) {
        G.add_edge(d, t, needed_per_day);
    }
    pair<ll, vector<FlowEdge>> soln = G.flow();
    if(soln.first != needed_per_day*n_days) return {false, {}};
    umap<ll, vector<ll>> schedule;
    for(const auto &fe : soln.second) {
        if(fe.v != s && fe.u != t) { // is an edge from a person to a day
            schedule[fe.u - n_people + 1].push_back(fe.v);
        }
    }
    return {true, schedule};
}
