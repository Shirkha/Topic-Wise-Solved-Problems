Wildcard Matching
'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
// How the idea of recursion----> for * we can either match substring of length 0, 1, 2, 3,....so on until we find a match



/**Recurive + memoization TC = O(m*n)     SC = O(m*n) + O(m+n) ****/
bool check(int i, int j, string &s, string &p, vector<vector<int>> &dp) {
	if (i < 0 and j < 0)
		return true;
	if (j < 0 and i >= 0)  // pattern exhausted but still some chars left to be match in string
		return false;

	//if string exhausted we will check whether the remaining chars in                                   // pattern is '*', otherwise not macth
	if (i < 0 and j >= 0) {
		for (int k = 0; k <= j; k++)
			if (p[k] != '*')
				return false;
		return true;
	}

	if (dp[i][j] != -1)
		return dp[i][j];

	if (s[i] == p[j]  or p[j] == '?')
		return dp[i][j] = check(i - 1, j - 1, s, p, dp);
	if (p[j] == '*')
		return dp[i][j] = check(i - 1, j, s, p, dp) or check(i, j - 1, s, p, dp);
	return dp[i][j] = false;
}
bool isMatch(string s, string p) {
	int m = s.length(), n = p.length();
	vector<vector<int>> dp(m, vector<int>(n, -1));
	return check(m - 1, n - 1, s, p, dp);
}