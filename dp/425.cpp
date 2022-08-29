// Longest Increasing Subsequence

class Solution {
public:
	int bs(vector<int> &lis, int low, int high, int x)
	{
		while (high > low)
		{
			int mid = (high + low) / 2;
			if (lis[mid] >= x)
				high = mid;
			else
				low = mid + 1;
		}
		return high;
	}
	int lengthOfLIS(vector<int>& nums) {
		int n = nums.size();
		vector<int> lis;
		for (int i = 0; i < n; i++)
		{
			if (lis.empty() || nums[i] > lis[lis.size() - 1])
				lis.push_back(nums[i]);
			else if (nums[i] < lis[lis.size() - 1])
			{
				int x = bs(lis, 0, lis.size() - 1, nums[i]);
				lis[x] = nums[i];
			}
		}
		return lis.size();
	}
};
