from decimal import Decimal, getcontext
def calc_pi(digits):
	getcontext().prec = digits+2
	C, D = Decimal(24)/Decimal(640320**3), 426880*Decimal(10005).sqrt()
	A, S, T  =  1, 1, 0
	for k in range(1,digits):
		A *= -C*(6*k-5)*(2*k-1)*(6*k-1)/Decimal(k**3)
		S += A
		T += A*k
	return D/Decimal(13591409*S + 545140134*T)
