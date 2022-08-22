Longest palindromic substring

// Same as count palindrome string


string longestPalindrome(string s) {
	int n = s.length();
	vector<vector<bool>> dp(n, vector<bool>(n, false));

	int start = 0;
	int maxl = 0;

	for (int g = 0; g < n; g++) {
		for (int i = 0, j = g; j < n; i++, j++) {        // (0,gap) --->(k,n-1)
			if (g == 0)
				dp[i][j] = true;
			else if (g == 1)
				dp[i][j] = (s[i] == s[j]);
			else
				dp[i][j] = (s[i] == s[j] and dp[i + 1][j - 1]);

			if (dp[i][j]) {
				start = i;
				maxl = g + 1;
			}

		}
	}
	string ans = s.substr(start, maxl);
	return ans;
}