// Given a 2D grid of n*m of characters and a word,
// find all occurrences of given word in grid.
// A word can be matched in all 8 directions at any point.
//  Word is said be found in a direction if all characters match in this direction
//  (not in zig-zag form). The 8 directions are, horizontally left, horizontally right,
//  vertically up, vertically down and 4 diagonal directions.
//

class Solution {
public:
	bool fn(vector<vector<char>>grid, string word, int i, int j, int x, int y)
	{
		int ptr = 1;
		int row = grid.size();
		int col = grid[0].size();
		i += x, j += y;
		while (i >= 0 and i<row and j >= 0 and j < col)
		{
			if (grid[i][j] == word[ptr])
			{
				ptr++; i += x; j += y;
				if (ptr == word.size()) break;
			} else break;
		}
		if (ptr == word.size()) return true;
		return false;
	}
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word) {
		// Code here
		vector<pair<int, int>> v{{0, -1}, { -1, 0}, { -1, -1}, {0, 1}, {1, 0}, {1, 1}, {1, -1}, { -1, 1}};
		vector<vector<int>> ans;
		int row = grid.size();
		int col = grid[0].size();
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				vector<int> temp = {i, j};
				if (grid[i][j] == word[0])
				{
					for (int x = 0; x < 8; x++)
					{
						if (fn(grid, word, i, j, v[x].first, v[x].second))
						{
							ans.push_back(temp);
							break;
						}
					}
				}
			}
		}
		return ans;
	}
};