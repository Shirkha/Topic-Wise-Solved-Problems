Coin Change I
Return the minm number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1
        -- > We have to make the amount any way if can't do return -1
        ---> Infinite supply of coins (Unbounded knapsack)
        --> Unlike knapsack where we can left some weight as unused here we can't left the amount

class Solution {
public:
	// Recursive--> TC >> O(2^n) (Same ind can be used again and again)   SC = O(amount)
	/***Recursive + Memoization****/
	// TC = O(n*amount)  SC = O(n*amount) + O(amount)
	int solve(int ind, vector<int> &arr, int sum, vector<vector<int>> &dp) {
			if (sum == 0)
				return 0;
			if (ind == 0) {
				if (sum % arr[0] == 0) // can pick
					return sum / arr[0];
				return 1e9;          // can't pick
			}

			if (dp[ind][sum] != -1)
				return dp[ind][sum];

			int notTake = solve(ind - 1, arr, sum, dp);
			int take = 1e9;
			if (arr[ind] <= sum)
				take = 1 + solve(ind, arr, sum - arr[ind], dp);
			return dp[ind][sum] = min(take, notTake);
		}

		int coinChange(vector<int>& arr, int amount) {
			int n = arr.size();
			vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
			int ans = solve(n - 1, arr, amount, dp);
			/***Tabulation****/
			//TC = O(N*amount) SC = O(N*amount)
			vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
			for (int sum = 0; sum <= amount; sum++) {
				if (sum % arr[0] == 0)
					dp[0][sum] = sum / arr[0];
				else
					dp[0][sum] = 1e9;
			}

			for (int i = 1; i < n; i++)
				for (int sum = 1; sum <= amount; sum++) {
					int notTake = dp[i - 1][sum];
					int take = 1e9;
					if (arr[i] <= sum)
						take = 1 + dp[i][sum - arr[i]];
					dp[i][sum] = min(take, notTake);
				}

			if (dp[n - 1][amount] >=  1e9)
				return -1;
			return dp[n - 1][amount];

			/****Space optimization*****/
			// SC = O(amount)

			vector<int> prev(amount + 1, 0), curr(amount + 1, 0);
			for (int sum = 0; sum <= amount; sum++) {
				if (sum % arr[0] == 0)
					prev[sum] = sum / arr[0];
				else
					prev[sum] = 1e9;
			}

			for (int i = 1; i < n; i++) {
				for (int sum = 1; sum <= amount; sum++) {
					int notTake = prev[sum];
					int take = 1e9;
					if (arr[i] <= sum)
						take = 1 + curr[sum - arr[i]];
					curr[sum] = min(take, notTake);
				}
				prev = curr;
			}
			if (prev[amount] >= 1e9)
				return -1;
			return prev[amount];

			/****Space optimization using single row****/

			vector<int> prev(amount + 1);
			for (int sum = 0; sum <= amount; sum++) {
				if (sum % arr[0] == 0)
					prev[sum] = sum / arr[0];
				else
					prev[sum] = 1e9;
			}

			for (int i = 1; i < n; i++) {
				for (int sum = 0; sum <= amount; sum++) {
					int notTake = prev[sum];
					int take = 1e9;
					if (arr[i] <= sum)
						take = 1 + prev[sum - arr[i]];
					prev[sum] = min(take, notTake);
				}
			}
			if (prev[amount] >= 1e9)
				return -1;
			return prev[amount];


		}
	};
