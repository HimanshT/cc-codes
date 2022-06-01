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