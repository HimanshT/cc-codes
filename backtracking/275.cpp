//Rat in a Maze Problem - I  top bottom up and down

vector<string> ans;
void fn(vector<vector<int>> &m, int i, int j, int n, string str)
{
	if (m[i][j] == 0)
		return;
	if (i == n - 1 && j == n - 1)
	{
		ans.push_back(str);
		return ;
	}
	else
	{
		m[i][j] = 0;
		if (j + 1 < n)
		{
			string temp = str;
			temp.push_back('R');
			fn(m, i, j + 1, n, temp);
		}
		if (i + 1 < n)
		{
			string temp = str;
			temp.push_back('D');
			fn(m, i + 1, j, n, temp);
		}
		if (i - 1 >= 0)
		{
			string temp = str;
			temp.push_back('U');
			fn(m, i - 1, j, n, temp);
		}
		if (j - 1 >= 0)
		{
			string temp = str;
			temp.push_back('L');
			fn(m, i, j - 1, n, temp);
		}
		m[i][j] = 1;
	}
}
vector<string> findPath(vector<vector<int>> &m, int n) {
	// Your code goes here
	string str = "";
	fn(m, 0, 0, n, str);
	return ans;
}



//better optimised code
void getallpath(int matrix[MAX][MAX], int n, int row, int col, vector<string> &ans, string cur)
{
	if (row >= n or col >= n or row < 0 or col < 0 or matrix[row][col] == 0)
		return ;

	if (row == n - 1 and col == n - 1)
	{
		ans.push_back(cur);
		return ;
	}

	//now if its one we have 4 calls
	matrix[row][col] = 0;

	getallpath(matrix, n, row - 1, col, ans, cur + "U");
	getallpath(matrix, n, row, col + 1, ans, cur + "R");
	getallpath(matrix, n, row, col - 1, ans, cur + "L");
	getallpath(matrix, n, row + 1, col, ans, cur + "D");

	matrix[row][col] = 1;

	return ;
}

vector<string> findPath(int matrix[MAX][MAX], int n) {
	// Your code goes here
	vector<string> ans;
	getallpath(matrix, n, 0, 0, ans, "");
	return ans;
}