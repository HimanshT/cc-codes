// Maximize The Cut Segments

class Solution
{
public:
	//Function to find the maximum number of cuts.
	int maximizeTheCuts(int n, int x, int y, int z)
	{
		int dp[n + 1];
		memset(dp, -1, sizeof(dp));
		dp[0] = 0; //if length =0
		for (int i = 1; i <= n; i++)
		{
			if (i - x >= 0 and dp[i - x] != -1)
				dp[i] = max(dp[i], dp[i - x] + 1);
			if (i - y >= 0 and dp[i - y] != -1)
				dp[i] = max(dp[i], dp[i - y] + 1);
			if (i - z >= 0 and dp[i - z] != -1)
				dp[i] = max(dp[i], dp[i - z] + 1);
		}
		return dp[n] <= 0 ? 0 : dp[n];
	}
};