Longest common substring



class Solution {
public:

	int longestCommonSubstr (string s1, string s2, int n, int m)
	{
		// your code here
		/***Tabulation ****/
		vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

		// Initialization --> Already initialized with 0
		int maxl = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (s1[i - 1] == s2[j - 1]) {
					dp[i][j] = 1 + dp[i - 1][j - 1];
					maxl = max(maxl, dp[i][j]);
				}
				else
					dp[i][j] = 0;
			}
		}
		return maxl;

		/***Space optimize****/

		vector<int> prev(m + 1, 0), curr(m + 1, 0);

		// Initialization --> Already initialized with 0
		int maxl = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (s1[i - 1] == s2[j - 1]) {
					curr[j] = 1 + prev[j - 1];
					maxl = max(maxl, curr[j]);
				}
				else
					curr[j] = 0;
			}
			prev = curr;
		}
		return maxl;

	}
};

//{ Driver Code Starts.

int main()
{
	int t; cin >> t;
	while (t--)
	{
		int n, m; cin >> n >> m;
		string s1, s2;
		cin >> s1 >> s2;
		Solution ob;

		cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
	}
}
