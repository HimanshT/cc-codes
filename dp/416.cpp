// Edit Distance
// Given two strings s and t. Return the minimum number of operations required to convert s to t.


class Solution {
public:
	int dp[100][100];
	int lcs(string s, string t, int i, int j)
	{
		if (i < 0)
			return j + 1;
		else if (j < 0)
			return i + 1;
		if (dp[i][j] != -1)
			return dp[i][j];
		if (s[i] == t[j])
			return dp[i][j] = lcs(s, t, i - 1, j - 1);
		else
			return dp[i][j] = 1 + min(min(lcs(s, t, i - 1, j), lcs(s, t, i, j - 1)), lcs(s, t, i - 1, j - 1));
	}
	int editDistance(string s, string t) {
		int n = s.length();
		int m = t.length();
		memset(dp, -1, sizeof(dp));
		int x = lcs(s, t, n - 1, m - 1);
		return x;
	}
};