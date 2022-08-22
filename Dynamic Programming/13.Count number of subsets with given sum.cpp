Count number of subset with given sum.
=> We have to handle the case if array element can be 0
	=> if we include 0 it will not affect the sum
		=> so for every 0 we have 2 possible ways

			class Solution {
#define mod (int)(1e9 + 7);
				/**Recursive + memoization***/
				int check(int ind, int sum, int arr[], vector<vector<int>> &dp) {
						if (ind == 0) {
							if (sum == 0 and arr[0] == 0)
								return 2;        // 2 subset either we can take 0 or not take
							if (sum == 0 || arr[0] == sum)
								return 1;
							return 0;
						}
						if (dp[ind][sum] != -1)
							return dp[ind][sum];

						int notTake = check(ind - 1, sum, arr, dp);
						int  take = 0;
						if (arr[ind] <= sum)
							take = check(ind - 1, sum - arr[ind], arr, dp);

						return dp[ind][sum] = (notTake + take) % mod;
					}


				public:
					int perfectSum(int arr[], int n, int sum) {
						/***Recursive****/
						vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
						return check(n - 1, sum, arr, dp);

						/***Tabulation***/
						vector<vector<int>> dp(n, vector<int>(sum + 1, 0));
						if (arr[0] == 0)
							dp[0][0] = 2;  // 2 ways either include or not
						else
							dp[0][0] = 1;

						if (arr[0] and arr[0] <= sum)
							dp[0][arr[0]] = 1;


						for (int i = 1; i < n; i++)
							for (int j = 0; j <= sum; j++) {
								int notTake = dp[i - 1][j];
								int take = 0;
								if (arr[i] <= j)
									take = dp[i - 1][j - arr[i]];

								dp[i][j] = (take + notTake) % mod;
							}

						return dp[n - 1][sum];
					}

				};

// Space optimization

vector<int> prev(sum + 1, 0), curr(sum + 1, 0);
if (arr[0] == 0)
	prev[0] = 2;
else
	prev[0] = 1;

if (arr[0] and arr[0] <= sum)
	prev[arr[0]] = 1;

for (int i = 1; i < n; i++) {
	for (int j = 0; j <= sum; j++) {
		int notPick = prev[j];
		int pick = 0;
		if (arr[i] <= j)
			pick = prev[j - arr[i]];

		curr[j] = (pick + notPick) % mod;
	}
	prev = curr;
}
return prev[sum];

// Using only single row

vector<int> prev(sum + 1, 0);
if (arr[0] == 0)
	prev[0] = 2;
else
	prev[0] = 1;

if (arr[0] and arr[0] <= sum)
	prev[arr[0]] = 1;

for (int i = 1; i < n; i++) {
	for (int j = sum; j >= 0; j--) {
		int notPick = prev[j];
		int pick = 0;
		if (arr[i] <= j)
			pick = prev[j - arr[i]];

		prev[j] = (pick + notPick) % mod;
	}

}
return prev[sum];