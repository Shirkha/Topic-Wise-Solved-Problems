Longest Bitonic subsequence
A subsequence of array is called Bitonic if it is first increasing, then decreasing. (can be only increasing or only decreasing)

//Solution: Find  l1 = LIS(L--------->R)   and l2 = LIS(L < ------R)
	// ans = l1 + l2 - 1(same no included in both dirn)

	int LongestBitonicSequence(vector<int>nums)
{

	int n = nums.size();
	vector<int> dp1(n, 1);

	for (int i = 0; i < n; i++) {
		for (int prev = 0; prev < i; prev++) {
			if (nums[i] > nums[prev] and 1 + dp1[prev] > dp1[i])
				dp1[i] = 1 + dp1[prev];
		}
	}

	vector<int> dp2(n, 1);
	for (int i = n - 1; i >= 0; i--) {
		for (int next = n - 1; next > i; next--) {
			if (nums[i] > nums[next] and 1 + dp2[next] > dp2[i])
				dp2[i] = 1 + dp2[next];
		}
	}

	int res = 0;
	for (int i = 0; i < n; i++) {
		//if strictly increasing or decreasing not allowed
		// we have to check if(dp1[i] > 1 and dp2[i] > 1)
		res = max(res, dp1[i] + dp2[i] - 1);
	}

	return res;
}