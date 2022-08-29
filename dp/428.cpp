// Maximum sum increasing subsequence

class Solution {
public:
	int maxSumIS(int arr[], int n)
	{
		int dp[n];
		dp[0] = arr[0];
		for (int i = 1; i < n; i++)
		{
			int value = 0;
			for (int j = i - 1; j >= 0; j--)
			{
				if (arr[j] < arr[i])
					value = max(value, dp[j]);
			}
			dp[i] = value + arr[i];
		}

		int ans = dp[0];
		for (int i = 1; i < n; i++)
			ans = max(ans, dp[i]);
		return ans;
	}
};