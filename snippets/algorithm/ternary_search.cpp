// < max, > min, or any other unimodal func
#define TERNCOMP(a,b) (a)<(b)
int ternsearch(int a, int b, int (*f)(int)) {
	while (b-a > 4) {
		int m = (a+b)/2;
		if (TERNCOMP((*f)(m), (*f)(m+1))) a = m;
		else b = m+1;
	}
	for (int i = a+1; i <= b; i++)
		if (TERNCOMP((*f)(a), (*f)(i)))
			a = i;
	return a;
}

#define TERNPREC 0.000001
double ternsearch(double a, double b, double (*f)(double)) {
	while (b-a > TERNPREC * 4) {
		double m = (a+b)/2;
		if (TERNCOMP((*f)(m), (*f)(m + TERNPREC))) a = m;
		else b = m + TERNPREC;
	}
	for (double i = a + TERNPREC; i <= b; i += TERNPREC)
	    if (TERNCOMP((*f)(a), (*f)(i)))
			a = i;
	return a;
}
