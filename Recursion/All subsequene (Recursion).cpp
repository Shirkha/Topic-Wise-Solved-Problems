All subsequene (Recursion)

void solve(int idx, string s, string &op) {
	if (idx == s.size()) {
		cout << op << " ";
		return;
	}

	//pick
	op.push_back(s[idx]);
	solve(idx + 1, s, op);

	//not pick
	op.pop_back();
	solve(idx + 1, s, op);
}