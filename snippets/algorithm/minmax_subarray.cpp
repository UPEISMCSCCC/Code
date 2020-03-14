// max - compare = a < b, reset = a < 0
// min - compare = a > b, reset = a > 0
// returns {sum, {start, end}}
pair<int, pair<int, int>> ContiguousSubarray(int* a, int size, bool(*compare)(int, int), bool(*reset)(int), int defbest = 0) {
	int best = defbest, cur = 0, start = 0, end = 0, s = 0;
	for (int i = 0; i < size; i++) {
		cur += a[i];
		if ((*compare)(best, cur)) { best = cur; start = s; end = i; }
		if ((*reset)(cur)) { cur = 0; s = i + 1; }
	}
	return {best, {start, end}};
}
