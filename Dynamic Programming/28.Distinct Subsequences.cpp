Distinct Subsequences
-- > Given two strings s and t, return the number of distinct subsequences of s which equals t.



class Solution {
public:
	int solve(int i, int j, string s, string t, vector<vector<int>> &dp) {
		if (j < 0)
			return 1;
		if (i < 0 or i < j)
			return 0;
		if (dp[i][j] != -1)
			return dp[i][j];

		if (s[i] == t[j]) {
			return dp[i][j] = solve(i - 1, j - 1, s, t, dp) + solve(i - 1, j, s, t, dp); // Take matching char or do not take
			// Find that char for remaining part of the first string
		}

		return solve(i - 1, j, s, t, dp);

	}

	int numDistinct(string s, string t) {
		int n = s.size(), m = t.size();
		// vector<vector<int>> dp(n,vector<int>(m,-1));
		// return solve(n-1,m-1,s,t,dp);
		vector<vector<unsigned long long>> dp(n + 1, vector<unsigned long long>(m + 1, 0)); // i--> n   j--> m
		for (int i = 0; i <= n; i++)
			dp[i][0] = 1;

		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++) {
				if (s[i - 1] == t[j - 1])
					dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
				else
					dp[i][j] = dp[i - 1][j];
			}
		return dp[n][m];

		/***Space optimize***/
		vector<unsigned int> prev(m + 1, 0);
		prev[0] = 1;

		for (int i = 1; i <= n; i++) {
			for (int j = m; j > 0; j--) {
				if (s[i - 1] == t[j - 1])
					prev[j] = prev[j - 1] + prev[j];
			}
		}
		return prev[m];
	}
};


