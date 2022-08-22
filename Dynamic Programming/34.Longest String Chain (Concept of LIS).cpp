Longest String Chain (Concept of LIS)

class Solution {
public:
	static bool comp(string &x, string &y) {
		return x.length() < y.length();
	}
	bool isPred(string &prev, string &curr) {
		int m = prev.size(), n = curr.size();
		if (m + 1 != n)
			return false;

		int i = 0, j = 0;
		while (i < m and j < n) {
			if (prev[i] == curr[j]) {
				i++;
				j++;
			}
			else
				j++;
		}
		return (i == m);
	}
	int longestStrChain(vector<string>& words) {
		sort(words.begin(), words.end(), comp);
		int n = words.size(), maxlen = 1;
		vector<int> dp(n, 1); // length of LSC till ith index
		for (int i = 1; i < n; i++) {
			for (int prev = 0; prev < i; prev++) {
				if (isPred(words[prev], words[i]) and 1 + dp[prev] > dp[i])
					dp[i] = 1 + dp[prev];
			}
			maxlen = max(maxlen, dp[i]);
		}
		return maxlen;
	}
};
