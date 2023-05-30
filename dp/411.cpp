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



//other approach
class Solution
{
public:
	int **dp;
	int fn(int w, int *wt, int *val, int idx, int n)
	{
		if (idx == n or w == 0)
			return 0;
		if (dp[idx][w] != -1)
			return dp[idx][w];
		if (w < wt[idx])
			return dp[idx][w] = fn(w, wt, val, idx + 1, n);
		return dp[idx][w] = max(fn(w - wt[idx], wt, val, idx + 1, n) + val[idx], fn(w, wt, val, idx + 1, n));
	}
	//Function to return max value that can be put in knapsack of capacity W.
	int knapSack(int W, int wt[], int val[], int n)
	{
		dp = new int *[n];
		for (int i = 0; i < n; i++)
		{
			dp[i] = new int[W + 1];
			memset(dp[i], -1, sizeof(int) * (W + 1));
		}
		return fn(W, wt, val, 0, n);
	}
};