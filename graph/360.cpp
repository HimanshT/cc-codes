// Detect cycle in an undirected graph

bool dfs(int src, int parent, vector<int> adj[], vector<bool> &visited)
{
	visited[src] = true;
	for (int &u : adj[src])
	{
		if (visited[u] == false)
		{
			if (dfs(u, src, adj, visited))
				return true;
		}
		else if (u != parent)
			return true;
	}
	return false;
}
// Function to detect cycle in an undirected graph.
bool isCycle(int V, vector<int> adj[]) {
	// Code here
	vector<bool> visited(V, false);
	for (int i = 0; i < V; i++)
	{
		if (visited[i] == false)
		{
			if (dfs(i, -1, adj, visited))
				return true;
		}
	}
	return false;
}