// Longest Common Subsequence

class Solution
{
public:
	int dp[1000][1000];
	int fn(string s1, string s2, int i, int j)
	{
		if (i < 0 or j < 0)
			return 0;
		if (dp[i][j] != -1)
			return dp[i][j];
		if (s1[i] == s2[j])
			return dp[i][j] = 1 + fn(s1, s2, i - 1, j - 1);
		return dp[i][j] = max(fn(s1, s2, i - 1, j), fn(s1, s2, i, j - 1));
	}
	int lcs(int x, int y, string s1, string s2)
	{
		memset(dp, -1, sizeof(dp));
		return fn(s1, s2, x - 1, y - 1);
	}
};