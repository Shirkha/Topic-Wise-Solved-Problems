Edit distance
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2
        Operations -- > Insert, delete, replace



class Solution {
public:
	int solve(int i, int j, string s1, string s2, vector<vector<int>> &dp) {
		if (i < 0)
			return j + 1;   // j + 1 insertions
		if (j < 0)
			return i + 1;  // i + 1 deletion

		if (dp[i][j] != -1)
			return dp[i][j];

		if (s1[i] == s2[j])
			return dp[i][j] = solve(i - 1, j - 1, s1, s2, dp);

		int ins = 1 + solve(i, j - 1, s1, s2, dp);
		int dlt = 1 + solve(i - 1, j, s1, s2, dp);
		int rep = 1 + solve(i - 1, j - 1, s1, s2, dp);

		return dp[i][j] = min(ins, min(dlt, rep));

	}

	int minDistance(string s1, string s2) {
		int n = s1.size(), m = s2.size();
		// vector<vector<int>> dp(n,vector<int>(m,-1));
		// return solve(n-1,m-1,s1,s2,dp);
		/***Tabulation ***/
		vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
		for (int j = 0; j <= m; j++)
			dp[0][j] = j;
		for (int i = 0; i <= n; i++)
			dp[i][0] = i;

		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++) {
				if (s1[i - 1] == s2[j - 1])
					dp[i][j] = dp[i - 1][j - 1];
				else {
					int ins = 1 + dp[i][j - 1];
					int dlt = 1 + dp[i - 1][j];
					int rep = 1 + dp[i - 1][j - 1];

					dp[i][j] = min(ins, min(dlt, rep));
				}
			}
		return dp[n][m];

		/***Space optimize***/
		vector<int> prev(m + 1), curr(m + 1);
		for (int j = 0; j <= m; j++)
			prev[j] = j;

		for (int i = 1; i <= n; i++) {
			curr[0] = i;
			for (int j = 1; j <= m; j++) {
				if (s1[i - 1] == s2[j - 1])
					curr[j] = prev[j - 1];
				else {
					int ins = 1 + curr[j - 1];
					int dlt = 1 + prev[j];
					int rep = 1 + prev[j - 1];

					curr[j] = min(ins, min(dlt, rep));
				}
			}
			prev = curr;
		}
		return prev[m];
	}
};