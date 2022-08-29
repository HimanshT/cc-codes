// Painting the Fence

long long countWays(int n, int k) {
	long long int dp[n + 1];
	long long mod = 1000000007;
	dp[0] = 0;
	dp[1] = k;
	dp[2] = k * k;
	for (long long i = 3; i <= n; i++)
	{
		dp[i] = ((k - 1) * (dp[i - 1] + dp[i - 2])) % mod;
	}
	return dp[n];
}