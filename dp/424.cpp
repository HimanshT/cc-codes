// Longest Repeating Subsequence

class Solution {
public:
	int dp[1001][1001];
	int lcs(string &str1, string &str2, int i, int j)
	{

		if (i < 0 || j < 0)
			return 0;
		if (dp[i][j] != -1)
			return dp[i][j];
		if (str1[i] == str2[j] && i != j)
			return dp[i][j] = 1 + lcs(str1, str2, i - 1, j - 1);
		return dp[i][j] = max(lcs(str1, str2, i, j - 1), lcs(str1, str2, i - 1, j));

	}
	int LongestRepeatingSubsequence(string str) {
		string str1 = str;
		string str2 = str;
		int n = str.length();
		memset(dp, -1, sizeof(dp));
		return lcs(str1, str2, n - 1, n - 1);
	}

};
