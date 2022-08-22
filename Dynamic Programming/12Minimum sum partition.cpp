Minimum sum partition  (Striver)
---> Given an array arr of size N containing non - negative integers, the task is to divide it into two sets S1 and S2 such that the absolute difference between their sums is minimum and find the minimum difference

---> See first classmate note
Solution:
---> Fill the table same as Subset sum
---> Find the S1 as close as possible to sum / 2
---> S2 - S1 = (total sum - s1) - s1 = total sum - 2s1
///We only require the last row of table
//We can not use Recursive + Memoization to get the table
//beacause Recursion does not visit all the n * sum state
//So we have to do by Tabualtion only

int minDifference(int arr[], int n)  {
	// Your code goes here
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += arr[i];


	bool dp[n][sum + 1];

	for (int i = 0; i < n; i++)
		dp[i][0] = true;
	for (int j = 1; j <= sum; j++)
		dp[0][j] = false;

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

	int s1;
	for (int j = sum / 2; j >= 0; j--) {
		if (dp[n - 1][j]) {
			s1 = j;
			break;
		}

	}
	int minDiff = sum - 2 * s1;
	return minDiff;
}