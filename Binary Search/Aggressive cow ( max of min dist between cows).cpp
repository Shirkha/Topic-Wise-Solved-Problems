Aggressive cow ( max of min dist between cows)

int aggressiveCows(vector<int> &stalls, int k)
{

	int n = stalls.size();
	if (k > n)
		return -1;
	sort(stalls.begin(), stalls.end());
	int lo = 1, hi = stalls[n - 1] - stalls[0], res = -1;
	while (lo <= hi) {
		int mid = (lo + hi) >> 1;
		if (isPossible(stalls, n, k, mid)) {
			res = mid;
			lo = mid + 1;
		}
		else
			hi = mid - 1;
	}
	return res;
}

bool isPossible(vector<int> &arr, int n, int k, int dist) {
	int pos = arr[0], count = 1;
	for (int i = 1; i < n; i++) {
		if (arr[i] - pos >= dist) {
			pos = arr[i];
			count++;
		}
		if (count == k)
			return true;
	}
	return false;
}