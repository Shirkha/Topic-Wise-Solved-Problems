General pattern - 3 to count no. of subsequences


#include <bits/stdc++.h>
using namespace std;

int solve(int idx, int n, int curr_sum, int sum, int arr[]) {
    if (idx == n) {
        if (curr_sum == sum) {
            return 1;
        }
        return 0;
    }

    /// solve(idx + 1, n, curr_sum, sum, ds, arr);  // not included



    curr_sum += arr[idx];                   // included
    int l = solve(idx + 1, n, curr_sum, sum, arr);

    curr_sum -= arr[idx];
    int r = solve(idx + 1, n, curr_sum, sum, arr); // not included

    return l + r;
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int arr[] = {1, 2, 3, 1, 1};
    int n = 5;
    int sum = 3;

    cout << solve(0, n, 0, sum, arr);

    return 0;
}

