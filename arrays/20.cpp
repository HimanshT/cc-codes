// Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
// If such an arrangement is impossible, it must rearrange it to the lowest possible order (i.e., sorted in ascending order).
// The replacement must be in place and use only constant extra memory.

class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		int n = nums.size(); int idx = -1;
		for (int i = n - 1; i > 0; i--)
		{
			if (nums[i - 1] < nums[i])
			{
				idx = i;
				break;
			}
		}
		if (idx == -1)
		{
			sort(nums.begin(), nums.end());
			return;
		}
		int ans = INT_MAX, y = 0;
		for (int x = idx; x < n; x++) {
			if (nums[x] > nums[idx - 1] and nums[x] < ans)
			{
				ans = nums[x];
				y = x;
			}
		}
		swap(nums[idx - 1], nums[y]);
		sort(nums.begin() + idx, nums.end());
	}
};

//approach:
//just find the first decreasing point let's say {1,2,3,8,10,5};
//                                                ------ (8<10) so this is decreasing point,so we have to replace 8 with a number
//just greater than this,minimum number greater than current number from that point
//and after that sort from that point
