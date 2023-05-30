// Given two sequences, find the length of longest subsequence present in both of them. Both the strings are of uppercase.

class Solution
{
public:
	int dp[1001][1001];
	Solution()
	{
		memset(dp, -1, sizeof(dp));
	}
	//Function to find the length of longest common subsequence in two strings.
	int lcs(int x, int y, string s1, string s2)
	{
		// your code here
		if (x == 0 || y == 0)
			return 0;
		if (dp[x][y] != -1)
			return dp[x][y];
		if (s1[x - 1] == s2[y - 1])
		{
			return dp[x][y] = 1 + lcs(x - 1, y - 1, s1, s2);
		} else {
			return dp[x][y] = max(lcs(x, y - 1, s1, s2), lcs(x - 1, y, s1, s2));
		}
	}
};