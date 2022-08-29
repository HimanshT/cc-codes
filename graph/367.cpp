// Implementing Dijkstra Algorithm

class Solution
{
public:
	//Function to find the shortest distance of all the vertices
	//from the source vertex S.
	vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
	{
		vector<int> dist(V, INT_MAX);
		dist[S] = 0;
		vector<bool> visited(V, false);
		for (int i = 0; i < V - 1; i++)
		{
			int u = -1;
			for (int j = 0; j < V; j++)
			{
				if (!visited[j] and (u == -1 or dist[j] < dist[u]))
				{
					u = j;
				}
			}
			visited[u] = true;
			for (auto& v : adj[u])
			{
				if (!visited[v[0]])
				{
					dist[v[0]] = min(dist[v[0]], dist[u] + v[1]);
				}
			}
		}
		return dist;
	}
};