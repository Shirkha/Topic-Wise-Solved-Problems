Largest Divisible Subset ( Concept of LIS)

Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:

        answer[i] % answer[j] == 0, or
        answer[j] % answer[i] == 0


bool isSatisfy(int x, int y) {
	return x % y == 0;
}
vector<int> largestDivisibleSubset(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	int n = nums.size();
	vector<int> dp(n, 1);
	vector<int> hash(n, 0);
	int maxLen = 1, lastIndex = 0;

	for (int i = 0; i < n; i++) {
		hash[i] = i;
		for (int prev = 0; prev < i; prev++) {
			if (isSatisfy(nums[i], nums[prev]) and dp[prev] + 1 > dp[i]) {
				dp[i] = 1 + dp[prev];
				hash[i] = prev;
			}
		}
		if (dp[i] > maxLen) {
			maxLen = dp[i];
			lastIndex = i;
		}
	}
	vector<int> res;
	res.push_back(nums[lastIndex]);
	while (hash[lastIndex] != lastIndex) {
		lastIndex = hash[lastIndex];
		res.push_back(nums[lastIndex]);
	}
	return res;
}