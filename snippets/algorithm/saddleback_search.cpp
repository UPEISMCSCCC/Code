// search for v in 2d array arr[x][y], sorted on both axis
pair<int, int> saddleback_search(int** arr, int x, int y, int v) {
	int i = x-1, j = 0;
	while (i >= 0 && j < y) {
		if (arr[i][j] == v) return {i, j};
		if (arr[i][j] > v) i--;
		else j++;
	}
	return {-1, -1};
}
