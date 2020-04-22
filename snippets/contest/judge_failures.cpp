// each case tests a different fail condition
// try them before contests to see error codes
struct g { int arr[1000000]; g(){}};
vector<g> a;
// 0=WA 1=TLE 2=MLE 3=OLE 4=SIGABRT 5=SIGFPE 6=SIGSEGV 7=recursive MLE
int judge(int n) {
	if (n == 0) exit(0);
	if (n == 1) while(1);
	if (n == 2) while(1) a.push_back(g());
	if (n == 3) while(1) putchar_unlocked('a');
	if (n == 4) assert(0);
	if (n == 5) 0 / 0;
	if (n == 6) *(int*)(0) = 0; 
	return n + judge(n + 1);
}