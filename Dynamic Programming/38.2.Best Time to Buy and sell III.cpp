Best Time to Buy and sell III

// Instead of taking 3 params (ind,buy,cap)  we can take (ind,transaction no)
// We can use transaction number    B S B S
//                                  0 1 2 3   even--> buy  odd-->sell

//R + M  TC = O(n*4)  SC = O(n*4) + O(n)
int find(int ind, int tran, vector<int> &prices, vector<vector<int>> &dp) {
	if (ind == prices.size() or tran == 4)
		return 0;
	if (dp[ind][tran] != -1)
		return dp[ind][tran];

	int profit = 0;
	if (tran % 2 == 0) {
		profit = max(-prices[ind] + find(ind + 1, tran + 1, prices, dp), find(ind + 1, tran, prices, dp));
	}
	else {
		profit = max(prices[ind] + find(ind + 1, tran + 1, prices, dp), find(ind + 1, tran, prices, dp));
	}
	return dp[ind][tran] = profit;
}
int maxProfit(vector<int>& prices) {
	int n = prices.size();
	vector<vector<int>> dp(n, vector<int>(4, -1));
	return find(0, 0, prices, dp);

	//Tabulation   TC = (n*4)  SC = O(n*5)
	vector<vector<int>> dp(n + 1, vector<int>(5, 0));

	for (int ind = n - 1; ind >= 0; ind--) {
		for (int tran = 3; tran >= 0; tran--) {
			int profit = 0;
			if (tran % 2 == 0)
				profit = max(-prices[ind] + dp[ind + 1][tran + 1], dp[ind + 1][tran]);
			else
				profit = max(prices[ind] + dp[ind + 1][tran + 1], dp[ind + 1][tran]);
			dp[ind][tran] = profit;
		}
	}
	return dp[0][0];

	// Space optimize  TC = O(n*4)  SC = O(5)

	vector<int> next(5, 0), curr(5, 0);

	for (int ind = n - 1; ind >= 0; ind--) {
		for (int tran = 3; tran >= 0; tran--) {
			int profit = 0;
			if (tran % 2 == 0)
				profit = max(-prices[ind] + next[tran + 1], next[tran]);
			else
				profit = max(prices[ind] + next[tran + 1], next[tran]);
			curr[tran] = profit;
		}
		next = curr;
	}
	return next[0];
}