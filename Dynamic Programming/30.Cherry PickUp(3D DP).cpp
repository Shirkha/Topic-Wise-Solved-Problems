// Cherry Pickup 3D DP

// See tabulation later
// Recursive + memoization
// TC = O(n*m*m)  SC = O(n*m*m) + O(n)
int solve(int i, int j1, int j2, int n, int m, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp) {
    if (j1 < 0 or j1 >= m or j2 < 0 or j2 >= m)
        return 0;

    if (i == n - 1) {
        if (j1 == j2)   // We can pick a cell only once
            return grid[i][j1];
        else
            return grid[i][j1] + grid[i][j2];
    }

    if (dp[i][j1][j2] != -1)
        return dp[i][j1][j2];

    int maxm = 0;
    for (int dj1 = -1; dj1 <= 1; dj1++)  // 3 * 3 states
        for (int dj2 = -1; dj2 <= 1; dj2++) {
            int val = 0;
            if (j1 == j2)
                val = grid[i][j1];
            else
                val = grid[i][j1] + grid[i][j2];

            val += solve(i + 1, j1 + dj1, j2 + dj2, n, m, grid, dp);
            maxm = max(val, maxm);
        }
    return dp[i][j1][j2] = maxm;

}

int cherryPickup(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    // (i,j1,j2) ---> 3 params changing (row is same for both the robot)
    // dp[n][m][m]
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
    return solve(0, 0, m - 1, n, m, grid, dp);


}