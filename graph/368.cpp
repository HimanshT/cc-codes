// Topological sort

public:
//Function to return list containing vertices in Topological order.
vector<int> topoSort(int V, vector<int> adj[])
{
	vector<int> indegree(V, 0);
	vector<int> ans;
	for (int i = 0; i < V; i++)
	{
		for (int& u : adj[i])
			indegree[u]++;
	}
	queue<int> q;
	for (int i = 0; i < V; i++)
		if (indegree[i] == 0)
			q.push(i);
	while (!q.empty())
	{
		int u = q.front(); q.pop();
		ans.push_back(u);
		for (int& v : adj[u])
		{
			indegree[v]--;
			if (indegree[v] == 0)
				q.push(v);
		}
	}
	return ans;
}