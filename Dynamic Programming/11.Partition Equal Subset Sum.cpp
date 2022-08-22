Partition Equal Subset Sum
-- > Partition array into 2 subsets of equal sum
-- > Slight variation of subset sum


bool canPartition(vector<int>& arr) {
	int sum = 0;
	for (int &i : arr)
		sum += i;
	if (sum & 1)           // if odd can't be partitioned
		return false;
	// else check whether it can be using subset sum
	int n = arr.size();
	int target = sum / 2;
	//vector<vector<int>> dp(n,vector<int>(target+1,-1));
	return check(target, arr);
}
// check whether it is possible to get subset of sum target

bool check(int target, vector<int> &arr) {

	/***Recursive***/
	if (target == 0)
		return true;
	if (ind == 0)
		return arr[0] == target;

	if (dp[ind][target] != -1)
		return dp[ind][target];

	bool notTake = check(ind - 1, target, arr, dp);
	bool take = false;
	if (arr[ind] <= target)
		take = check(ind - 1, target - arr[ind], arr, dp);

	return dp[ind][target] = take or notTake;

	/***Tabulation****/
	int n = arr.size();
	bool dp[n][target + 1];

	for (int i = 0; i < n; i++)
		dp[i][0] = true;

	for (int j = 1; j <= target; j++)
		dp[0][j] = false;
	if (arr[0] <= target)
		dp[0][arr[0]] = true;

	for (int i = 1; i < n; i++)
		for (int j = 1; j <= target; j++) {
			bool notTake = dp[i - 1][j];
			bool take = 0;
			if (arr[i] <= j)
				take = dp[i - 1][j - arr[i]];

			dp[i][j] = take or notTake;
		}
	return dp[n - 1][target];

	/****Space optimizir*****/
	vector<bool> prev(target + 1, 0), curr(target + 1, 0);
	prev[0] = 1;
	curr[0] = 1;
	if (arr[0] <= target)
		prev[arr[0]] = 1;

	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= target; j++) {
			bool notTake = prev[j];
			bool take = 0;
			if (arr[i] <= j)
				take = prev[j - arr[i]];

			curr[j] = take or notTake;
		}
		prev = curr;
	}
	return prev[target];
}
