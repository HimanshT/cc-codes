// nCr

class Solution {
	//there is memory leak in the above setup due to continuous initialization
public:
	int m = pow(10, 9) + 7;
	int **dp;
	int fn(int n, int r)
	{
		if (n < r or n == 0 ) return 0;
		if (n == r) return 1;
		if (r == 0) return 1;
		if (dp[n][r] != -1) return dp[n][r];
		return dp[n][r] = (fn(n - 1, r - 1) + fn(n - 1, r)) % m;
	}
	int nCr(int n, int r) {
		dp = new int*[n + 1];
		for (int i = 0; i <= n; i++)
		{
			dp[i] = new int [r + 1];
			memset(dp[i], -1, sizeof(int) * (r + 1));
		}
		// code here
		int ans = fn(n, r);
		for (int i = 0; i <= n; i++)
			delete[] dp[i];
		delete[] dp;
		return ans;
	}
};