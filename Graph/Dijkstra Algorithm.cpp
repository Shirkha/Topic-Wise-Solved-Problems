Dijkstra Algorithm

// Using queue

vector<int> dist(n, INT_MAX);
queue<int> q;
dist[src] = 0;
q.push(src);

while (!q.empty()) {
	int node = q.front();
	q.pop();

	for (auto next : adj[node]) {
		int nextNode = next[0];
		int nextDist = next[1];
		if (dist[node] + nextDist < dist[nextNode]) {
			dist[nextNode] = dist[node] + nextDist;
			q.push(nextNode);
		}
	}
}
return dist;

// Using priority queue to greedily pick min dist

vector<int> dist(n, INT_MAX);
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
dist[src] = 0;
pq.push({0, src});


while (!pq.empty()) {
	int node = pq.top().second;
	//  int nodeDist = pq.top().first;
	pq.pop();                       // (node,weight)

	for (auto next : adj[node]) {
		int nextNode = next[0];
		int nextDist = next[1];
		if (dist[node] + nextDist < dist[nextNode]) {
			dist[nextNode] = dist[node] + nextDist;
			pq.push({dist[nextNode], nextNode});
		}
	}
}

return dist;