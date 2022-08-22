Rod Cutting (Unbounded knapsack)
-- > Instead of cutting the road try to collect the small pieces of rod



    class Solution {
    public:
        /****Recursive + memoizaion***/ TC = O(N*N)  SC = 0(N*N) + O(N)
        int solve(int ind, int n, int price[], vector<vector<int>> &dp) {
            if (n == 0)
                return 0;
            if (ind == 0) {
                return n * price[0];
            }

            if (dp[ind][n] != -1)
                return dp[ind][n];

            int notTake = solve(ind - 1, n, price, dp);
            int take = INT_MIN;
            int length = ind + 1;
            if (length <= n)
                take = price[ind] + solve(ind, n - length, price, dp);
            return dp[ind][n] = max(take, notTake);

        }

        int cutRod(int price[], int n) {
            vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
            return solve(n - 1, n, price, dp);

            /***Tabulation****/  // TC = O(N*N)  SC = O(N*N)
            vector<vector<int>> dp(n, vector<int>(n + 1));  //dp[ind][length]
            for (int j = 0; j <= n; j++)
                dp[0][j] = j * price[0];

            for (int i = 1; i < n; i++)
                for (int j = 0; j <= n; j++) {
                    int notTake = dp[i - 1][j];
                    int take = INT_MIN;
                    int length = i + 1;
                    if (length <= j)
                        take = price[i] + dp[i][j - length];
                    dp[i][j] = max(take, notTake);
                }
            return dp[n - 1][n];

            /***Space optimize***/   SC = O(N)
                                          vector<int> prev(n + 1), curr(n + 1);
            for (int j = 0; j <= n; j++)
                prev[j] = j * price[0];

            for (int i = 1; i < n; i++) {
                for (int j = 0; j <= n; j++) {
                    int notTake = prev[j];
                    int take = INT_MIN;
                    int length = i + 1;
                    if (length <= j)
                        take = price[i] + curr[j - length];
                    curr[j] = max(take, notTake);
                }
                prev = curr;
            }
            return prev[n];

            /****Using 1 row****/
            vector<int> prev(n + 1);
            for (int j = 0; j <= n; j++)
                prev[j] = j * price[0];

            for (int i = 1; i < n; i++) {
                for (int j = 0; j <= n; j++) {
                    int notTake = prev[j];
                    int take = INT_MIN;
                    int length = i + 1;
                    if (length <= j)
                        take = price[i] + prev[j - length];
                    prev[j] = max(take, notTake);
                }
            }
            return prev[n];
        }
    };

