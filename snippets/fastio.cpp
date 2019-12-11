void readn(unsigned int& n) {
	char c; n = 0;
	while ((c = getchar_unlocked()) != ' ' && c != '\n')
		n = n * 10 + c - '0';
}

void readn(int& n) {
	char c; n = 0; int s = 1;
	if ((c = getchar_unlocked()) == '-') s = -1;
	else n = c - '0';
	while ((c = getchar_unlocked()) != ' ' && c != '\n')
		n = n * 10 + c - '0';
	n *= s;
}

void readn(long double& n) {
	char c; n = 0;
	long double m = 0, o = 1; bool d = false; int s = 1;
	if ((c = getchar_unlocked()) == '-') s = -1;
	else if (c == '.') d = true;
	else n = c - '0';
	while ((c = getchar_unlocked()) != ' ' && c != '\n') {
		if (c == '.') d = true;
		else if (d) { m = m * 10 + c - '0'; o *= 0.1; }
		else n = n * 10 + c - '0';
	}
	n = s * (n + m * o);
}
void readn(double& n) {
	long double m; readn(m); n = m;
}
void readn(float& n) {
	long double m; readn(m); n = m;
}

void readn(string& s) {
    char c; s = "";
    while((c = getchar_unlocked()) != ' ' && c != '\n')
        s += c;
}

void printn(unsigned int& n) {
    if (n / 10) 
        printn(n / 10); 
    putchar_unlocked(n % 10 + '0');
}
