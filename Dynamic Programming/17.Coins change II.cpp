Coins change II
-- > Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.

class Solution {
public:

	/***Recursive + memoization ****/
	int solve(int ind, int amount, vector<int> &coins, vector<vector<int>> &dp) {
		if (amount == 0)
			return 1;   // 1 way we don't need any coins
		if (ind == 0) {
			return amount % coins[0] == 0; // We are required to return only the no of ways
			// not the no of coins
		}

		if (dp[ind][amount] != -1)
			return dp[ind][amount];

		int notTake = solve(ind - 1, amount, coins, dp);
		int take = 0;
		if (coins[ind] <= amount)
			take = solve(ind, amount - coins[ind], coins, dp);

		return dp[ind][amount] = notTake + take;

	}


	int change(int amount, vector<int>& coins) {
		int n = coins.size();
		// vector<vector<int>> dp(n,vector<int>(amount+1,-1));
		// return solve(n-1,amount,coins,dp);

		/***Tabulation*****/
		vector<vector<int>> dp(n, vector<int>(amount + 1));
		for (int i = 0; i < n; i++)
			dp[i][0] = 1;
		for (int j = 0; j <= amount; j++)
			dp[0][j] = (j % coins[0] == 0);

		for (int i = 1; i < n; i++)
			for (int j = 1; j <= amount; j++) {
				int notTake = dp[i - 1][j];
				int take = 0;
				if (coins[i] <= j)
					take = dp[i][j - coins[i]];
				dp[i][j] = take + notTake;
			}
		return dp[n - 1][amount];

		/***Space optimization***/
		vector<int>prev(amount + 1), curr(amount + 1);

		for (int j = 0; j <= amount; j++)
			prev[j] = (j % coins[0] == 0);

		for (int i = 1; i < n; i++) {
			for (int j = 1; j <= amount; j++) {
				int notTake = prev[j];
				int take = 0;
				if (coins[i] <= j)
					take = curr[j - coins[i]];
				curr[j] = take + notTake;
			}
			prev = curr;
		}
		return prev[amount];

		/****Using only single row****/

		vector<int>prev(amount + 1);

		for (int j = 0; j <= amount; j++)
			prev[j] = (j % coins[0] == 0);

		for (int i = 1; i < n; i++) {
			for (int j = 1; j <= amount; j++) {
				int notTake = prev[j];
				int take = 0;
				if (coins[i] <= j)
					take = prev[j - coins[i]];
				prev[j] = take + notTake;
			}
		}
		return prev[amount];
	}
};