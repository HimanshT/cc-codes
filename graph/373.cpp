//kruskal's algo

class DSU {
	int* parent;
	int* rank;

public:
	DSU(int n)
	{
		parent = new int[n];
		rank = new int[n];

		for (int i = 0; i < n; i++) {
			parent[i] = -1;
			rank[i] = 1;
		}
	}

	// Find function
	int find(int i)
	{
		if (parent[i] == -1)
			return i;

		return parent[i] = find(parent[i]);
	}

	// Union function
	//having same rank,rank updates by 1
	//having different rank,no update
	if (rank[s2] > rank[s1])
	{
		parent[s1] = s2; // if the parents are different ,then the graph with lesser rank will become the child
	}
	else if (rank[s1] > rank[s2]) {
		parent[s2] = s1;
	} else {
		parent[s2] = s1;
		rank[s1] += 1;
	}
};

class Solution
{
public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	int spanningTree(int V, vector<vector<int>> adj[])
	{
		vector<pair<int, pair<int, int>>> edges;
		for (int i = 0; i < V; i++)
		{
			for (auto& it : adj[i])
				edges.push_back({it[1], {it[0], i}});
		}
		sort(edges.begin(), edges.end());
		DSU s(V);
		int min_weight = 0;
		for (auto edge : edges)
		{
			int w = edge.first;
			int x = edge.second.first;
			int y = edge.second.second;
			//if it does not form a cycle
			if (s.find(x) != s.find(y))
			{
				s.unite(x, y);
				min_weight += w;
			}
		}
		return min_weight;
	}
};


