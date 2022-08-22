Min Delete Operation for Two Strings to make them equal
Or Delete / Insert operation to convert string s1 to s2

// Keep the lcs intact delete or insert the extra chars in s1 and s2

int lcs(string s, string t, int n, int m) {
	vector<int> prev(m + 1, 0), curr(m + 1, 0);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (s[i - 1] == t[j - 1])
				curr[j] = 1 + prev[j - 1];
			else
				curr[j] = max(curr[j - 1], prev[j]);
		}
		prev = curr;
	}
	return prev[m];
}

int minDistance(string word1, string word2) {
	int n = word1.size(), m = word2.size();
	int lcs_length = lcs(word1, word2, n, m);
	return n + m - 2 * lcs_length;
}