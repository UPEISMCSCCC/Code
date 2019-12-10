// integrate f from a to b, k iterations
// error <= (b-a)/18.0 * M * ((b-a)/2k)^4
// where M = max(abs(f````(x))) for x in [a,b]
// "f" is a function "double func(double x)"
double Simpsons(double a, double b, int k, double (*f)(double)) {
	double dx = (b-a)/(2.0*k), t = 0;
	for (int i = 0; i < k; i++)
		t += ((i==0)?1:2)*(*f)(a+2*i*dx) + 4 * (*f)(a+(2*i+1)*dx);
	return (t + (*f)(b)) * (b-a) / 6.0 / k;
}
