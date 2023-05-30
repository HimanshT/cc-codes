// Find a specific pair in Matrix

#include <bits/stdc++.h>
using namespace std;

int maxdiff( int **mat, int n)
{
	int dp[n][n];
	dp[n - 1][n - 1] = mat[n - 1][n - 1];
	for (int c = n - 2; c >= 0; c--)
		dp[n - 1][c] = max(dp[n - 1][c], dp[n - 1][c + 1]);
	for (int r = n - 2; r >= 0; r--)
		dp[r][n - 1] = max(dp[r][n - 1], dp[r + 1][n - 1]);

	int ans = INT_MIN;
	for (int i = n - 2; i >= 0; i--)
	{
		for (int j = n - 2; j >= 0; j--)
		{
			ans = max(ans, mat[i + 1][j + 1] - mat[i][j]);
			dp[i][j] = max(mat[i][j], max(dp[i + 1][j], dp[i][j + 1]));
		}
	}
	return ans;
}

int main()
{
	int n = 5;
	int **mat = new int*[n];
	for (int i = 0; i < n; i++)
		mat[i] = new int[n];
	// mat[n][n] = {{ 1, 2, -1, -4, -20 },
	// 	{ -8, -3, 4, 2, 1 },
	// 	{ 3, 8, 6, 1, 3 },
	// 	{ -4, -1, 1, 7, -6 },
	// 	{ 0, -4, 10, -5, 1 }
	// };

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> mat[i][j];

	cout << maxdiff(mat, n);
}