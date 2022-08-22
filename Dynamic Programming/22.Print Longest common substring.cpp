Print Longest common substring

class Solution {
public:

    int longestCommonSubstr (string s1, string s2, int n, int m)
    {
        // your code here
        /***Tabulation ****/
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Initialization --> Already initialized with 0
        // Print lcs
        int row = 0, col = 0;
        int maxl = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    if (dp[i][j] > maxl) {
                        maxl = dp[i][j];
                        row = i - 1;
                        col = j - 1;
                    }
                }
                else
                    dp[i][j] = 0;
            }
        }

        string str = s1.substr(row - maxl + 1, maxl);

        // vector<char> str(maxl);
        // string str(maxl, '$');
        // int k = maxl - 1;
        // while (dp[row][col] != 0) {
        //     str[k--] = s1[row - 1];
        //     row--;
        //     col--;
        // }

        // for (char c : str)
        //     cout << c;
        cout << str;
        return maxl;

        /***Space optimize****/
        vector<int> prev(m + 1, 0), curr(m + 1, 0);

        int maxl = 0;
        int end = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    curr[j] = 1 + prev[j - 1];
                    if (curr[j] > maxl) {
                        maxl = curr[j];
                        end = i - 1;
                        // For s1 --> end = i-1
                        //     s2 --> end = j-1
                    }
                }
                else
                    curr[j] = 0;
            }
            prev = curr;
        }

        string s = s1.substr(end - maxl + 1, maxl);
        // s = s2.substr(end - maxl + 1,maxl)
        cout << s;

        return maxl;




    }
};





