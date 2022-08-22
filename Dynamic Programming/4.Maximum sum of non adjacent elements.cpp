##Maximum sum of non adjacent elements/ House Robber

1. Recursive + memoization
TC = O(N)  SC = O(N) + O(N)

int houseRob(vector<int> &nums){
	int n = nums.size();
	vector<int> dp(n,-1);
	return solve(n-1,nums,dp);
}
int solve(int ind,vector<int> &nums,vector<int> &dp){
	if(ind < 0)
	 return 0;
	if(ind == 0)
	 return nums[0];

	if(dp[ind] != -1)
	 return dp[ind];

	int pick = nums[ind] + solve(ind-2,nums,dp);
	int notPick = solve(ind-1,nums,dp);

	return dp[ind] = max(pick,notPick);  
}
2. Tabulation TC = O(N)  SC = O(N)

int houseRob(nums){
	vector<int> dp(n);
	dp[0] = nums[0];
	
	for(int i=1; i<n; i++){
     int pick = nums[i];
     if(i>1)
      pick += dp[i-2];
     int notPick = dp[i-1];
     dp[i] = max(pick,notPick); 
  }	
  return dp[n-1];
}
3. Space optimization  TC = O(N)  SC = O(1)
dp[i-2]---->prev2
dp[i-1]---->prev1

int houseRob(nums){
	int prev1 = nums[0];
	int prev2 = nums[0];

	for(int i=1; i<n; i++){
	int pick = nums[i];
	if(i>1)
	 pick += prev2;
	int notPick = prev1;
	
	int curr = max(pick,notPick);
	prev2 = prev1;
	prev1 = curr; 
 }
 return prev1;
}