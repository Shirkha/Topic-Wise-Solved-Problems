Subset Sum DP (Striver)
// 0-1 knapsack
-- > For count of Subsets Replace or with +



#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	/****Recursive******/ TC = O(2 ^ N)   SC = O(N)
	bool check(int ind, int sum, vector<int> &arr, vector<vector<int>> &dp) {
		if (sum == 0)
			return true;
		if (ind == 0)
			return arr[0] == sum;

		if (dp[ind][sum] != -1)
			return dp[ind][sum];

		bool notTake = check(ind - 1, sum, arr, dp);
		bool take = false;
		if (arr[ind] <= sum)
			take = check(ind - 1, sum - arr[ind], arr, dp);

		return dp[ind][sum] = notTake or take;
	}

	bool isSubsetSum(vector<int>arr, int sum) {
		// code here
		int n = arr.size();
		vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
		return check(n - 1, sum, arr, dp);

		/**Tabulation****/  TC = O(N * SUM) = SC
		                                      vector<vector<bool>> dp(n, vector<bool>(sum + 1, 0));

		for (int i = 0; i < n; i++)
			dp[i][0] = true;

		if (arr[0] <= sum)
			dp[0][arr[0]] = true;

		for (int i = 1; i < n; i++)
			for (int j = 1; j <= sum; j++) {
				bool notTake = dp[i - 1][j];
				bool take = false;
				if (arr[i] <= j)
					take = dp[i - 1][j - arr[i]];

				dp[i][j] = take or notTake;
			}
		return dp[n - 1][sum];

		/***Space optimization*****/ TC = O(N * SUM)  SC = O(SUM)
		                                  vector<bool> prev(sum + 1, 0), curr(sum + 1, 0);
		prev[0] = true;
		if (arr[0] <= sum)
			prev[arr[0]] = true;

		for (int i = 1; i < n; i++) {
			for (int j = 1; j <= sum; j++) {
				bool notTake = prev[j];
				bool take = false;
				if (arr[i] <= j)
					take = prev[j - arr[i]];

				curr[j] = take or notTake;
			}
			prev = curr;
		}
		return prev[sum];
	}
};




// { Driver Code Starts.
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int N, sum;
		cin >> N;
		vector<int> arr(N);
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
		}
		cin >> sum;

		Solution ob;
		cout << ob.isSubsetSum(arr, sum) << endl;
	}
	return 0;
}
// } Driver Code Ends