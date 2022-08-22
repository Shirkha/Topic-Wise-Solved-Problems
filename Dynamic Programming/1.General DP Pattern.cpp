General DP Pattern

Q. Fibonacci number

1. Recursive + Memoization(Top down)-- > (n->base case)
TC-> O(n)     SC->O(n) + O(n)--->Recursive stack space
#####
int fibonacci(int n) {
	vector<int> dp(n + 1, -1);
	return fib(n, dp);
}

int fib(int n, vector<int> &dp) {
	if (n <= 1)
		return n;
	if (dp[n] != -1)
		return dp[n];

	return dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
}

2. Tabulation (Bottom up)-- > (base case->n)
	TC-> O(n)   SC-> O(n)
####
	int fibonacci(int n) {
	if (n == 0)
		return 0;
	vector<int> dp(n + 1);
	dp[0] = 0;
	dp[1] = 1;
	//cout<<dp[0]<<" "<<dp[1]<<" ";

	for (int i = 2; i <= n ; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
		// cout << dp[i] << " ";
	}
	return dp[n];
}

3. Space optimization
TC-> O(n)   SC-> O(1)
####
int fibonacci(int n) {
	if (n == 0)
		return 0;
	int prev2 = 0;
	int prev1 = 1;

	for (int i = 2; i <= n; i++) {
		int curr = prev1 + prev2;
		prev2 = prev1;
		prev1 = curr;
	}
	return prev1;
}
