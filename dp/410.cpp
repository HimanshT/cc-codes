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

//other dp solution
class Solution {
public:
	long long **dp;
	long long fn(int coins[], int n, int idx, int sum) {
		if (sum == 0) {
			return dp[idx][sum] = 1;
		}
		if (dp[idx][sum] != -1)
			return dp[idx][sum];
		long long ans = 0;
		for (int i = idx; i < n; i++) {
			if (coins[i] > sum)
				break;
			ans += fn(coins, n, i, sum - coins[i]);
		}
		return dp[idx][sum] = ans;
	}
	long long int count(int coins[], int N, int sum) {
		// code here.
		sort(coins, coins + N);
		dp = new long long *[N];
		for (int i = 0; i < N; i++) {
			dp[i] = new long long[sum + 1];
			memset(dp[i], -1, sizeof(long long) * (sum + 1));
		}
		long long ans = 0;
		for (int i = 0; i < N; i++) {
			if (coins[i] > sum)
				break;
			ans += fn(coins, N, i, sum - coins[i]);
		}
		for (int i = 0; i < N; i++)
			delete[] dp[i];
		delete[] dp;
		return ans;
	}
};
