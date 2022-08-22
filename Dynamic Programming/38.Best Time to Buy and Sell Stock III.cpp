Best Time to Buy and Sell Stock III (At most 2 transactions)

//If we sell a stock then 1 transaction completes
// Recursive + Memoization
// TC = O(n*2*3)    SC = O(n*2*3) + O(n)
int find(int ind, int buy, vector<int> &prices, int cap, vector<vector<vector<int>>> &dp) { // cap---> no of transactions
	if (ind == prices.size() or cap == 0)
		return 0;

	if (dp[ind][buy][cap] != -1)
		return dp[ind][buy][cap];
	int profit = 0;
	if (buy) {
		profit = max(-prices[ind] + find(ind + 1, 0, prices, cap, dp), find(ind + 1, 1, prices, cap, dp));
	}
	else {
		profit = max(prices[ind] + find(ind + 1, 1, prices, cap - 1, dp), find(ind + 1, 0, prices, cap, dp)); // if we sell a stock then one transaction is complete  (B,S)
	}
	return dp[ind][buy][cap] = profit;

}
int maxProfit(vector<int>& prices) {
	int n = prices.size();
	// dp[n][buy+1][cap+1]   buy=1   cap=2
	vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
	return find(0, 1, prices, 2, dp);
}


// Tabulation   TC = O(n*2*3) = SC
vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
// base case ---> dp[i][j][0] = 0        dp[n][i][j] = 0

for (int ind = n - 1; ind >= 0; ind--) { // recursive (0-->n-1)
	for (int buy = 0; buy <= 1; buy++) { // recursive (1-->0)
		for (int cap = 1; cap <= 2; cap++) { // cap = 0(base case)  recursive (2-->0)
			int profit;
			if (buy)
				profit = max(-prices[ind] + dp[ind + 1][0][cap], dp[ind + 1][1][cap]);
			else
				profit = max(prices[ind] + dp[ind + 1][1][cap - 1], dp[ind + 1][0][cap]);
			dp[ind][buy][cap] = profit;
		}

	}
}
return dp[0][1][2];

// Space Optimize  SC = O(2*3)
vector<vector<int>> next(2, vector<int>(3, 0)), curr(2, vector<int>(3, 0));
for (int ind = n - 1; ind >= 0; ind--) {
	for (int buy = 0; buy <= 1; buy++) {
		for (int cap = 1; cap <= 2; cap++) {
			int profit;
			if (buy)
				profit = max(-prices[ind] + next[0][cap], next[1][cap]);
			else
				profit = max(prices[ind] + next[1][cap - 1], next[0][cap]);
			curr[buy][cap] = profit;
		}
	}
	next = curr;
}
return next[1][2];


