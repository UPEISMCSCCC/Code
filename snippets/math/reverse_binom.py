def binom(n, k):
	k = min(k, n - k)
	ans = 1
	for i in range(k):
		ans *= n - i
		ans //= i + 1
	return ans

def first_over(k, c):
	"""Binary search to find smallest value of n for which n^k >= c"""
	n = 1
	while n ** k < c:
		n *= 2
	# Invariant: lo**k < c <= hi**k
	lo = 1
	hi = n
	while hi - lo > 1:
		mid = lo + (hi - lo) // 2
		if mid ** k < c:
			lo = mid
		else:
			hi = mid
	return hi

def find_n_k(x):
	"""Given x>1, yields all n and k such that binom(n, k) = x."""
	k = 0
	while True:
		k += 1
		# https://math.stackexchange.com/a/103385/205
		if (2 * k + 1) * x <= 4**k:
			break
		nmin = first_over(k, math.factorial(k) * x)
		nmax = nmin + k + 1
		nmin = max(nmin, 2 * k)
		choose = binom(nmin, k)
		for n in range(nmin, nmax):
			if choose == x:
				yield (n, k)
				if k < n - k:
					yield (n, n - k)
			choose *= (n + 1)
			choose //= (n + 1 - k)
