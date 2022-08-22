Best Time to Buy and Sell Stock IV (At most K transactions)

// B S B S .......B S  ---> Total 2k
// 0 1 2 3.....2K-2 2K-1
//R+M TC = O(n*2k) SC = O(n*2k) + O(n)
int find(int ind, int tran, int k, vector<int> &prices, vector<vector<int>> &dp) {
	if (ind == prices.size() or tran == 2 * k)
		return 0;

	if (dp[ind][tran] != -1)
		return dp[ind][tran];

	int profit;
	if (tran % 2 == 0)
		profit = max(-prices[ind] + find(ind + 1, tran + 1, k, prices, dp), find(ind + 1, tran, k, prices, dp));
	else
		profit = max(prices[ind] + find(ind + 1, tran + 1, k, prices, dp), find(ind + 1, tran, k, prices, dp));

	return dp[ind][tran] = profit;
}

int maxProfit(int k, vector<int>& prices) {
	int n = prices.size();
	vector<vector<int>> dp(n, vector<int>(2 * k, -1));
	return find(0, 0, k, prices, dp);

	// Tabulation TC = O(n*2k) = SC
	vector<vector<int>> dp(n + 1, vector<int>(2 * k + 1, 0));
	//dp[n][i] = dp[i][2k] = 0
	for (int ind = n - 1; ind >= 0; ind--) {
		for (int tran = 2 * k - 1; tran >= 0; tran--) {
			int profit;
			if (tran % 2 == 0)
				profit = max(-prices[ind] + dp[ind + 1][tran + 1], dp[ind + 1][tran]);
			else
				profit = max(prices[ind] + dp[ind + 1][tran + 1], dp[ind + 1][tran]);
			dp[ind][tran] = profit;
		}
	}
	return dp[0][0];

	// Space optimize SC = O(2*k)
	vector<int> next(2 * k + 1, 0);

	for (int ind = n - 1; ind >= 0; ind--) {
		for (int tran = 0; tran <= 2 * k - 1; tran++) {
			int profit;
			if (tran % 2 == 0)
				profit = max(-prices[ind] + next[tran + 1], next[tran]);
			else
				profit = max(prices[ind] + next[tran + 1], next[tran]);
			next[tran] = profit;
		}
		// next = curr;
	}
	return next[0];
}