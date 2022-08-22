Q. Frog jump  (can jump i+i or i+2)
-->Again fibonacci pattern ---> f(n) = f(n-1) + f(n-2);
-->Fibonacci pattern can always be space optimized

1. Recursive + memoization
TC = O(N)  SC = O(N) + O(N)

int frogJump(int n,vector<int> &arr){
	vector<int> dp(n,-1);
	return solve(n-1,arr);                     ---->0 based indexing
}

int solve(int n,vector<int> &arr){
	if(n == 0)
	 return 0;
    if(dp[n] != -1)
     return dp[n];

    int fs = solve(n-1,arr) + abs(arr[n] - arr[n-1])  ---> 1 step
    int ss = INT_MAX;
    if(n >= 2)
     ss = solve(n-2,arr) + abs(arr[n] - arr[n-2])     ---->2 step
    return dp[n] = min(fs,ss); 
}

2. Tabulation
TC = O(N) SC = O(N)

int frogJump(int n,vector<int> &arr){
	vector<int> dp(n);
	dp[0] = 0;

	for(int i=1; i<n; i++){
	  int fs = dp[i-1] + abs(arr[i] - arr[i-1]);
	  int ss = INT_MAX;
	  if(i >= 2)
	    ss = dp[i-2] + abs(arr[i] - arr[i-2]);
	  dp[i] = min(fs,ss);  
	}
	return dp[n-1];
}

3. Space optimization
TC = O(N)  SC = O(1)

**replace ---> dp[i]--> curr,   dp[i-1]--> prev1, dp[i-2]-->prev2
int frogJump(int n,vector<int> &arr){
       int prev2 = 0;
       int prev1 = 0;

       for(int i=1;i<n; i++){
         int fs = prev1 + abs(arr[i] - arr[i-1]);
         int ss = INT_MAX;
         if(i >=2)
           ss = prev2 + abs(arr[i] - arr[i-2]);
         curr = min(fs,ss);
         prev2 = prev1;
         prev1 = curr;  
       }
      return prev1; 
	}

