// DFS of Graph

void dfs(int v, vector<int> adj[], vector<bool>&visited, vector<int>&ans)
{
	visited[v] = true;
	ans.push_back(v);
	for (auto u : adj[v])
	{
		if (!visited[u])
		{
			dfs(u, adj, visited, ans);
		}
	}
}
vector<int> dfsOfGraph(int V, vector<int> adj[]) {
	vector<bool> visited(V, false);
	vector<int> ans;
	dfs(0, adj, visited, ans);
	return ans;
}