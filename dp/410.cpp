// Coin Change

long long int count(int S[], int m, int n) {

	int sum = n;
	long long int dp[sum + 1][m + 1];
	for (int i = 0; i <= m; i++) dp[0][i] = 1;
	for (int i = 1; i <= sum; i++) dp[i][0] = 0;
	for (int i = 1; i <= sum; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			dp[i][j] = dp[i][j - 1];
			if (S[j - 1] <= i)
				dp[i][j] += dp[i - S[j - 1]][j];
		}
	}
	return dp[sum][m];
}