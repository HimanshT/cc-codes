// Minimum Size Subarray Sum

class Solution {
public:
	int minSubArrayLen(int target, vector<int>& nums) {
		int ptr1 = 0, ptr2 = 0, currsum = 0, ans = INT_MAX;
		int n = nums.size();
		while (ptr1 < n and ptr2 < n)
		{
			if (ptr1 == ptr2)
			{
				currsum = nums[ptr1];
				if (currsum >= target)
					ans = min(ans, 1);
				ptr2++;
				if (ptr2 < n)
					currsum += nums[ptr2];
			} else {
				if (currsum >= target)
				{
					ans = min(ans, ptr2 - ptr1 + 1);
					currsum -= nums[ptr1];
					ptr1++;
				} else {

					ptr2++;
					if (ptr2 < n)
						currsum += nums[ptr2];
				}
			}
		}
		if (ptr2 == n)
		{
			while (ptr1 < n)
			{
				if (currsum >= target)
					ans = min(ans, ptr2 - ptr1);
				currsum -= nums[ptr1];
				ptr1++;
			}
		}
		return ans == INT_MAX ? 0 : ans;
	}
};