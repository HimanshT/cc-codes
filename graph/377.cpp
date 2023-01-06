// Floyd Warshall

// The problem is to find the shortest distances between every pair of vertices in a given edge-weighted directed Graph.
//  The Graph is represented as an adjacency matrix, and the matrix denotes the weight of the edges (if it exists) else -1.

class Solution {
public:
	void shortest_distance(vector<vector<int>>&matrix) {
		// Code here
		int n = matrix.size();
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (matrix[i][j] == -1)
					matrix[i][j] = INT_MAX;
		for (int k = 0; k < n; k++)
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{

					if (matrix[i][k] == INT_MAX || matrix[k][j] == INT_MAX)
						continue;
					matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
				}
			}
		}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (matrix[i][j] == INT_MAX)
					matrix[i][j] = -1;
	}
};