// Gold Mine Problem

class Solution {
public:
	int dp[50][50];
	int fn(vector<vector<int>> &arr, int i, int j)
	{
		//always pass through address
		int row = arr.size();
		int col = arr[0].size();
		if (i >= row or i<0 or j >= col)
			return 0;
		if (dp[i][j] != -1)
			return dp[i][j];
		return dp[i][j] = arr[i][j] + max(max(fn(arr, i, j + 1), fn(arr, i - 1, j + 1)), fn(arr, i + 1, j + 1));
	}
	int maxGold(int n, int m, vector<vector<int>> M)
	{
		int row = M.size();
		int col = M[0].size();
		int ans = 0;
		memset(dp, -1, sizeof(dp));
		for (int i = 0; i < row; i++)
			ans = max(ans, fn(M, i, 0));
		return ans;
	}
};