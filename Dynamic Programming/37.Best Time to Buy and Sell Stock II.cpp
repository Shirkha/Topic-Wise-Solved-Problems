Best Time to Buy and Sell Stock II (Multiple transactions allowed)
On each day, you may decide to buy and / or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

Solution: -
// 1---->can buy . Initially we can buy so pass 1
// 0----> can't buy
//Since profit is difference between buy and sell
// Buy means negative
// Sell means positve


// Recursive + Memoization TC = O(n*2)  SC = O(n*2) + O(n)
int find(int ind, int buy, vector<int> &prices, vector<vector<int>> &dp) {
	if (ind == prices.size())
		return 0;
	if (dp[ind][buy] != -1)
		return dp[ind][buy];

	int profit = 0;
	if (buy) { // We can buy
		// int take = -prices[ind] + find(ind+1,0,prices,dp); // buy means negative
		// int notTake = find(ind+1,1,prices,dp);

		profit = max(-prices[ind] + find(ind + 1, 0, prices, dp), find(ind + 1, 1, prices, dp));
	}
	else {
		// else we can sell
		// int take = prices[ind] + find(ind+1,1,prices,dp);   // sell means positve
		// int notTake = find(ind+1,0,prices,dp);

		profit = max(prices[ind] + find(ind + 1, 1, prices, dp), find(ind + 1, 0, prices, dp));
	}

	return dp[ind][buy] = profit;
}
int maxProfit(vector<int>& prices) {
	vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
	return find(0, 1, prices, dp);
}

// Tabulation
// TC = O(n*2)   SC = O(n*2)
int n = prices.size();
vector<vector<int>> dp(n + 1, vector<int>(2, 0));
dp[n][0] = dp[n][1] = 0;

for (int ind = n - 1; ind >= 0; ind--) {
	for (int buy = 0; buy <= 1; buy++) {
		int profit;
		if (buy)
			profit = max(-prices[ind] + dp[ind + 1][0], dp[ind + 1][1]);
		else
			profit = max(prices[ind] + dp[ind + 1][1], dp[ind + 1][0]);

		dp[ind][buy] = profit;
	}
}
return dp[0][1];

// Space optimization
// SC = O(1);
vector<int> next(2, 0), curr(2, 0);

for (int ind = n - 1; ind >= 0; ind--) {
	for (int buy = 0; buy <= 1; buy++) {
		int profit;
		if (buy)
			profit = max(-prices[ind] + next[0], next[1]);
		else
			profit = max(prices[ind] + next[1], next[0]);

		curr[buy] = profit;
	}
	next = curr;
}
return next[1] ;  // or curr[1];

// Space Optimization using 4 variables instead of vectors
//  SC = O(1)
int nextBuy, nextSell, currBuy, currSell;  //0-->buy    1-->sell
nextBuy = nextSell = 0;
for (int ind = n - 1; ind >= 0; ind--) {
	currBuy = max(-prices[ind] + nextSell, nextBuy);
	currSell = max(prices[ind] + nextBuy, nextSell);

	nextBuy = currBuy;
	nextSell = currSell;
}
return currBuy; // or nextBuy


// Miscellaneous solution
// Try to buy it in local maxima and sell it in local maxima--> between two consecutive stocks

int maxProfit(vector<int>& prices) {
	int profit = 0;
	for (int i = 1; i < prices.size(); i++) {
		int diff = prices[i] - prices[i - 1];
		if (diff > 0)
			profit += diff;
	}
	return profit;
}