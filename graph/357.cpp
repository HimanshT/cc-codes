// BFS of graph

vector<int> bfsOfGraph(int V, vector<int> adj[]) {
	// Code here
	vector<int> ans;
	vector<int> visited(V, 0);
	queue<int> q;
	q.push(0); visited[0] = 1;
	while (!q.empty())
	{
		int v = q.front();
		q.pop();
		ans.push_back(v);
		for (auto u : adj[v])
		{
			if (!visited[u])
			{
				q.push(u);
				visited[u] = 1;
			}
		}
	}
	return ans;
}