// Given two strings wild and pattern where wild string may contain wild card characters and pattern string is a normal string.
// Determine if the two strings match. The following are the allowed wild card characters in first string :-

class Solution {
public:
	int dp[1001][1001];
	bool fn(int i, int j, string t, string p)
	{
		if (i == t.length() and j == p.length())
			return true;
		else if (i == t.length() - 1 and t[i] == '*')
			return true;
		else if (t[i] == '*' and j == p.length())
			return true;
		else if ((i == t.length() and j != p.length()) || (i != t.length() and j == p.length()))
			return false;
		else if (dp[i][j] != -1)
			return dp[i][j];
		//condition for recursively calling
		if (t[i] == p[j] or t[i] == '?')
			return dp[i][j] = fn(i + 1, j + 1, t, p);
		else if (t[i] == '*')
		{
			int ptr1 = j;
			while (ptr1 < p.length())
			{
				if (fn(i + 1, ptr1, t, p)) return dp[i][j] = true;
				else ptr1++;
			}
			return dp[i][j] = false;
		}
		else return dp[i][j] = false;
	}
	bool match(string wild, string pattern)
	{
		// code here
		memset(dp, -1, sizeof(dp));
		return fn(0, 0, wild, pattern);
	}
};