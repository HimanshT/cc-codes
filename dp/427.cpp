LCS of three strings//

int dp[20][20][20];
int lcs(string A, string B, string C, int n1, int n2, int n3)
{
	if (n1 < 0 or n2 < 0 or n3 < 0)
		return 0;
	if (dp[n1][n2][n3] != -1)
		return dp[n1][n2][n3];
	if (A[n1] == B[n2] and B[n2] == C[n3] )
		return dp[n1][n2][n3] = lcs(A, B, C, n1 - 1, n2 - 1, n3 - 1) + 1;
	return dp[n1][n2][n3] = max(max(lcs(A, B, C, n1 - 1, n2, n3), lcs(A, B, C, n1, n2 - 1, n3)), lcs(A, B, C, n1, n2, n3 - 1));
}
int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
{
	// your code here
	memset(dp, -1, sizeof(dp));
	return lcs(A, B, C, n1 - 1, n2 - 1, n3 - 1);
}