Q. Climbing stairs
-- > Either can climb 1 step or 2 step for given n
####
Count all possible ways == >> Recursion
                           ***
                           Instead of climbing think of jumping
                           == >> f(n) = f(n - 1) + f(n - 2) -----> Similar to Fibonacci no.

	                                        -- > n = 0 ---- > 0 way
	                                                -- > n = 1 ---- > 1 way
	                                                        -- > n = 2 ---- > 2 ways  (1 + 1) or (2)

	                                                                1. Recursive + Memoization (TC->O(n) SC->O(n) + O(n))
	                                                                ***
	int climbing(int n) {
	vector<int> dp(n + 1, -1);
	return solve(n, dp);
}

int solve(int n, vector<int> &dp) {
	if (n <= 2)
		return n;
	if (dp[n] != -1)
		return dp[n];

	return dp[n] = solve(n - 1, dp) + solve(n - 2, dp);
}

2. Tabulation (TC->O(n) SC->O(n))
***
int climbing(int n) {
	if (n <= 2)
		return n;
	vector<int> dp(n + 1);
	//dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= n; i++)
		dp[i] = dp[i - 1] + dp[i - 2];
	return dp[n]
}