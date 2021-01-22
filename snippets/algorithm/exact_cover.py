def exact_cover(x, subsets, getall = False):
	def solve(X, Y, solution=[]):
		if not X:
			yield list(solution)
		else:
			c = min(X, key=lambda c: len(X[c]))
			for r in list(X[c]):
				solution.append(r)
				cols = select(X, Y, r)
				for s in solve(X, Y, solution):
					yield s
				deselect(X, Y, r, cols)
				solution.pop()
	def select(X, Y, r):
		cols = []
		for j in Y[r]:
			for i in X[j]:
				for k in Y[i]:
					if k != j:
						X[k].remove(i)
			cols.append(X.pop(j))
		return cols
	def deselect(X, Y, r, cols):
		for j in reversed(Y[r]):
			X[j] = cols.pop()
			for i in X[j]:
				for k in Y[i]:
					if k != j:
						X[k].add(i)
	# map X_i to list of covered Y_js
	X = {j: set() for j in x}
	for i in subsets:
		for j in subsets[i]:
			X[j].add(i)
	return list(solve(X, subsets)) if getall else next(solve(X, subsets))

# example
X = {1, 2, 3}
Y = {'a':[1], 'b':[2], 'c':[1,2,3], 'd':[2,3], 'e':[1]}
print(exact_cover(X, Y)) # print an answer
print(exact_cover(X, Y, True)) # print all