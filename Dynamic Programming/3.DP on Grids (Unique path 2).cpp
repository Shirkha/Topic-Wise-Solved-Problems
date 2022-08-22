DP on Grids
## Unique path II      if(grid[i][j] == 1)--->Obstacles

1. Recursive + memoization
  TC= O(m*n)  SC = O(m - 1 + n -1) + O(m*n)

int uniquePath(vector<vector<int>> &grid){
	int m = grid.size(), n = grid[0].size();
	vector<vector<int>> dp(m,vector<int>(n,-1));
	return solve(m-1,n-1,grid,dp);
}

int solve(int i,int j,vector<vector<int>> &grid,vector<vector<int>> &dp){
	if(i<0 or j<0 or grid[i][j] == 1)
	  return 0;
	if(i==0 and j==0)   // not--> i==0 or j==0 --->there may be obstacles in the first row or first col
	  return 1; 
	if(dp[i][j] != -1)
	 return dp[i][j];

	return dp[i][j] = solve(i-1,j,grid,dp) + solve(i,j-1,grid,dp);    
}

2. Tabulation
TC = O(M*N)  SC = O(M*N)

int uniquePaths(grid){
	int dp[m][n];

	for(int i=0; i<m; i++)
	 for(int j=0; j<n; j++){
	   if(grid[i][j] == 1)
	     dp[i][j] = 0;
	   else if(i == 0 and j == 0)
	          dp[i][j] = 1;
	    else{
	       int up = 0;
	       int left = 0;
	       if(i > 0)
	        up = dp[i-1][j];
	       if(j > 0)
	        left = dp[i][j-1];
	       dp[i][j] = left + up;   
	    }        
	 }
	 return dp[m-1][n-1];
}

3. Space optimize     TC = O(M*N)  SC = O(N)

int uniquePath(grid){
	vector<int> pre(n,0);

	for(int i=0; i<m; i++){
	  vector<int> temp(n,0);
	  for(int j=0; j<n; j++){
	     if(grid[i][j] == 1)
	       temp[j] = 0;
	     else if(i == 0 and j == 0)
	             temp[j] = 1;
	     else{
	        int up = 0, left = 0;
	        if(i > 0)
	          up = pre[j];
	        if(j > 0)
	          left = temp[j-1];

	        temp[j] = up + left;    
	     }            
	  }
	  pre = temp;
	}
	return pre[n-1];
}