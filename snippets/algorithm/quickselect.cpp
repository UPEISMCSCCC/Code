#define QSNE -999999

int partition(int arr[], int l, int r)
{
	int x = arr[r], i = l;
	for (int j = l; j <= r - 1; j++)
		if (arr[j] <= x)
			swap(arr[i++], arr[j]);
	swap(arr[i], arr[r]);
	return i;
}

// find k'th smallest element in unsorted array, only if all distinct
int qselect(int arr[], int l, int r, int k)
{
	if (!(k > 0 && k <= r - l + 1)) return QSNE;
	swap(arr[l + rng() % (r-l+1)], arr[r]);
	int pos = partition(arr, l, r);
	if (pos-l==k-1) return arr[pos];
	if (pos-l>k-1) return qselect(arr,l,pos-1,k);
	return qselect(arr, pos+1, r, k-pos+l-1);
}

// TODO: compare against std::nth_element()