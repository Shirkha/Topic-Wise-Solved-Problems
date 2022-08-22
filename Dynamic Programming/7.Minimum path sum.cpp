Q. Minimum path sum
Fixed starting and ending points

1. Recursive + memoization   TC = O(MN)  SC = O(MN) + O(M-1+N-1)
int solve(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& dp){
        if(i<0 or j<0)
            return 1e9;   // Don't consider out of bound path
        if(i==0 and j==0)
            return grid[i][j];
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int up = grid[i][j] + solve(i-1,j,grid,dp);
        int left = grid[i][j] + solve(i,j-1,grid,dp);
        
        return dp[i][j] = min(up,left);
        
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(m-1,n-1,grid,dp);
    }

 2. Tabulation      TC = O(MN) SC = O(MN)
   vector<vector<int>> dp(m,vector<int>(n));
        
      for(int i=0; i<m; i++)
        for(int j=0; j<n; j++){
             if(i==0 and j==0)
                  dp[i][j] = grid[i][j];
              else{
                   int up = 1e9;
                  if(i > 0)
                      up = grid[i][j] + dp[i-1][j];
                   int left = 1e9;
                   if(j > 0)
                      left = grid[i][j] + dp[i][j-1];
              
               dp[i][j] = min(up,left);
           }
           }
         return dp[m-1][n-1];
      }
 3. Space optimization   	SC = O(MN)

  vector<int> prev(n);
        for(int i=0; i<m; i++){
           vector<int> curr(n);  
          for(int j=0; j<n; j++){
              if(i==0 and j==0)
                  curr[j] = grid[i][j];
              else{
                  int up = 1e9;
                  if(i>0)
                     up = grid[i][j] + prev[j];
                  int left = 1e9;
                  if(j>0)
                      left = grid[i][j] + curr[j-1];
                  
                  curr[j] = min(up,left);
              }
          }
          prev = curr;  
        }
        return prev[n-1];
