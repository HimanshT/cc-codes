// Given a number n. The task is to find the smallest number whose factorial contains at least n trailing zeroes.

class Solution
{
public:
	int fn(int n)
	{
		int x = 5;
		int count = 0;
		while (1)
		{
			int temp = n / x;
			if (temp == 0) break;
			count += temp;
			x *= 5;
		}
		return count;
	}
	int findNum(int n)
	{
		int low = 1, high = INT_MAX;
		int ans = -1;
		while (low <= high)
		{
			int mid = (low + high) / 2;
			int count = fn(mid);
			if (count >= n)
			{
				ans = mid;
				high = mid - 1;
			} else low = mid + 1;
		}
		return ans;
	}
};