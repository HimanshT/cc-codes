// Rat in a Maze Problem - I

vector<string> ans;
void fn(vector<vector<int>> &m, int i, int j, int n, string str)
{
	if (i >= n || i < 0 || j >= n || j < 0)
		return; //always put array bounds on top
	if (m[i][j] == 0)
		return;
	if (i == n - 1 && j == n - 1)
	{
		ans.push_back(str);
		return ;
	}

	m[i][j] = 0;
	fn(m, i, j + 1, n, str + "R");
	fn(m, i + 1, j, n, str + "D");
	fn(m, i - 1, j, n, str + "U");
	fn(m, i, j - 1, n, str + "L");
	m[i][j] = 1;
}
vector<string> findPath(vector<vector<int>> &m, int n) {
	// Your code goes here
	string str = "";
	fn(m, 0, 0, n, str);
	return ans;
}