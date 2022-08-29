// Friends Pairing Problem

class Solution
{
public:
	int dp[10000];
	int m = 1000000007;
	int fn(int n)
	{
		if (n <= 0)
			return 1;
		if (dp[n] != -1)
			return dp[n];
		// if you have selected a pair,then no. of ways to select another
		//pair is from n-1 objects
		return dp[n] = (long long)(fn(n - 1) + ((long long)(n - 1) * fn(n - 2)) % m) % m;
	}
	int countFriendsPairings(int n)
	{
		memset(dp, -1, sizeof(dp));
		return fn(n);
	}
};