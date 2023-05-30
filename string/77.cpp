// Given a string str of length N,
// you have to find number of palindromic subsequence
// (need not necessarily be distinct) present in the string str.
// Note: You have to return the answer module 109+7;


class Solution {
public:
	int mod = 10e9 + 7;
	long long dp[1001][1001];
	long long fn(long long i, long long j, string str)
	{
		if (i == j)
			return 1;
		else if (i > j)
			return 0;
		else if (dp[i][j] != -1)
			return dp[i][j];
		else if (str[i] == str[j])
		{
			return dp[i][j] = (1 + fn(i + 1, j - 1, str)) % mod;
		}
		else
		{
			return dp[i][j] = (fn(i + 1, j, str) + fn(i, j - 1, str) - fn(i + 1, j - 1, str)) % mod;
		}
	}
	/*You are required to complete below method */
	long long int  countPS(string str)
	{
		//Your code here
		memset(dp, -1, sizeof(dp));
		return fn(0, str.length() - 1, str);
	}
