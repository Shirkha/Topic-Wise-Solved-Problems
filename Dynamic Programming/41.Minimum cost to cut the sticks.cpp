Minimum cost to cut the sticks
(Tricky see again)
Solution:
// The cut[] array should be sorted so that when we cut at certain postion left and right part don't depend on each other for the next cuts and we can solve individually for them
// eg- cut[]  = [1, 3, 4, 5]      n = 7 (length of stick)
// if we cut at 4---> left part of stick [0,1,2,3,4]
//               ---> rigth part  [4,5,6,7]
// left and right part are not depending on each other for the next cuts


// TC = O(c^3)
// SC = O(c^2)
int solve(int i, int j, vector<int> &cuts, vector<vector<int>> &dp) {
	if (i > j)
		return 0;

	if (dp[i][j] != -1)
		return dp[i][j];
	int minm = 1e9;
	for (int k = i; k <= j; k++) {
		int cost = cuts[j + 1] - cuts[i - 1] + solve(i, k - 1, cuts, dp) + solve(k + 1, j, cuts, dp);
		minm = min(minm, cost);
	}
	return dp[i][j] = minm;
}
int minCost(int n, vector<int>& cuts) {
	int c = cuts.size();
	cuts.insert(cuts.begin(), 0); // insert 0, n to get the length easily after cut
	cuts.push_back(n);
	sort(cuts.begin(), cuts.end());
	vector<vector<int>> dp(c + 2, vector<int>(c + 2, -1));
	return solve(1, c, cuts, dp); // [0,1,3,4,5,7]
	//    i     j
}

