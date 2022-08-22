Longest Palindromic Subsequences

// Find LCS between str and reverse(str)

class Solution {
public:
	/***Recursive + memoization ****/
	int solve(int i, int j, string s, string t, vector<vector<int>> &dp) {
		if (i < 0 or j < 0)
			return 0;
		if (dp[i][j] != -1)
			return dp[i][j];

		if (s[i] == t[j])
			return  dp[i][j] = 1 + solve(i - 1, j - 1, s, t, dp);

		return dp[i][j] = max(solve(i - 1, j, s, t, dp), solve(i, j - 1, s, t, dp));
	}

	int lcs(string s, string t) {
		int n = s.length();
		// vector<vector<int>> dp(n,vector<int>(n,-1));
		// return solve(n-1,n-1,s,t,dp);

		/***Tabulation****/
		vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
		//To handle the base case of i < 0, j < 0  Add extra row, col and think in terms of length (Shifted index)
		//  Already initialized the vector no need to initialize again
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (s[i - 1] == t[j - 1]) {
					dp[i][j] = 1 + dp[i - 1][j - 1];
				}
				else
					dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
			}
		}
		int maxl = dp[n][n];

		/****Space optimize****/
		vector<int> prev(n + 1, 0), curr(n + 1, 0);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (s[i - 1] == t[j - 1]) {
					curr[j] = 1 + prev[j - 1];
				}
				else
					curr[j] = max(curr[j - 1], prev[j]);
			}
			prev = curr;
		}

		return maxl;

	}


	int longestPalindromeSubseq(string s) {
		string t = s;
		reverse(s.begin(), s.end());
		return lcs(s, t);
	}
};