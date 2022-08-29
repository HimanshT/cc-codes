// Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
// If such an arrangement is impossible, it must rearrange it to the lowest possible order (i.e., sorted in ascending order).
// The replacement must be in place and use only constant extra memory.

class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		int n = nums.size();
		int i = n - 1;
		while (i >= 1)
		{
			if (nums[i - 1] < nums[i])
				break;
			i--;
		}
		if (i == 0)
		{
			sort(nums.begin(), nums.end());
			return;
		}
		int ans = INT_MAX;
		int idx = 0;
		for (int j = i; j < n; j++)
		{
			if (nums[j] > nums[i - 1] and nums[j] < ans)
			{
				ans = nums[j];
				idx = j;
			}
		}
		swap(nums[i - 1], nums[idx]);
		sort(nums.begin() + i, nums.end());
	}
};

//approach:
//just find the first decreasing point let's say {1,2,3,8,10,5};
//                                                ------ (8<10) so this is decreasing point,so we have to replace 8 with a number
//just greater than this
