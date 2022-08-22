Print longest common subsequence
-- > Use the table dp[n][m] filled in previous problem

// Backtrack from (m,n) to get one of the LCS
// We can not get multiple LCS by this table b

// TC = O(N*M)  SC = O(N*M) + O(N+M)--> for backtracking/tracing the LCS
void longestCommonSubsequence(string s1, string s2) {
	int n = s1.size(), m = s2.size();
	/***Tabulation*****/
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
	for (int i = 0; i <= n; i++)
		dp[i][0] = 0;
	for (int j = 0; j <= m; j++)
		dp[0][j] = 0;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			if (s1[i - 1] == s2[j - 1])
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
		}


	int length = dp[n][m];
	int i = n, j = m;
	// string s = "";
	// for(int i=0; i<length; i++)
	//     s += '$';

	// vector<char> s(length);

	string s(length, '$');

	int k = length - 1;

	while (i > 0 and j > 0) {
		if (s1[i - 1] == s2[j - 1]) {
			s[k--] = s1[i - 1];
			i--;
			j--;
		}
		else if (dp[i - 1][j] > dp[i][j - 1]) {
			i--;
		}
		else
			j--;
	}
	// cout<<s;
	for (char c : s)
		cout << c;

}