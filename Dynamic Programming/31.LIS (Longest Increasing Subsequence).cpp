LIS (Longest Increasing Subsequence)

class Solution {
public:
	// (index,prev_index) ---> Find length of LIS starting from index if elements upto prev_index is included
	// Recursive  + memoization  (0----->n-1)
	// TC = O(n*n)  SC = O(n*n) + O(n)
	int find(int ind, int prev, vector<int> &nums, vector<vector<int>> &dp) {
		if (ind == nums.size())
			return 0;
		if (dp[ind][prev + 1] != -1)
			return dp[ind][prev + 1];

		int len = find(ind + 1, prev, nums, dp); // notPick
		if (prev == -1 || nums[ind] > nums[prev])
			len = max(len, 1 + find(ind + 1, ind, nums, dp)); // pick

		return dp[ind][prev + 1] = len;
	}

	int lengthOfLIS(vector<int>& nums) {

		int n = nums.size();
		vector<vector<int>> dp(n, vector<int>(n + 1, -1)); // to handle prev_index = -1---> shift the prev_index
		return find(0, -1, nums, dp);

		// Tabulation  (n-1----->0)
		// TC = O(n^2) = SC
		//(index shifting is tricky part)
		vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

		for (int ind = n - 1; ind >= 0 ; ind--) {
			for (int prev = ind - 1 ; prev >= -1; prev--) {
				int len = dp[ind + 1][prev + 1];
				if (prev == -1 || nums[ind] > nums[prev])
					len = max(len, 1 + dp[ind + 1][ind + 1]);
				dp[ind][prev + 1] = len;
			}
		}
		return dp[0][-1 + 1];
	}
};


// Using another tabulation apporach we can print the LIS
// TC = O(n^2)   SC = O(n)
int lengthOfLIS(vector<int>& nums) {
	int n = nums.size();
	vector<int> dp(n, 1); // Length of LIS till ith index
	int maxlen = 0;
	for (int i = 0; i < n; i++) {
		for (int prev = 0; prev < i; prev++) {
			if (nums[i] > nums[prev]) { // add the curr element to LIS till prev if we can get maxlen
				dp[i] = max(dp[i], 1 + dp[prev]);
			}
		}
		maxlen = max(maxlen, dp[i]);
	}
	return maxlen;
}