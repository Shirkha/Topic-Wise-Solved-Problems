Unbounded knapsack

int solve(int ind, int w, int wt[], int val[], vector<vector<int>> &dp) {
	if (w == 0)
		return 0;
	if (ind == 0)
		return (w / wt[0]) * val[0];
	if (dp[ind][w] != -1)
		return dp[ind][w];

	int notTake = solve(ind - 1, w, wt, val, dp);
	int take = INT_MIN;
	if (wt[ind] <= w)
		take = val[ind] + solve(ind, w - wt[ind], wt, val, dp);

	return dp[ind][w] = max(take, notTake);

}
int knapSack(int n, int w, int val[], int wt[])
{
	/***Recursive + memoization***/
	vector<vector<int>> dp(n, vector<int> (w + 1, -1));
	return solve(n - 1, w, wt, val, dp);

	/****Tabualtion*****/
	vector<vector<int>> dp(n, vector<int>(w + 1, 0));
	for (int i = 0; i <= w; i++)
		dp[0][i] = (i / wt[0]) * val[0];

	for (int i = 1; i < n; i++)
		for (int j = 1; j <= w; j++) {
			int notTake = dp[i - 1][j];
			int take = INT_MIN;
			if (wt[i] <= j)
				take = val[i] + dp[i][j - wt[i]];

			dp[i][j] = max(take, notTake);
		}
	return  dp[n - 1][w];

	/****Space optimize****/
	vector<int> prev(w + 1, 0), curr(w + 1, 0);
	for (int i = 0; i <= w; i++)
		prev[i] = (i / wt[0]) * val[0];

	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= w; j++) {
			int notTake = prev[j];
			int take = INT_MIN;
			if (wt[i] <= j)
				take = val[i] + curr[j - wt[i]];

			curr[j] = max(take, notTake);
		}
		prev = curr;
	}

	return  prev[w];

	/****Using only 1 row***/

	/****Space optimize****/
	vector<int> prev(w + 1, 0);
	for (int i = 0; i <= w; i++)
		prev[i] = (i / wt[0]) * val[0];

	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= w; j++) {
			int notTake = prev[j];
			int take = INT_MIN;
			if (wt[i] <= j)
				take = val[i] + prev[j - wt[i]];

			prev[j] = max(take, notTake);
		}
	}

	return  prev[w];
}