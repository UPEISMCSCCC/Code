#define ll long long

// given n items with weights wt[i] and values val[i]
// chooses a subset of items with maximal value sum and weight sum <=W
// uses O(nW) time and space; wt==val is a subset sum problem
// returns vec of indices of chosen items and last element equalling value collected
vector<ll> knapSack(int W, vector<int> &wt, vector<int> &val, int n) {
   int i, w; 
   int K[n+1][W+1];
   for (i = 0; i <= n; i++) 
   { 
     for (w = 0; w <= W; w++) 
     {
       if (i==0 || w==0) 
         K[i][w] = 0; 
       else if (wt[i-1] <= w)
         K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]); 
       else
         K[i][w] = K[i-1][w]; 
     } 
   }
   int res = K[n][W];
     
   w = W;
   ll s = 0;
   vector<ll> x;
   for (i = n; i > 0 && res > 0; i--) {
    if (res == K[i - 1][w])  
     continue;         
    else {
     s += val[i-1];
     x.push_back(i-1);
     res = res - val[i - 1]; 
     w = w - wt[i - 1]; 
    } 
   }
   x.push_back(s);
   return x;
}
