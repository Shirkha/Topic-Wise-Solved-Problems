Shortest Common Supersequence
-- > Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences. If there are multiple valid strings, return any of them.

// Concept of LCS and print LCS
// We can take the LCS part only once and take rest of the chars from the strings

        lic:
string shortestCommonSupersequence(string s1, string s2) {
	int n = s1.length(), m = s2.length();
	vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			if (s1[i - 1] == s2[j - 1])
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}

	int length = n + m - dp[n][m];
	cout << length;
	string s(length, '$');
	int k = length - 1;
	int i = n, j = m;

	while (i > 0 and  j > 0) {
		if (s1[i - 1] == s2[j - 1]) {
			s[k--] = s1[i - 1];
			i--;
			j--;
		}
		else if (dp[i - 1][j] > dp[i][j - 1]) {
			s[k--] = s1[i - 1];
			i--;
		}
		else {
			s[k--] = s2[j - 1];
			j--;
		}
	}
	while (i > 0) {
		s[k--] = s1[i - 1];
		i--;
	}
	while (j > 0) {
		s[k--] = s2[j - 1];
		j--;
	}

	return s;
}
