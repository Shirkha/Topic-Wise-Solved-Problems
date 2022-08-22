Monster power, bonus

#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, exp;
	cin >> n;
	cin >> exp;
	int power[n], bonus;
	for (int i = 0; i < n; i++) {
		cin >> power[i];
	}
	map<int, int> m;
	for (int i = 0; i < n; i++) {
		cin >> bonus;
		m[power[i]] = bonus;
	}

	int count = 0;
	for (auto it : m) {
		if (exp >= it.first) {
			exp += it.second;
			count++;
		}
		else
			break;
	}

	cout << count;

	return 0;
}







