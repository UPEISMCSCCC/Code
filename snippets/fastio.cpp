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
