// Detect cycle in a directed graph

bool dfs(vector<int> adj[], int v, vector<bool> &visited, vector<bool> &recSt)
{
	visited[v] = true; recSt[v] = true;
	for (auto u : adj[v])
	{
		if (visited[u] == false && dfs(adj, u, visited, recSt))
			return true;
		else if (recSt[u] == true)
			return true;
	}
	recSt[v] = false;
	return false;
}
// Function to detect cycle in a directed graph.
bool isCyclic(int V, vector<int> adj[]) {
	vector<bool> visited(V, false);
	vector<bool> recSt(V, false);
	for (int i = 0; i < V; i++)
	{
		if (visited[i] == false)
		{
			if (dfs(adj, i, visited, recSt) == true)
				return true;
		}
	}
	return false;
}