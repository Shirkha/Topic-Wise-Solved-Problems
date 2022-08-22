Print LIS

class Solution {
public:
	// Using another tabulation apporach we can print the LIS
	// TC = O(n^2)   SC = O(n)
	int lengthOfLIS(vector<int>& nums) {
		int n = nums.size();
		vector<int> dp(n, 1); // Length of LIS till ith index
		vector<int> hash(n);
		int maxlen = 0;
		int lastindex = 0;  // last index of lis
		for (int i = 0; i < n; i++) {
			hash[i] = i;
			for (int prev = 0; prev < i; prev++) {
				if (nums[i] > nums[prev] and 1 + dp[prev] > dp[i]) { // add the curr element to LIS till prev if we can get maxlen
					dp[i] = 1 + dp[prev];
					hash[i] = prev;
				}
			}
			// maxlen = max(maxlen,dp[i]);
			if (dp[i] > maxlen) {
				maxlen = dp[i];
				lastindex = i;
			}
		}

		vector<int> lis;
		lis.push_back(nums[lastindex]);

		while (hash[lastindex] != lastindex) {
			lastindex = hash[lastindex];
			lis.push_back(nums[lastindex]);
		}

		reverse(lis.begin(), lis.end());
		for (auto x : lis)
			cout << x << " ";

		return maxlen;
	}
};