//print all solutions of n queen problem;

bool safe(int row, int col, vector<string> board, int n)
{
	int r = row;
	int c = col;
	//checking upper diagonal
	while (row >= 0 && col >= 0)
	{
		if (board[row][col] == 'Q') return false;
		row--; col--;
	}


	row = r, col = c;
	while ( col >= 0)
	{
		if (board[row][col] == 'Q') return false;
		col--;
	}
	//checking right top diagonal
	row = r, col = c;
	while (row < n && col >= 0)
	{
		if (board[row][col] == 'Q') return false;
		row++; col--;
	}

	return true;
}

void search(int col, vector<string>&board, vector<vector<string>>&ans, int n)
{
	if (col == n)
	{
		ans.push_back(board);
		return;
	}

	for (int row = 0; row < n; row++)
	{
		if (safe(row, col, board, n))
		{
			board[row][col] = 'Q';
			search(col + 1, board, ans, n);
			board[row][col] = '.';
		}
	}


}

vector<vector<string>> solveNQueens(int n) {
	vector<vector<string>> ans;
	vector<string> board(n);
	string s(n, '.');
	for (int i = 0; i < n; i++)
		board[i] = s;
	search(0, board, ans, n);
	return ans;
}