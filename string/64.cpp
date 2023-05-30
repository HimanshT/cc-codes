// Given a string str, find the length of the longest repeating subsequence such that it can be found twice in the given string.
//The two identified subsequences A and B can use the same ith character from string str
//if and only if that ith character has different indices in A and B.


// A subsequence is a sequence that appears in the same relative order, but not necessarily contiguous

class Solution {
public:
	int dp[1001][1001];
	int lcs(string str, int x, int y)
	{
		if (x == str.length() or y == str.length())
			return 0;
		if (dp[x][y] != -1)
			return dp[x][y];
		if (str[x] == str[y] and x != y)
			return dp[x][y] = 1 + lcs(str, x + 1, y + 1);
		return dp[x][y] = max(lcs(str, x + 1, y), lcs(str, x, y + 1));
	}
	int LongestRepeatingSubsequence(string str) {
		// Code here
		int x = 0, y = 0;
		memset(dp, -1, sizeof(dp));
		return lcs(str, x, y);
	}

};



