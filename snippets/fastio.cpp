// read int fast -- no negatives
void readn(int& n) {
	char c; n = 0;
	while ((c = getchar_unlocked()) != ' ' && c != '\n')
		n = n * 10 + c - '0';
}