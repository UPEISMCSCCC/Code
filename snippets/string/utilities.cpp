void lowercase(string& s) {
	transform(s.begin(), s.end(), s.begin(), ::tolower);
}
void uppercase(string& s) {
	transform(s.begin(), s.end(), s.begin(), ::toupper);
}
void trim(string &s) {
	s.erase(s.begin(),find_if_not(s.begin(),s.end(),[](int c){return isspace(c);}));
	s.erase(find_if_not(s.rbegin(),s.rend(),[](int c){return isspace(c);}).base(),s.end());
}
vector<string> split(string& s, char token) {
    vector<string> v; stringstream ss(s);
    for (string e;getline(ss,e,token);)
        v.push_back(e);
    return v;
}