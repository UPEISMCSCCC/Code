void lowercase(string& s) {
    transform(s.begin(), s.end(), s.begin(), ::tolower);
}
void uppercase(string& s) {
    transform(s.begin(), s.end(), s.begin(), ::toupper);
}