Q. Minimum Falling Path Sum
Can start at any point and end at any poin
## Variable starting point and ending point

class Solution {
public:
    // Recursive TC = 3^N    (Not 3^NM  Tink Why?)
    
    /****Recursive + memoization****/
    //TC = O(MN)   SC = O(MN)+ O(N)
    // n-1 -----> 0
    int solve(int i,int j,int n,int m,vector<vector<int>>& arr,vector<vector<int>>& dp){
        if(j < 0 or j >= m)
            return 1e9;      // Return big value so we don't consider this
        if(i == 0)
            return arr[i][j];
        
        if(dp[i][j] != INT_MIN)
            return dp[i][j];
        
        int up = arr[i][j] + solve(i-1,j,n,m,arr,dp);
        int ld = arr[i][j] + solve(i-1,j-1,n,m,arr,dp);
        int rd = arr[i][j] + solve(i-1,j+1,n,m,arr,dp);
        
        return dp[i][j] = min(up,min(ld,rd));
        
    }
  
    int minFallingPathSum(vector<vector<int>>& arr) {
       int n = arr.size();
       int m = arr[0].size();
       int minPath = INT_MAX;
       vector<vector<int>> dp(n,vector<int>(m,INT_MIN)); 
       for(int j=0; j<m; j++){
           int path = solve(n-1,j,n,m,arr,dp);
           minPath = min(minPath,path);
       }
        
        
          /****Tabulation****/
        //TC = O(MN)   SC = O(MN)
    // 0---->n-1
        vector<vector<int>> dp(n,vector<int>(m));
        for(int j=0; j<m; j++)
            dp[0][j] = arr[0][j];
        
        for(int i=1; i<n; i++)
            for(int j=0; j<m; j++){
                int up = arr[i][j] + dp[i-1][j];
                int ld = 1e9, rd = 1e9;
                if(j  > 0)
                    ld = arr[i][j] + dp[i-1][j-1];
                if(j < m-1)
                    rd = arr[i][j] + dp[i-1][j+1];
                
                dp[i][j] = min(up,min(ld,rd));
            }
         
        for(int j=0; j<m; j++)
            minPath = min(minPath,dp[n-1][j]);
        
        /****Space optimization****/
        //TC = O(MN)  SC = O(M)
        vector<int> dp(m);
        for(int j=0; j<m; j++)
            dp[j] = arr[0][j];
        
        for(int i=1; i<n; i++){
            vector<int> curr(m);
            for(int j=0; j<m; j++){
                int up = arr[i][j] + dp[j];
                int ld = 1e9, rd = 1e9;
                if(j > 0)
                    ld = arr[i][j] + dp[j-1];
                if(j < m-1)
                    rd = arr[i][j] + dp[j+1];
                
                curr[j] = min(up,min(ld,rd));
            }
            dp = curr;
        }
        
        for(int j=0; j<m; j++)
            minPath = min(minPath,dp[j]);
       
        return minPath; 
    }
};