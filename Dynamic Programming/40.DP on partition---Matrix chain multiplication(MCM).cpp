DP on partition-- -Matrix chain multiplication(MCM)

// Recursive + memoization
// TC = O(n*n) * O(n)--->loop for k = O(n^3)
//SC = O(n^2) + O(n)
int solve(int i, int j, int arr[], vector<vector<int>> &dp) {
	if (i == j) // single matrix (0 operation )
		return 0;

	if (dp[i][j] != -1)
		return dp[i][j];
	int minm = 1e9;
	for (int k = i; k < j; k++) {
		int operation = arr[i - 1] * arr[k] * arr[j] + solve(i, k, arr, dp) + solve(k + 1, j, arr, dp);
		minm = min(minm, operation);
	}
	return dp[i][j] = minm;
}
int matrixMultiplication(int n, int arr[])
{
	// code here
	vector<vector<int>> dp(n, vector<int>(n, -1));
	return solve(1, n - 1, arr, dp);


	// Tabulation
	// TC = O(n^3)  SC = O(n^2)
	vector<vector<int>> dp(n, vector<int>(n, 0));

	for (int i = n - 1; i >= 1; i--) {
		for (int j = i + 1; j < n; j++) {
			int minm = 1e9;
			for (int k = i; k < j; k++) {
				int operation = arr[i - 1] * arr[k] * arr[j] + dp[i][k] + dp[k + 1][j];
				minm = min(minm, operation);
				dp[i][j] = minm;
			}
		}
	}
	return dp[1][n - 1];
}
