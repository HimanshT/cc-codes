// BFS of graph

vector<int> bfsOfGraph(int V, vector<int> adj[]) {
	vector<int> sol;
	queue<int> q;
	unordered_map<int, int> umap;
	q.push(0);
	umap[0]++;
	while (!q.empty())
	{
		int curr = q.front();
		q.pop();
		for (int i = 0; i < adj[curr].size(); i++)
		{
			if (umap[adj[curr][i]] == 0)
			{
				q.push(adj[curr][i]);
				umap[adj[curr][i]]++;
			}
		}
		sol.push_back(curr);
	}

	return sol;
}