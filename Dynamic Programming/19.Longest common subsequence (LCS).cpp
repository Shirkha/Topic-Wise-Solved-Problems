Longest common subsequence (LCS)  (S1, S2)
-- > Express in terms of ind1, ind2
== > if both the char match take f(ind1 - 1 , ind2 - 1)
	else
		take  max(f(ind1, ind2 - 1) ,  f(ind1 - 1, ind2)

		          ---> Recursive  TC = 2 ^ M * 2 ^ N     SC = O(M + N)

		class Solution {
public:
		/***Recursive + memoization****/
		// TC = O(M*N)  SC = O(M*N) + O(M+N)
		int solve(int i, int j, string s1, string s2, vector<vector<int>> &dp) {
			if (i < 0 or j < 0)
				return 0;

			if (dp[i][j] != -1)
				return dp[i][j];

			if (s1[i] == s2[j])
				return dp[i][j] = 1 + solve(i - 1, j - 1, s1, s2, dp);

			return dp[i][j] = max(solve(i, j - 1, s1, s2, dp), solve(i - 1, j, s1, s2, dp));

		}

		int longestCommonSubsequence(string s1, string s2) {
			int n = s1.size(), m = s2.size();
			vector<vector<int>> dp(n, vector<int>(m, -1));
			return solve(n - 1, m - 1, s1, s2, dp);

			/***Tabulation*****/
			// TC = O(M*N)   SC = O(M*N)
			// To handle the case of i < 0 , j < 0
			// Shift the elements i.e nothing but think in terms of length (Aditya Verma)

			vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
			// for (int i = 0; i <= n; i++)
			// 	dp[i][0] = 0;
			// for (int j = 0; j <= m; j++)
			// 	dp[0][j] = 0;

			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= m; j++) {
					if (s1[i - 1] == s2[j - 1])
						dp[i][j] = 1 + dp[i - 1][j - 1];
					else
						dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
				}
			return dp[n][m];


			/***Space optimization *****/
			//TC = O(M*N)    SC = O(M)
			vector<int> prev(m + 1, 0), curr(m + 1, 0);

			for (int j = 0; j <= m; j++)
				prev[j] = 0;

			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= m; j++) {
					if (s1[i - 1] == s2[j - 1])
						curr[j] = 1 + prev[j - 1];
					else
						curr[j] = max(curr[j - 1], prev[j]);
				}
				prev = curr;
			}
			return prev[m];
		}
	};

---> Space optimization using 1 row is not possible bec. there is dependency on both prev[j - 1] and curr[j - 1] at the same time