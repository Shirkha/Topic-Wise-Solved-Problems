General pattern for subsequence---> pick or not pick
##STRIVER


#include <bits/stdc++.h>
using namespace std;

void solve(int idx, int n, int curr_sum, int sum, vector<int> &ds, int arr[]) {
    if (idx == n) {
        if (curr_sum == sum) {
            for (auto x : ds)
                cout << x << " ";
            cout << endl;
        }
        return;
    }

    /// solve(idx + 1, n, curr_sum, sum, ds, arr);  // not included

    ds.push_back(arr[idx]);
    curr_sum += arr[idx];                   // included
    solve(idx + 1, n, curr_sum, sum, ds, arr);

    ds.pop_back();
    curr_sum -= arr[idx];
    solve(idx + 1, n, curr_sum, sum, ds, arr);     // not included
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int arr[] = {1, 2, 3, 1, 1};
    int n = 5;
    int sum = 3;
    vector<int> ds;
    solve(0, n, 0, sum, ds, arr);

    return 0;
}

