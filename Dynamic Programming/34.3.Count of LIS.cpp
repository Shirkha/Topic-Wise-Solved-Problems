Count of LIS  (See Again little bit tricky)

int findNumberOfLIS(vector<int>& nums) {
	int n = nums.size();
	vector<int> dp(n, 1), count(n, 1);
	int maxl = 1, index = 0;
	for (int i = 0; i < n; i++) {
		for (int prev = 0; prev < i; prev++) {
			if (nums[i] > nums[prev]) {
				if (1 + dp[prev] > dp[i]) {
					dp[i] = 1 + dp[prev];
					count[i] = count[prev];  // no of possible way to form lis will be same                                                         as the element at prev
				}

				else if (1 + dp[prev] == dp[i])
					count[i] += count[prev];  // we will add the way of prev. Sine we already                                                    got lis with other prev element
			}
		}
		maxl = max(maxl, dp[i]);
	}
	int res = 0;
	for (int i = 0; i < n; i++) {
		if (dp[i] == maxl)
			res += count[i];
	}
	return res;