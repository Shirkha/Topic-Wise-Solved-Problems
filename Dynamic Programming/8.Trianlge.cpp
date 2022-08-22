Q. Trianlge
Given a triangle array, return the minimum path sum from top to bottom.
-->Fixed starting variable ending point 

class Solution {
public:
    int solve(int i,int j,vector<vector<int>> &arr,vector<vector<int>> &dp){
        // if(j >= arr.size())   // Not required-->we will never go out of bound in j
        //     return 0;
        if(i == arr.size()-1)
            return arr[i][j];
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int sum1 = arr[i][j] + solve(i+1,j,arr,dp);
        int sum2 = arr[i][j] + solve(i+1,j+1,arr,dp);
        
        return dp[i][j] = min(sum1,sum2);
            
    }
    
    int minimumTotal(vector<vector<int>>& arr) {
        int n = arr.size();
        /***Recursive + Memoization****/ //(Top down)
        // (0,0)---->(n-1,0) or (n-1,1) or.......(n-1,n-1)  i.e. (n-1,j)
        
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(0,0,arr,dp);
        
        /***Tabulation*****/ //(Bottom Up)
        // Thumb rule---> In tabulation we go opposite way to Recursive
        // (n-1,j)------> (0,0)
        
        int dp[n][n];
        for(int j=0; j<n; j++)
            dp[n-1][j] = arr[n-1][j];
        
        for(int i=n-2; i>=0; i--)
           for(int j=i; j>=0; j--){
               int sum1 = arr[i][j] + dp[i+1][j];
               int sum2 = arr[i][j] + dp[i+1][j+1];
               dp[i][j] = min(sum1,sum2);
           } 
        return dp[0][0];
        
        /****Space Optimization***/
        vector<int> dp(n);
        for(int j=0; j<n; j++)
            dp[j] = arr[n-1][j];
        
        for(int i=n-2; i>=0; i--){
           vector<int> curr(n); 
           for(int j=i; j>=0; j--){
               int sum1 = arr[i][j] + dp[j];
               int sum2 = arr[i][j] + dp[j+1];
               curr[j] = min(sum1,sum2);
           }
            dp = curr;
        }
        return dp[0];
    }
};