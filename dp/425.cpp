// Longest Increasing Subsequence

int fn(int *a, int ci, int pi, int n, vector<vector<int>>&dp)
{
	if (ci == n)
		return 0;
	if (dp[ci][pi + 1] != -1)
		return dp[ci][pi + 1];
	int len = fn(a, ci + 1, pi, n, dp);
	if (pi == -1 || a[pi] < a[ci])
	{
		len = max(len, 1 + fn(a, ci + 1, ci, n, dp));
	}
	dp[ci][pi + 1] = len;
	return len;
}
int longestSubsequence(int n, int a[])
{
	vector<vector<int>> dp(n, vector<int> (n + 1, -1));
	int ans = fn(a, 0, -1, n, dp);
	return ans;
}

//if n=10^5,it will be difficult to create a vector,so better approach
