General pattern - 2 for subsequences
-- > To restrict the recursive function call for further
    -- > Ex - print only one subsequence with reqd. sum



#include <bits/stdc++.h>
    using namespace std;

bool solve(int idx, int n, int curr_sum, int sum, vector<int> &ds, int arr[]) {
    if (idx == n) {
        if (curr_sum == sum) {
            for (auto x : ds)
                cout << x << " ";
            cout << endl;
            return true;
        }
        return false;
    }

    /// solve(idx + 1, n, curr_sum, sum, ds, arr);  // not included

    ds.push_back(arr[idx]);
    curr_sum += arr[idx];                   // included
    if (solve(idx + 1, n, curr_sum, sum, ds, arr))
        return true;

    ds.pop_back();
    curr_sum -= arr[idx];
    if (solve(idx + 1, n, curr_sum, sum, ds, arr)) // not included
        return true;

    return false;
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

