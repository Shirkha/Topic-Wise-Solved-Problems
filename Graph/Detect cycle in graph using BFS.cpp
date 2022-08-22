Detect cycle in undirected graph using BFS


bool check(int x, vector<int> &vis, vector<int> adj[]) {
	queue<pair<int, int>> q;
	q.push({x, -1});
	vis[x] = 1;

	while (!q.empty()) {
		auto p = q.front();
		int node = p.first;
		int par = p.second;
		q.pop();
		for (auto it : adj[node]) {
			if (!vis[it]) {
				q.push({it, node});
				vis[it] = 1;
			}
			else if (it != par)
				return true;
		}
	}
	return false;
}

bool isCycle(int v, vector<int> adj[]) {
	// Code here
	vector<int> vis(v, 0);
	for (int i = 0; i < v; i++) {
		if (!vis[i])
			if (check(i, vis, adj))
				return true;
	}
	return false;
}


