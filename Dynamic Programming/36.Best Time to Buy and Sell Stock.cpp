Best Time to Buy and Sell Stock (Single transaction)
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

// Find the minm till curr day and find the max profit

int maxProfit(vector<int>& prices) {
	int maxProfit = 0;
	int minm = prices[0];
	for (int i = 1; i < prices.size(); i++) {
		minm = min(minm, prices[i]);
		int profit = prices[i] - minm;
		maxProfit = max(maxProfit, profit);
	}
	return maxProfit;
}