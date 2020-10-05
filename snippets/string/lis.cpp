// longest increasing subsequence
#define T int
int ceil_idx(vector<T> &arr, vector<int>& t, int l, int r, int key) { 
    while (r - l > 1) { 
        int m = l + (r - l) / 2; 
        if (arr[t[m]] >= key)
            r = m;
        else
            l = m; 
    }
    return r; 
}

int lis(vector<T> &arr) {
    if(arr.size() == 0) return 0;
    int n = arr.size();
    vector<int> tailIndices(n, 0);
    vector<int> prevIndices(n, -1);
    int len = 1;
    for (int i = 1; i < n; i++) { 
        if (arr[i] < arr[tailIndices[0]]) { 
            tailIndices[0] = i; 
        } 
        else if (arr[i] > arr[tailIndices[len - 1]]) { 
            prevIndices[i] = tailIndices[len - 1]; 
            tailIndices[len++] = i; 
        } 
        else {
            int pos = ceil_idx(arr, tailIndices, -1, len - 1, arr[i]);
            prevIndices[i] = tailIndices[pos - 1]; 
            tailIndices[pos] = i; 
        } 
    }
    return len;
}
