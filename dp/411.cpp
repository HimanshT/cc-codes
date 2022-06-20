// 0 - 1 Knapsack Problem

int knapSack(int W, int wt[], int val[], int n)
{
	if (n == 0 || W == 0)
		return 0;
	if (wt[n - 1] > W)
		return knapSack(W, wt, val, n - 1);
	else
		return (max(knapSack(W, wt, val, n - 1), val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1)));
}

//dp solution

int knapSack(int W, int wt[], int val[], int n)
{
	int dp[n + 1][W + 1];
	for (int i = 0; i <= n; i++) dp[i][0] = 0;
	for (int j = 0; j <= W; j++) dp[0][j] = 0;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= W; j++)
		{
			if (wt[i - 1] > j)
				dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
		}
	}
	return dp[n][W];
}