// Flood Fill

class Solution {
public:
	bool isposs(int x, int y, int row, int col, vector<vector<int>>& image, int color)
	{
		if (x >= 0 and x<row and y >= 0 and y < col and image[x][y] == color)
			return true;
		return false;
	}
	vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
		int row = image.size();
		int col = image[0].size();
		vector<vector<int>> visited(row, vector<int>(col, 0));
		//bfs approach
		queue<pair<int, int>> q;
		q.push({sr, sc});
		visited[sr][sc] = 1;
		while (!q.empty())
		{
			int n = q.size();
			for (int i = 0; i < n; i++)
			{
				int xx = q.front().first;
				int yy = q.front().second;
				q.pop();

				int r[4] = {1, -1, 0, 0};
				int c[4] = {0, 0, 1, -1};

				for (int i = 0; i < 4; i++)
				{
					int x1 = xx + r[i], y1 = yy + c[i];
					if (isposs(x1, y1, row, col, image, image[xx][yy]) && !visited[x1][y1])
					{
						q.push({x1, y1});
						visited[x1][y1] = 1;
					}
				}

				image[xx][yy] = color;
			}
		}
		return image;
	}
};