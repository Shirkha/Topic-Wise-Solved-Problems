Minimum Insertion Steps to Make a String Palindrome

// We can keep intact the palindrome already present in the string. We only required the copy of extra chars present in the string to make it palindrome

// Concept of lcs and lps

int minInsertions(string s) {
	int lps = find_lps(s);
	return s.length() - lps;
}


int find_lps(string s) {
	string t = s;
	reverse(s.begin(), s.end());
	int n = s.length();

	/***Recursive + memoization****/
	vector<vector<int>> dp(n, vector<int>(n, -1));
	return lcs(n - 1, n - 1, s, t, dp);

	/***Tabulation****/
	// Think in terms of length (shifted index)
	vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			if (s[i - 1] == t[j - 1])
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	return dp[n][n];

	/***Space optimize****/

	vector<int> prev(n + 1, 0), curr(n + 1, 0);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (s[i - 1] == t[j - 1])
				curr[j] = 1 + prev[j - 1];
			else
				curr[j] = max(prev[j], curr[j - 1]);
		}
		prev = curr;
	}
	return prev[n];

}


int lcs(int i, int j, string s, string t, vector<vector<int>> &dp) {
	if (i < 0 or j < 0)
		return 0;

	if (dp[i][j] != -1)
		return dp[i][j];

	if (s[i] == t[j])
		return dp[i][j] = 1 + lcs(i - 1, j - 1, s, t, dp);

	return dp[i][j] = max(lcs(i - 1, j, s, t, dp), lcs(i, j - 1, s, t, dp));
}




