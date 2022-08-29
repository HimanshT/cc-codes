// Matrix Chain Multiplication

class Solution {
public:
	int dp[100][100];
	int mcm(int *arr, int l, int r)
	{
		if (dp[l][r] != -1)
			return dp[l][r];
		if (l + 1 == r)
			return dp[l][r] = 0;
		int ans = INT_MAX;
		for (int i = l + 1; i < r; i++)
		{
			ans = min(ans, mcm(arr, l, i) + mcm(arr, i, r) + arr[l] * arr[r] * arr[i]);
		}
		return dp[l][r] = ans;
	}
	int matrixMultiplication(int N, int arr[])
	{
		memset(dp, -1, sizeof(dp));
		return mcm(arr, 0, N - 1);
	}
};