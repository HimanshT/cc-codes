// Given a weighted directed graph with n nodes and m edges.
// Nodes are labeled from 0 to n-1, the task is to check if it contains a negative weight cycle or not.
// Bellman Ford Algorithm

class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges) {
		// Code here
		vector<int> d(n, INT_MAX);
		d[0] = 0;
		for (int i = 0; i < n - 1; i++)
		{
			for (auto edge : edges)
			{
				int u = edge[0], v = edge[1], weight = edge[2];
				if (d[u] != INT_MAX and d[v] > d[u] + weight)
					d[v] = d[u] + weight;
			}
		}

		for (auto edge : edges)
		{
			int u = edge[0], v = edge[1], weight = edge[2];
			if (d[v] > d[u] + weight)
				return 1;
		}
		return 0;
	}
};