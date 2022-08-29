// Find the number of islands

class Solution {
public:
	// Function to find the number of islands.
	bool isPossible(int x, int y, vector<vector<char>>& grid, vector<vector<int>> &visited)
	{
		int row = grid.size();
		int col = grid[0].size();
		if (x >= 0 and x<row and y >= 0 and y < col and grid[x][y] == '1' and visited[x][y] == 0)
			return true;
		return false;
	}
	void bfs(vector<vector<char>>& grid, int x, int y, vector<vector<int>> &visited)
	{
		queue<pair<int, int>> q;
		int arr1[] = { -1, -1, -1, 0, 0, 1, 1, 1};
		int arr2[] = { -1, 0, 1, -1, 1, -1, 0, 1};
		q.push({x, y});
		visited[x][y];
		while (!q.empty())
		{
			int n = q.size();
			while (n--)
			{
				pair<int, int> curr = q.front();
				q.pop();
				for (int i = 0; i < 8; i++)
				{
					if (isPossible(curr.first + arr1[i], curr.second + arr2[i], grid, visited))
					{
						q.push({curr.first + arr1[i], curr.second + arr2[i]});
						visited[curr.first + arr1[i]][curr.second + arr2[i]] = 1;
					}
				}
			}
		}

	}
	int numIslands(vector<vector<char>>& grid) {
		int count = 0;
		int row = grid.size();
		int col = grid[0].size();
		vector<vector<int>> visited(row, vector<int> (col, 0));
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (grid[i][j] == '1' and !visited[i][j])
				{
					bfs(grid, i, j, visited);
					count++;
				}
			}
		}
		return count;
	}
};