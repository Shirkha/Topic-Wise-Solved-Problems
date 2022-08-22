0 / 1 Knapsack

class Solution
{
public:
	/**Recursive + memoization ****/
	// TC = O(m*n)   SC = O(m*n) + O(n)
	int solve(int ind, int w, int wt[], int val[], vector<vector<int>> &dp) {
		if (w == 0)
			return 0;
		if (ind == 0) {
			if (wt[0] <= w)
				return val[0];
			return 0;
		}

		if (dp[ind][w] != -1)
			return dp[ind][w];

		int notTake = solve(ind - 1, w, wt, val, dp);
		int take = INT_MIN;
		if (wt[ind] <= w)
			take = val[ind] + solve(ind - 1, w - wt[ind], wt, val, dp);

		return dp[ind][w] = max(take, notTake);
	}


	int knapSack(int maxWt, int wt[], int val[], int n)
	{

		vector<vector<int>> dp(n, vector<int>(w + 1, -1));
		return solve(n - 1, w, wt, val, dp);

		/***Tabulation****/
		// TC = O(m*n)  SC = O(m*n)
		vector<vector<int>> dp(n, vector<int>(maxWt + 1, 0));
		// if capacity of knapsack >= wt[0]  ---> get the value val[0]
		for (int w = wt[0]; w <= maxWt; w++)
			dp[0][w] = val[0];

		for (int i = 1; i < n; i++)
			for (int j = 1; j <= maxWt; j++) {
				int notTake = dp[i - 1][j];
				int take = INT_MIN;
				if (wt[i] <= j)
					take = val[i] + dp[i - 1][j - wt[i]];
				dp[i][j] = max(notTake, take);
			}
		return dp[n - 1][maxWt];

		/***Space optimize***/
		vector<int> prev(maxWt + 1, 0), curr(maxWt + 1, 0);
		for (int w = wt[0]; w <= maxWt; w++)
			prev[w] = val[0];

		for (int i = 1; i < n; i++) {
			for (int j = 1; j <= maxWt; j++) {
				int notTake = prev[j];
				int take = INT_MIN;
				if (wt[i] <= j)
					take = val[i] + prev[j - wt[i]];
				curr[j] = max(take, notTake);
			}
			prev = curr;
		}
		return prev[maxWt];

		/****Space optimize using only single row****/
		vector<int> prev(maxWt + 1, 0);
		for (int w = wt[0]; w <= maxWt; w++)
			prev[w] = val[0];

		for (int i = 1; i < n; i++)
			for (int j = maxWt; j > 0; j--) {  // depends on previous state
				int notTake = prev[j];         // traverse left<------right
				int take = INT_MIN;
				if (wt[i] <= j)
					take = val[i] + prev[j - wt[i]];
				prev[j] = max(take, notTake);
			}
		return prev[maxWt];
	}
};

