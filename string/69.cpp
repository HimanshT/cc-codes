// Given two strings s and t. Return the minimum number of operations required to convert s to t.
// The possible operations are permitted:

// Insert a character at any position of the string.
// Remove any character from the string.
// Replace any character from the string with any other character.

int editDistance(string s, string t) {
	// Code here
	int m = s.length();
	int n = t.length();
	int dp[m + 1][n + 1];
	for (int i = 0; i <= m; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			//if string1 len is 0,then fill that row with col no.
			if (i == 0)
				dp[i][j] = j;
			//if string2 len is 0,then fill that col with row no.
			else if (j == 0)
				dp[i][j] = i;
			//if last characters are same,then ans(m,n)=ans(m-1,n-1)
			// abc dbc --. ab,db
			else if (s[i - 1] == t[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1];
			}
			// if the last characters are not same,then take the min of
			// insert<-  | remove ,diagonal-> replace
			else
			{
				//dp[i][j]=min(dp[i-1][j),dp[i][j-1],dp[i][j])
				dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]);
				dp[i][j] = 1 + min(dp[i][j], dp[i - 1][j - 1]);
			}
		}
	}
	return dp[m][n];
}



class Solution {
public:
	int dp[101][101];
	int fn(int idx1, string s, int idx2, string t)
	{
		int ans = 0;
		if (idx1 == -1)
			return idx2 + 1;
		else if (idx2 == -1)
			return idx1 + 1;
		else {
			if (dp[idx1][idx2] != -1)
				return dp[idx1][idx2];
			if (s[idx1] == t[idx2])
			{
				ans = fn(idx1 - 1, s, idx2 - 1, t);
			} else
			{
				ans = 1 + min(fn(idx1, s, idx2 - 1, t), min(fn(idx1 - 1, s, idx2, t), fn(idx1 - 1, s, idx2 - 1, t)));
			}
		}
		return dp[idx1][idx2] = ans;
	}
	int editDistance(string s, string t) {
		memset(dp, -1, sizeof(dp));
		// Code here
		return fn(s.length() - 1, s, t.length() - 1, t);
	}
};